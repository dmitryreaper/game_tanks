# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lSDL2 -Iinclude -lSDL2main -lSDL2 -lSDL2_image

# File paths
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRCS = $(SRC_DIR)/game.cpp $(SRC_DIR)/main.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = $(BIN_DIR)/game

# Targets
all: $(EXEC)

# Linking
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/game

.PHONY: all clean
