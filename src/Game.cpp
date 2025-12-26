// ===== Game.cpp =====

#include "Game.hpp"
#include "Config.hpp"

#include <iostream>

Game::Game()
    : window(sf::VideoMode{{Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT}}, "Snake")
{
#ifdef DEBUG
  std::cout << "Modo DEBUG\n";
#endif

  window.setFramerateLimit(Config::FPS_LIMIT);
}

void Game::run()
{
  while (window.isOpen())
  {
    processEvents();
    update();
    render();
  }
}

void Game::processEvents()
{
  while (const std::optional<sf::Event> event = window.pollEvent())
  {
    if (event->is<sf::Event::Closed>())
      window.close();
  }
}

void Game::update() {}

void Game::render()
{
  window.clear();
  window.display();
}

void Game::reset() {}