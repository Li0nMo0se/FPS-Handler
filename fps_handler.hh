#pragma once

class FpsHandler
{
public:
    FpsHandler(unsigned int fps);

    /*! \brief Begin the process of fps handling. */
    void begin();

    /*! \brief Wait the correct time to simulate fps.
    **
    ** Between each frame enqueue, the waiting duration should be
    ** enqueue_interval_
    ** However the real waiting duration might be longer than the
    ** theoretical one (due to descheduling)
    ** To cope with this issue, we compute the wasted time in order to take
    ** it into account for the next enqueue
    ** By doing so, the correct enqueuing time is computed, not doing so
    ** would create a lag
    */
    void wait();

private:
    /*! \brief Theoretical time between 2 enqueues/waits */
    std::chrono::duration<double> enqueue_interval_;

    /*! \brief Begin time point of the wait */
    std::chrono::steady_clock::time_point begin_time_;

    /*! \brief Time wasted in last wait (if waiting was too long) */
    std::chrono::duration<double> wasted_time_{0};
};