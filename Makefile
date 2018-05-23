export CC = gcc
export FLAGS = -w -pthread -std=c11
export PROJECT_DIR = ~/Programs/ChatinC
export SOURCE_DIR = $(PROJECT_DIR)/src
export BUILD_DIR = $(PROJECT_DIR)/build 
export INCLUDE_DIR = $(PROJECT_DIR)/src
export INCLUDE_FLAG = -I $(INCLUDE_DIR)
export COMPILE_COMMAND = $(CC) $(FLAGS) $(INCLUDE_FLAG)

.PHONY: all build clean

all: build

build:
	cd $(SOURCE_DIR) && make build
	mv src/*.o $(BUILD_DIR)
	find . -name *\.gch -delete

clean:
	find . -name *\.o -delete
	find . -name *\.gch -delete