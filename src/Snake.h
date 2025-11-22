#pragma once
#include <vector>
#include <SDL.h>

class Snake {
public:
  Snake(int gridSize);
  void update();
  void render(SDL_Renderer* renderer);

private:
  std::vector<SDL_Point> body;
  int dirX = 1, dirY = 0;
  int gridSize;
};
