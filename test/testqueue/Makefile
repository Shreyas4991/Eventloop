REQUIRED_OBJECTS = \
		$(BUILD_DIR)/pointerutilities.o \
		$(BUILD_DIR)/queue.o


test:
	$(COMPILE_COMMAND) -c testqueue.c
	$(COMPILE_COMMAND) \
			-o testqueue testqueue.o \
			$(REQUIRED_OBJECTS)
	valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
        --verbose \
        --log-file=valgrind-out.txt \
		./testqueue

clean:
	find . -name testqueue -delete

.PHONY: test