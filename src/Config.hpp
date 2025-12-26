// ===== Config.hpp =====

#pragma once

namespace Config
{
  // ===== Window =====
  inline constexpr int WINDOW_WIDTH = 600;
  inline constexpr int WINDOW_HEIGHT = 600;
  inline constexpr int FPS_LIMIT = 60;

  // ===== Game =====
  inline constexpr int GRID_SIZE = 20;
  inline constexpr int GRID_WIDTH = 30;
  inline constexpr int GRID_HEIGHT = 30;

  // ===== Snake =====
  inline constexpr int START_X = 10;
  inline constexpr int START_Y = 10;
  inline constexpr float SNAKE_SPEED = 0.05f;
}