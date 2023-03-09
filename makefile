TARGET := oefe

CXX := g++

BUILD_DIR := ./build
SRC_DIRS := ./src
INC_DIRS := ./include ./include/Math

LIBS := ''
LDFLAGS := -v

SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

$(info VAR="$(SRCS)")
$(info VAR="$(OBJS)")
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS := $(INC_FLAGS) -MMD -MP

CXXFLAGS := -g -W -Wall -Wextra -pedantic -O0

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) -L $(LDIR) $(LIBS) 

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)

MKDIR_P := mkdir -p
