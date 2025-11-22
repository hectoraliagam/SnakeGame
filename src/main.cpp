// src/main.cpp

#include <SDL.h>
#include "Game.h"

int main(int argc, char** argv) {
  Game game("Snake", 640, 480);

  if (!game.init()) return 1;

  while (game.isRunning()) {
    game.handleEvents();
    game.update();
    game.render();
    SDL_Delay(1);
  }

  game.clean();
  return 0;
}
