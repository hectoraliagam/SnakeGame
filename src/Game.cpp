// src/Game.cpp

#include "Game.h"
#include "Utils.h"

Game::Game(const char* title, int w, int h)
  : width(w), height(h) {}

bool Game::init() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) return false;

  window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  snake = new Snake(DEFAULT_GRID_W / 2, DEFAULT_GRID_H / 2);
  food = new FoodManager(DEFAULT_GRID_W, DEFAULT_GRID_H);
  obstacles = new ObstacleMap(DEFAULT_GRID_W, DEFAULT_GRID_H);
  obstacles->generate(OBSTACLE_COUNT);

  highScore = loadHighScore();
  food->spawn(snake->getBody());

  running = true;
  return true;
}

void Game::handleEvents() {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT)
      running = false;
    if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:    snake->setDir( 0,-1); break;
        case SDLK_DOWN:  snake->setDir( 0, 1); break;
        case SDLK_LEFT:  snake->setDir(-1, 0); break;
        case SDLK_RIGHT: snake->setDir( 1, 0); break;

        case SDLK_MINUS: if (speed > MIN_SPEED) speed--; break;
        case SDLK_EQUALS: if (speed < MAX_SPEED) speed++; break;
      }
    }
  }
}
