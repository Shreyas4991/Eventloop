# EventLoop

Ideally event-driven code is best written in languages like javascript or with libraries. The event loop is a single threaded model. That said, I wrote this stuff primarily to 
* Revisit low level C programming after a long time.
* Implement some fundamental concept in CS
* Get accustomed to MakeFiles again.


## How this works
* You register events initially. Execute code sequentially and synchronously. Trigger events and have the callback corresponding to them execute on a thread on which the eventloop runs.
*  test/testevent/sampleevmain is a good example of how it works so far.

* You are responsible for the handling of shared resources between event-handlers. So do use your own locks/mutexes/semaphores/monitors for any global/static variables used in event handlers

* The only way you can chain event callbacks is by triggering events in them.
* Callbacks cannot return anything. This is to stop you from shooting yourself in the foot. 

* This project is very small, hence the bad Makefile format i.e. using phony targets everywhere and therefore rebuilding everytime is not a big performance issue.

## Building it
* `make build`: Produces the necessary object files in the `build/` directory. You will need to write your source and link it will all these objects to get the executable. In the compile command, make sure you use `-I src/` to add `src/` to the list of directories in which your compiler will search for header files
* `make clean` : Cleans the project of all object and executable files.
* `make test`: Runs the tests currently specified in the test directory


## How to use it
It's a bit complicated at the moment since this is still a work-in-progress with more serious [issues](#issues-to-fix) to be fixed. Basically, you need to 
* include the header `eventio.h` which is in the src directory and makes other includes.
* define a set of events by integers. You can use macros or an enum type. The events are stored in a dynamic array.
* Your source needs to contain two functions whose  signatures are given below:
    *  `int evmain(int argc,char **argv)`:
        * This is the equivalent of main here.
        * The arguments `argc` and `argv` from the actual main function are directly passed to this function.   
    * `event_list_t* register_events()`
        * This is where you register your initial set of event handlers. Watching I/O actions and calling trigger on the corresponding events with a pointer to an object containing your arguments is your job as of now
* To compile and produce the executable you need to link all the objects in build. The flag `-I src/` is essential in the compile command.

Your file with all the objects in the build directory
The file `test/testevent/sampleevmain` is a good example of working with this.

## Issues to fix
### Serious:
* Memory leaks in the queue data structure. Clearly I must have committed a blunder somewhere. Double freeing should not be an issue thanks to `safe_free` in src/pointerutilities.h. 
* Being able to add events on the fly in evmain. requires the addition of a function to expand the allocated space for variables of type event_list_t* using realloc.
### Others:
* Disappearing arguments: For now arguments supplied to callbacks disappear into a blackhole (aka get freed). This means passing values by reference is pointless. The idea was to not let the user worry about freeing pointer arguments. Clearly that isn't much help if the user wants to keep them.
*  Return values: Again much needed. For now callbacks have to have a return type `void`