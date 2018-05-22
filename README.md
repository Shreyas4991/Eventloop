# EventLoop

Ideally these apps are best written in higher level languages like python. That said, I wrote this app primarily to 
* get a hang of low level C programming after a long while.
* Get used to MakeFiles.
* Work around with ncurses as a precursor to other GUI applications.

## How this works
* You register events initially. Execute code sequentially and synchronously. Trigger events and have the code corresponding to them execute
* You are responsible for the handling of shared resources between event-handlers. So do use your own locks/mutexes/semaphores/monitors for any global/static variables used in event handlers
* This library does not make code run asynchronously. Event callbacks are executed on a different thread, (henceforth referred to as the eventloop thread). 
* When an event is triggered, it will wait for the current event loop to empty the event queue before executing the callback for the event you just triggered.
* The only way you can chain event callbacks is by triggering events in them.
* Callbacks cannot return anything. This is to stop you from shooting yourself in the foot.
* There is no asyncrhony involved.
* This project is very small, hence the bad Makefile format is not a big performance issue during the build.