// src/Config.h

#pragma once

// GRID
inline constexpr int DEFAULT_GRID_W = 32; // columnas
inline constexpr int DEFAULT_GRID_H = 24; // filas
inline constexpr int DEFAULT_CELL = 20;   // tamaño en pixeles

// WINDOW
inline constexpr int DEFAULT_WINDOW_W = DEFAULT_GRID_W * DEFAULT_CELL;
inline constexpr int DEFAULT_WINDOW_H = DEFAULT_GRID_H * DEFAULT_CELL;

// GAME
inline constexpr int INITIAL_SNAKE_LENGTH = 4;
inline constexpr int INITIAL_SPEED = 8; // updates por segundo
inline constexpr int MIN_SPEED = 2;
inline constexpr int MAX_SPEED = 30;

// OBSTACLES
inline constexpr int OBSTACLE_COUNT = 40;

// POWERUPS
inline constexpr int POWERUP_LIFETIME = 600; // frames de juego (aprox)
