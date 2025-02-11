# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g `pkg-config --cflags gtkmm-3.0`
#CXXFLAGS = -Wall -g `pkg-config --cflags gtk+-3.0`

# Linker flags
LDFLAGS = `pkg-config --libs gtkmm-3.0`

# Source files directory
SRC_DIR = src

# Object files directory
OBJ_DIR = obj

# Binary output directory
BIN_DIR = bin

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Binary output file
BIN_FILE = $(BIN_DIR)/image_viewer

# Default target
all: $(BIN_FILE)

# Rule to create the object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to create the binary
$(BIN_FILE): $(OBJ_FILES)
	$(CXX) $^ $(LDFLAGS) -o $@

# Rule to clean the project
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_FILE)

# Create necessary directories
directories:
	mkdir -p $(SRC_DIR) $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean directories

