#include "Snake.h"

Snake::Snake(int g) : gridSize(g) {
  body.push_back({10, 10});
}

void Snake::update() {
  SDL_Point head = body.front();
  head.x += dirX;
  head.y += dirY;
  body.insert(body.begin(), head);
  body.pop_back();
}

void Snake::render(SDL_Renderer* r) {
  SDL_SetRenderDrawColor(r, 0, 255, 0, 255);

  for (auto& p : body) {
    SDL_Rect rect = { p.x * gridSize, p.y * gridSize, gridSize, gridSize };
    SDL_RenderFillRect(r, &rect);
  }
}
