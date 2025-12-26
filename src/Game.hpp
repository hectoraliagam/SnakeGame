// ===== Game.hpp =====

#pragma once

#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Config.hpp"

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
  Snake snake;
  sf::RectangleShape segmentShape;
  sf::Clock clock;
  sf::Time elapsedTime;
};