#include "game.h"
#include <iostream>

Game::Game() {
    _window = nullptr;
    _renderer = nullptr;

    ScreenWidth = 1024;
    ScreenHeight = 800;
    _gamestate = GameState::PLAY;

    // Инициализация игрока
    _player = {ScreenWidth / 2 - 25, ScreenHeight / 2 - 25, 50, 50}; // Центр экрана, размер 50x50
    _playerSpeed = 5; // Скорость движения игрока
}

Game::~Game() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Game::run() {
    init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
    gameLoop();
}

void Game::init(const char* title, int x, int y, int w, int h, Uint32 flags) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return;
    }

    _window = SDL_CreateWindow(title, x, y, w, h, flags);
    if (!_window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (!_renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return;
    }
}

void Game::gameLoop() {
    while (_gamestate != GameState::EXIT) {
        handleEvents();
        update();
        draw();
    }
}

void Game::handleEvents() {
    SDL_Event evnt;
    while (SDL_PollEvent(&evnt)) {
        switch (evnt.type) {
            case SDL_QUIT:
                _gamestate = GameState::EXIT;
                break;

            case SDL_KEYDOWN:
                // Обработка нажатий клавиш
                switch (evnt.key.keysym.sym) {
                    case SDLK_w: _player.y -= _playerSpeed; break; // Вверх
                    case SDLK_s: _player.y += _playerSpeed; break; // Вниз
                    case SDLK_a: _player.x -= _playerSpeed; break; // Влево
                    case SDLK_d: _player.x += _playerSpeed; break; // Вправо
                }
                break;
        }
    }
}

void Game::update() {
    // Можно добавить обновление логики игры, если потребуется
}

void Game::draw() {
    // Очистка экрана
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); // Чёрный фон
    SDL_RenderClear(_renderer);

    // Рисуем игрока
    SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255); // Красный цвет
    SDL_RenderFillRect(_renderer, &_player);

    // Отображаем содержимое
    SDL_RenderPresent(_renderer);
}
