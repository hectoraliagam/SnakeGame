#pragma once
#include <SDL.h>

class Game {
public:
  Game(const char* title, int w, int h);
  bool init();
  void handleEvents();
  void update();
  void render();
  void clean();
  bool isRunning() const { return running; }

private:
  bool running = false;
  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;
  int width, height;
};

void Game::update() {
  // lógica del juego (movimiento snake, colisiones, etc)
}

void Game::render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  // DIBUJAR PIXEL -> (rectángulo cuadrado)
  SDL_Rect pixel = { 100, 100, 20, 20 };
  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  SDL_RenderFillRect(renderer, &pixel);

  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
