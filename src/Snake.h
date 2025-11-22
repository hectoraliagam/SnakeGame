#pragma once
#include <vector>
#include <SDL.h>

class Snake {
public:
  Snake(int startX, int startY);
  void reset(int x, int y);
  void setDir(int dx, int dy);
  void update(bool grow);
  bool checkSelfCollision() const;
  SDL_Point head() const;
  const std::vector<SDL_Point>& getBody() const;
  void render(SDL_Renderer* r, int cellSize) const;
  size_t lenght() const;
private:
  std::vector<SDL_Point> body;
  int dirX = 1, dirY = 0;
};
