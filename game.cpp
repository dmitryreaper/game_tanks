#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>



Game::Game() {
	_window = nullptr;
	_renderer = nullptr;

	ScreenWidth = 1024;
	ScreenHeight = 800;
	_gamestate = GameState::PLAY;
	
};
Game::~Game() {};

void Game::run() {

	init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
	gameLoop();
	
}

void Game::init(const char* title, int x, int y, int w, int h, Uint32 flags) {
	
	SDL_Init(SDL_INIT_EVERYTHING);
	_window = SDL_CreateWindow(title, x , y, w, h, flags);
	_renderer = SDL_CreateRenderer(_window, -1, 0);
	
}

void Game::gameLoop() {

	while(_gamestate != GameState::EXIT) {
		handleEvents();	
	}
	
}

void Game::handleEvents() {
	
	SDL_Event evnt;
	SDL_PollEvent(&evnt);

	switch (evnt.type) {
	case SDL_QUIT:
		_gamestate = GameState::EXIT;
	}
}
