// src/Snake.cpp

#include "Snake.h"
#include "Config.h"
#include "Utils.h"
#include <algorithm>

Snake::Snake(int startX, int startY) {
  reset(startX, startY);
}

void Snake::reset(int x, int y) {
  body.clear();
  for (int i = 0; i < INITIAL_SNAKE_LENGTH; ++i) {
    body.push_back({x - i, y});
  }
  dirX = 1; dirY = 0;
}

void Snake::setDir(int dx, int dy) {
  // evitar invertir direccion
  if (dx == -dirX && dy == -dirY) return;
  dirX = dx, dirY = dy;
}

void Snake::update(bool grow) {
  SDL_Point h = body.front();
  SDL_Point nh{ h.x + dirX, h.y + dirY };
  body.insert(body.begin(), nh);
  if (!grow) body.pop_back();
}

bool Snake::checkSelfCollision() const {
  SDL_Point h = head();
  for (size_t i = 1; i < body.size(); ++i) if (body[i].x == h.x && body[i].y == h.y) return true;
  return false;
}

SDL_Point Snake::head() const { return body.front(); }

const std::vector<SDL_Point>& Snake::getBody() const { return body; }

void Snake::render(SDL_Renderer* r, int cellSize) const {
  SDL_SetRenderDrawColor(r, 0, 200, 0, 255);
  for (auto& p : body) drawCell(r, p.x, p.y, cellSize);
}

size_t Snake::lenght() const { return body.size(); }
