#pragma once
#include <SDL.h>
#include <vector>

enum class PowerType { None, SpeedUp, Slow, Grow, Shrink, Multiplier };

struct FoodItem {
  SDL_Point pos;
  PowerType power = PowerType::None;
  int life = 0; // frames
  int value = 1; // score
};

class FoodManager {
public:
  FoodManager(int w, int h);
  void spawn(const std::vector<SDL_Point>& forbidden);
  void update();
  bool eatAt(int x, int y, FoodItem& out);
  void render(SDL_Renderer* r, int cellSize) const;
private:
  int width, height;
  std::vector<FoodItem> items;
  void spawnOne(const std::vector<SDL_Point>& forbidden);
};
