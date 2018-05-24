# EventLoop

Ideally event-driven and code is best written in higher level languages like javascript with better. That said, I wrote this app primarily to 
* Get a hang of low level C programming after a long while.
* Get accustomed to MakeFiles again.
* Try out a concept people usually use libraries to implement.


## How this works
* You register events initially. Execute code sequentially and synchronously. Trigger events and have the code corresponding to them execute. test/testevent/sampleevmain is a good example of how it works so far

* You are responsible for the handling of shared resources between event-handlers. So do use your own locks/mutexes/semaphores/monitors for any global/static variables used in event handlers

* The only way you can chain event callbacks is by triggering events in them.
* Callbacks cannot return anything. This is to stop you from shooting yourself in the foot. 

* This project is very small, hence the bad Makefile format i.e. using phony targets everywhere and therefore rebuilding everytime is not a big performance issue.

## Issues to fix
### Serious:
* Memory leaks in the queue data structure. Clearly I must have committed a blunder somewhere. Double freeing should not be an issue thanks to `safe_free` in src/pointerutilities.h. 
* Being able to add events on the fly in evmain.
### Others:
* Disappearing arguments: For now arguments supplied to callbacks disappear into a blackhole (aka get freed). This means passing values by reference is pointless. The idea was to not let the user worry about freeing pointer arguments. Clearly that isn't much help if the user wants to keep them.
*  Return values: Again much needed. For now callbacks have to have a return type `void`
*  