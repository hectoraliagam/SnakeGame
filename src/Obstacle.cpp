#include "Obstacle.h"
#include "Utils.h"

ObstacleMap::ObstacleMap(int w, int h) : width(w), height(h) {}

void ObstacleMap::generate(int count) {
  blocks.clear();
  for (int i = 0; i < count; ++i) {
    int x = RNG::randRange(1, width - 2);
    int y = RNG::randRange(1, height - 2);
    blocks.push_back({x,y});
  }
}

bool ObstacleMap::isBlocked(int x, int y) const {
  for (auto &p : blocks) if (p.x == x && p.y == y) return true;
  return false;
}

void ObstacleMap::render(SDL_Renderer* r, int cellSize) const {
  SDL_SetRenderDrawColor(r, 150, 75, 0, 255);
  for (auto &p : blocks) drawCell(r, p.x, p.y, cellSize);
}

void ObstacleMap::clear() { blocks.clear(); }
