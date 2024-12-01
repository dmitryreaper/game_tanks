#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

enum class GameState {
    PLAY,
    EXIT
};

class Game {
public:
    Game();
    ~Game();

    void run();

private:
    void init(const char* title, int x, int y, int w, int h, Uint32 flags);
    void gameLoop();
    void handleEvents();
    void update();
    void draw();

    SDL_Window* _window;
    SDL_Renderer* _renderer;

    int ScreenWidth;
    int ScreenHeight;
    GameState _gamestate;

    SDL_Rect _player; // Прямоугольник для игрока
    int _playerSpeed; // Скорость игрока
};

#endif // GAME_H
