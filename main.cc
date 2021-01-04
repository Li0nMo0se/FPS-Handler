#include "fps_handler.hh"

#include <iostream>
#include <chrono>

void test_fps_handler(const unsigned int fps,
                      const unsigned int number_of_calls)
{
    // Create the fps handler
    FpsHandler fps_handler(fps);

    // Begin the chrono
    fps_handler.begin();

    for (unsigned int i = 0; i < number_of_calls; i++)
    {
        // Wait until the waiting time is reached
        fps_handler.wait();
        // The std::cout call may slow down the process for high fps
        // But the fps handler should will take care of this delay
        std::cout << "Call: " << (i + 1) << std::endl;
    }
}

/* Show usage of the fps handler */
int main()
{
    int fps = 60;
    int number_of_calls = 60;

    std::cout << "FPS? ";
    std::cin >> fps;

    if (fps <= 0)
    {
        std::cerr << "Error: the FPS must be a strictly positive value."
                  << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Number of calls? ";
    std::cin >> number_of_calls;

    if (number_of_calls < 0)
    {
        std::cerr << "Error: the number of calls must be positive."
                  << std::endl;
        return EXIT_FAILURE;
    }

    // Run the test
    auto start_test = std::chrono::high_resolution_clock::now();
    test_fps_handler(fps, number_of_calls);
    auto end_test = std::chrono::high_resolution_clock::now();

    // Display results
    auto nano_duration = std::chrono::duration_cast<std::chrono::nanoseconds>
        (end_test - start_test);
    std::cout << "Time elapsed (in nanoseconds): "
              << nano_duration.count()
              << "ns" << std::endl;

    std::cout << "Time elapsed (in seconds): "
              << nano_duration.count() / 1E9
              << "s" << std::endl;

    int actual_fps = static_cast<int>(static_cast<double>(number_of_calls) / nano_duration.count() * 1E9);
    std::cout << "Actual FPS: " << actual_fps << std::endl;

    return EXIT_SUCCESS;
}