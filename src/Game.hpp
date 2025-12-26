// ===== Game.hpp =====

#pragma once

#include <SFML/Graphics.hpp>

class Game
{
public:
  Game();
  void run();

private:
  void processEvents();
  void update();
  void render();
  void reset();

private:
  sf::RenderWindow window;
};