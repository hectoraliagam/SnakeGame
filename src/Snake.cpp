// ===== Snake.cpp =====

#include "Snake.hpp"

Snake::Snake()
    : direction{1, 0}, growNext(false)
{
  segments.push_back({{10, 10}});
}

void Snake::move()
{
  if (segments.empty())
    return;

  sf::Vector2i newHeadPos = segments.front().position + direction;

  if (growNext)
  {
    segments.insert(segments.begin(), {newHeadPos});
    growNext = false;
  }
  else
  {
    for (int i = segments.size() - 1; i > 0; --i)
    {
      segments[i].position = segments[i - 1].position;
    }
    segments[0].position = newHeadPos;
  }
}

void Snake::grow() { growNext = true; }

bool Snake::checkCollision() const
{
  if (segments.empty())
    return false;

  const sf::Vector2i &head = segments.front().position;

  return head.x < 0 || head.y < 0 || head.x >= 30 || head.y >= 30;
}

bool Snake::checkSelfCollision() const
{
  if (segments.size() < 2)
    return false;

  const sf::Vector2i &head = segments.front().position;

  for (size_t i = 1; i < segments.size(); ++i)
  {
    if (segments[i].position == head)
      return true;
  }
  return false;
}

const std::vector<Segment> &Snake::getSegments() const { return segments; }

void Snake::setDirection(const sf::Vector2i &dir) { direction = dir; }

sf::Vector2i Snake::getDirection() const { return direction; }