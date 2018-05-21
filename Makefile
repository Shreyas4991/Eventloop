export CC = gcc
export FLAGS = --Wall --Wextra --lpthread
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


clean:
	find . -name *\.o -delete
	find . -name *\.gch -delete