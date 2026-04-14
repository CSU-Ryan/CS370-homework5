# Makefile kindly modified from https://gist.github.com/zobayer1/7265c698d1b024bb7723bc624aeedeb3

# Pre-compiler and Compiler flags
CXX_FLAGS := -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -Wctor-dtor-privacy -Wold-style-cast -D_GLIBCXX_DEBUG -fno-diagnostics-show-option
PRE_FLAGS := -MMD -MP

# Project directory structure
BIN := .
SRC := src
LIB := lib
INC := include
MAINFILE := $(SRC)/Scheduler.cpp

# Build directories and output
TARGET := $(BIN)/Scheduler
BUILD := build

# Library search directories and flags
EXT_LIB :=
LDFLAGS :=
LDPATHS := $(addprefix -L,$(LIB) $(EXT_LIB))

# Include directories
INC_DIRS := $(INC) $(shell find $(SRC) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Construct build output and dependency filenames
SRCS := $(shell find $(SRC) -name *.cpp)
OBJS := $(subst $(SRC)/,$(BUILD)/,$(addsuffix .o,$(basename $(SRCS))))
DEPS := $(OBJS:.o=.d)

# Run task
run: build
	./$(TARGET) $(ARGS)

# Build task
build: clean all

# Main task
all: $(TARGET)

# Task producing target from built files
$(TARGET): $(OBJS)
	mkdir -p $(dir $@)
	$(CXX) $(OBJS) -o $@ $(LDPATHS) $(LDFLAGS)

# Compile all cpp files
$(BUILD)/%.o: $(SRC)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) $(PRE_FLAGS) $(INC_FLAGS) -c -o $@ $< $(LDPATHS) $(LDFLAGS)

# Clean task
.PHONY: clean
clean:
	rm -rf build
	rm -rf $(TARGET)

# Include all dependencies
-include $(DEPS)
