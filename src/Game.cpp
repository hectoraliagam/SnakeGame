// ===== Game.cpp =====

#include "Game.hpp"
#include "Config.hpp"
#include <iostream>

Game::Game()
    : window(sf::VideoMode(sf::Vector2u(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT)), "Snake"),
      segmentShape(sf::Vector2f(float(Config::GRID_SIZE - 2), float(Config::GRID_SIZE - 2)))
{
#ifdef DEBUG
  std::cout << "Modo DEBUG\n";
#endif

  window.setFramerateLimit(Config::FPS_LIMIT);

  segmentShape.setFillColor(sf::Color::Green);
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
  while (auto eventOpt = window.pollEvent())
  {
    const sf::Event &event = *eventOpt;

    if (event.is<sf::Event::Closed>())
      window.close();

    if (event.is<sf::Event::KeyPressed>())
    {
      const auto *keyEvent = event.getIf<sf::Event::KeyPressed>();

      if (keyEvent)
      {
        sf::Vector2i dir = snake.getDirection();

        switch (keyEvent->code)
        {
        case sf::Keyboard::Key::Up:
          if (dir.y == 0)
            dir = {0, -1};
          break;
        case sf::Keyboard::Key::Down:
          if (dir.y == 0)
            dir = {0, 1};
          break;
        case sf::Keyboard::Key::Left:
          if (dir.x == 0)
            dir = {-1, 0};
          break;
        case sf::Keyboard::Key::Right:
          if (dir.x == 0)
            dir = {1, 0};
          break;
        default:
          break;
        }

        snake.setDirection(dir);
      }
    }
  }
}

void Game::update()
{
  snake.move();

  if (snake.checkCollision() || snake.checkSelfCollision())
  {
    reset();
  }
}

void Game::render()
{
  window.clear();

  for (const auto &seg : snake.getSegments())
  {
    segmentShape.setPosition(
        sf::Vector2f(
            float(seg.position.x * Config::GRID_SIZE),
            float(seg.position.y * Config::GRID_SIZE)));
    window.draw(segmentShape);
  }

  window.display();
}

void Game::reset()
{
  snake = Snake();
}