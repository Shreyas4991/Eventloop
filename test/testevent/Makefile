REQUIRED_OBJECTS = \
	$(BUILD_DIR)/event.o \
	$(BUILD_DIR)/pointerutilities.o \
	$(BUILD_DIR)/queue.o \
	$(BUILD_DIR)/main.o

test:
	$(COMPILE_COMMAND) -c sampleevmain.c
	$(COMPILE_COMMAND) \
		sampleevmain.o \
		$(REQUIRED_OBJECTS) \
		-o sampleevmain
	valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
        --verbose \
        --log-file=valgrind-out.txt \
		./sampleevmain

clean: 
	find . -name sampleevmain -delete

.PHONY: test clean