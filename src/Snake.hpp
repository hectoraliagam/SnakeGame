// ===== Snake.hpp =====

#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

struct Segment
{
  sf::Vector2i position;
};

class Snake
{
public:
  Snake();

  void move();
  void grow();
  bool checkCollision() const;
  bool checkSelfCollision() const;

  const std::vector<Segment> &getSegments() const;

  void setDirection(const sf::Vector2i &dir);
  sf::Vector2i getDirection() const;

private:
  std::vector<Segment> segments;
  sf::Vector2i direction;
  bool growNext;
};