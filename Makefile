# Variables
CXX := clang++
LD := ld.lld

CXXFLAGS := -Wall \
            -Wextra \
            -O2 \
            -std=c++17 \
            -I src/ \

LDFLAGS := -L/usr/local/lib \
           -L/usr/lib

SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin
TARGET := $(BIN_DIR)/volt

# Find all .cpp files in src/ and set corresponding object files in build/
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Default target
all: $(TARGET)

# Linking the final executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	@$(CXX) \
		$(OBJS) \
		$(LDFLAGS) \
		-o $@ \
		$(LDLIBS)

# Compiling each .cpp to a .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) \
		$(CXXFLAGS) \
		-c $< \
		-o $@

# Ensure build/ and bin/ directories exist
$(OBJ_DIR) $(BIN_DIR):
	@mkdir -p $@

# Run the executable
run: $(TARGET)
	@./$(TARGET)

# Clean up
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean run
