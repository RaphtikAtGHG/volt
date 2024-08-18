CXX := clang++
LD := ld.lld

CXXFLAGS := -Wall \
			-Wextra \
			-O2 \
			-std=c++20 \
			-I src/ \

LDFLAGS := -L/usr/local/lib \
		-L/usr/lib

SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin
TARGET := $(BIN_DIR)/volt

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	@$(CXX) \
		$(OBJS) \
		$(LDFLAGS) \
		-o $@ \
		$(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) \
		$(CXXFLAGS) \
		-c $< \
		-o $@

$(OBJ_DIR) $(BIN_DIR):
	@mkdir -p $@

run: $(TARGET)
	@./$(TARGET)

clean:
	@clear
	@rm -rf $(OBJ_DIR) $(BIN_DIR)

reset: clean all

.PHONY: all clean run
