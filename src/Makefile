queue: pointerutilities
	$(COMPILE_COMMAND) -c queue.h queue.c

pointerutilities:
	$(COMPILE_COMMAND) -c pointerutilities.h pointerutilities.c

event: queue vector pointerutilities
	$(COMPILE_COMMAND) -c event.h event.c


build: event

.PHONY: build pointerutilities queue vector