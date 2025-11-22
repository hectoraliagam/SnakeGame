// src/Game.h

#include "Snake.h"
#include "Food.h"
#include "Obstacle.h"
#include "Config.h"
#include "Utils.h"

class Game {
public:
  Game(const char* title, int w, int h);
  bool init();
  void handleEvents();
  void update();
  void render();
  void clean();
  bool isRunning() const { return running; }

private:
  bool running = false;
  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;
  int width, height;
  Snake* snake = nullptr;
  FoodManager* food = nullptr;
  ObstacleMap* obstacles = nullptr;
  bool growFlag = false;
  int score = 0;
  int highScore = 0;
  int speed = INITIAL_SPEED; // velocidad en updates por segundo
  int frameCounter = 0;
};

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
