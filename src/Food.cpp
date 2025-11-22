#include "Food.h"
#include "Utils.h"
#include "Config.h"
#include <algorithm>

FoodManager::FoodManager(int w, int h): width(w), height(h) {}

void FoodManager::spawn(const std::vector<SDL_Point>& forbidden) {
  // ensure at least 1 item
  if (items.empty()) spawnOne(forbidden);
}

void FoodManager::spawnOne(const std::vector<SDL_Point>& forbidden) {
  FoodItem f;
  int tries = 0;
  do {
    f.pos.x = RNG::randRange(0, width - 1);
    f.pos.y = RNG::randRange(0, height - 1);
    ++tries;
  } while ((std::find_if(forbidden.begin(), forbidden.end(), [&](const SDL_Point &p){return p.x==f.pos.x && p.y==f.pos.y;}) != forbidden.end()) && tries < 200);

  // random power-up
  int r = RNG::randRange(1, 100);
  if (r <= 10) { f.power = PowerType::SpeedUp; f.value = 3; }
  else if (r <= 18) { f.power = PowerType::Slow; f.value = 1; }
  else if (r <= 40) { f.power = PowerType::Grow; f.value = 2; }
  else if (r <= 45) { f.power = PowerType::Shrink;  f.value = -1; }
  else if (r <= 50) { f.power = PowerType::Multiplier; f.value = 5; }
  else { f.power = PowerType::None; f.value = 1; }
  f.life = POWERUP_LIFETIME;
  items.push_back(f);
}

void FoodManager::update() {
  for (auto &f : items) {
    if (f.power != PowerType::None) {
      f.life -= 1;
    }
  }
  items.erase(std::remove_if(items.begin(), items.end(), [](const FoodItem &f){ return f.life <= 0; }), items.end());
  if (items.empty()) spawnOne({});
}

bool FoodManager::eatAt(int x, int y, FoodItem& out) {
  for (size_t i = 0; i < items.size(); ++i) {
    if (items[i].pos.x == x && items[i].pos.y == y) {
      out = items[i];
      items.erase(items.begin() + i);
      return true;
    }
  }
  return false;
}

void FoodManager::render(SDL_Renderer* r, int cellSize) const {
  for (auto &f : items) {
    switch (f.power) {
      case PowerType::SpeedUp: SDL_SetRenderDrawColor(r, 255, 0, 0, 255); break;
      case PowerType::Slow: SDL_SetRenderDrawColor(r, 0, 0, 255, 255); break;
      case PowerType::Grow: SDL_SetRenderDrawColor(r, 0, 255, 0, 255); break;
      case PowerType::Shrink: SDL_SetRenderDrawColor(r, 255, 165, 0, 255); break;
      case PowerType::Multiplier: SDL_SetRenderDrawColor(r, 255, 255, 0, 255); break;
      default: SDL_SetRenderDrawColor(r, 200, 200, 200, 255); break;
    }
    drawCell(r, f.pos.x, f.pos.y, cellSize);
  }
}
