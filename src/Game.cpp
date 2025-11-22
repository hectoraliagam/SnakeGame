#include "Game.h"

Game::Game(const char* title, int w, int h)
  : width(w), height(h) {}

bool Game::init() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) return false;

  window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  running = true;
  return true;
}

void Game::handleEvents() {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT)
      running = false;
  }
}
