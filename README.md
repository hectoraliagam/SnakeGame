# SnakeGame (C++ / SDL2)

Instrucciones rápidas:

1. Coloca SDL2 dev (include, lib, bin) dentro de `libs/SDL2`.
2. `mkdir build && cd build`
3. `cmake -G "MinGW Makefiles" ..`
4. `mingw32-make`
5. Ejecuta el binario en `build/bin/Snake.exe` (o desde VSCode launch config).

Controles:
- Flechas: mover snake
- P: pause
- W/S: aumentar/disminuir velocidad
- C: toggle choques con paredes
- R: reiniciar partida
- G: generar nuevo mapa de obstáculos
- H: mostrar/ocultar HUD

Los puntajes se guardan en `score.txt`.
