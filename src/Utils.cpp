#include "Utils.h"
#include <random>
#include <fstream>

int RNG::randRange(int a, int b) {
  static std::mt19937 rng(std::random_device{}());
  std::uniform_int_distribution<int> dist(a, b);
  return dist(rng);
}

void drawCell(SDL_Renderer* r, int gx, int gy, int cellSize) {
  SDL_Rect rect{ gx * cellSize, gy * cellSize, cellSize, cellSize };
  SDL_RenderFillRect(r, &rect);
}

void saveScore(int score) {
  std::ofstream ofs("score.txt", std::ios::app);
  if (!ofs) return;
  ofs << score << "\n";
}

int loadHighScore() {
  std::ifstream ifs("score.txt");
  int best = 0; int s;
  while (ifs >> s) if (s > best) best = s;
  return best;
}

std::string toString(int v) {
  return std::to_string(v);
}
