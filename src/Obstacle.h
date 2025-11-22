// src/Obstacle.h

#pragma once
#include <vector>
#include <SDL.h>

class ObstacleMap {
public:
  ObstacleMap(int w, int h);
  void generate(int count);
  bool isBlocked(int x, int y) const;
  void render(SDL_Renderer* r, int cellSize) const;
  void clear();
private:
  int width, height;
  std::vector<SDL_Point> blocks;
};
