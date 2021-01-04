# FPS-Handler

The FPS-Handler is able to *simulate* fps. It takes care of the potential lag between each process of frames and can wait according to this delay.

## Usage

1. Create a FPS-Handler object
```cpp
FpsHandler(unsigned int fps)
```
2. Call `Begin` to start the wacth of the handler
```cpp
begin()
```

3. Call `Wait`to wait until the next action that can be processed according to the given fps
```cpp
wait()
```

## Example

An example of usage and a proof of efficiency can be found in the file `main.cc`
You can build and execute it by following the below instructions:
```shell
mkdir build
cd build
cmake ..
make
./example
```

Then, the fps and number of calls must be given (as unsigned int).
For example:
```shell
FPS? 1000
Number of Calls? 1000
```
which will produce:
```shell
Call 1
Call 2
...
Call 1000
Time elapsed (in nanoseconds): 999940742ns
Time elapsed (in seconds): 0.999941s
Actual FPS: 1000
```
