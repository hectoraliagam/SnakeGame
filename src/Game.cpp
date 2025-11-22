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

void Game::update() {
  frameCounter++;

  if (frameCounter < (60 / speed)) return; // controla velocidad
  frameCounter = 0;

  food->update();

  Snake& s = *snake;
  SDL_Point h = s.head();

  // Comer comida / power-up
  FoodItem item;
  if (food->eatAt(h.x, h.y, item)) {
    score += item.value;

    if (item.power == PowerType::Grow)
      growFlag = true;
    if (item.power == PowerType::Shrink && s.lenght() > 4)
      growFlag = false;
    if (item.power == PowerType::SpeedUp && speed < MAX_SPEED)
      speed += item.value;
    if (item.power == PowerType::Slow && speed > MIN_SPEED)
      speed -= item.value;

    food->spawn(s.getBody());
  }

  // mover snake
  s.update(growFlag);
  growFlag = false;

  // colisión consigo mismo
  if (s.checkSelfCollision()) {
    saveScore(score);
    score = 0;
    s.reset(DEFAULT_GRID_W/2, DEFAULT_GRID_H/2);
  }

  // colisión con muro
  SDL_Point nh = s.head();
  if (nh.x < 0 || nh.x >= DEFAULT_GRID_W || nh.y < 0 || nh.y >= DEFAULT_GRID_H) {
    saveScore(score);
    score = 0;
    s.reset(DEFAULT_GRID_W/2, DEFAULT_GRID_H/2);
  }

  // colisión con obstáculo
  if (obstacles->isBlocked(nh.x, nh.y)) {
    saveScore(score);
    score = 0;
    s.reset(DEFAULT_GRID_W/2, DEFAULT_GRID_H/2);
  }
}

void Game::render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  obstacles->render(renderer, DEFAULT_CELL);
  food->render(renderer, DEFAULT_CELL);
  snake->render(renderer, DEFAULT_CELL);

  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
