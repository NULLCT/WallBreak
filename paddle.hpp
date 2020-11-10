#pragma once
#include <SFML/Graphics.hpp>
#include "wall.hpp"

class Paddle : public Wall{
public:
  Paddle();
  void moveRight();
  void moveLeft();
private:
  const int movespeed=10;
};
