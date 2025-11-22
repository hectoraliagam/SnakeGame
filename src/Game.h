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
