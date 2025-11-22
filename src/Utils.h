// src/Utils.h

#pragma once
#include <string>
#include <vector>
#include <SDL.h>

struct RNG {
  static int randRange(int a, int b);
};

// dibujar rectángulo en grid units
void drawCell(SDL_Renderer* r, int gx, int gy, int cellSize);

// guardar puntaje
void saveScore(int score);
int loadHighScore();

std::string toString(int v);
