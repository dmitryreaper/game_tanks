# Компилятор и флаги
CXX = c++
CXXFLAGS = -std=c++17 -Iinclude `sdl2-config --cflags`

# Линкинг
LDFLAGS = `sdl2-config --libs` -lSDL2_image

# Исходные файлы
SRC = main.cpp game.cpp
OBJ = main.o game.o

# Директория для исполняемого файла
BIN_DIR = bin
BIN = $(BIN_DIR)/game

# Цели
all: $(BIN)

$(BIN): $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CXX) $(OBJ) -o $(BIN) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BIN_DIR)

.PHONY: all clean
