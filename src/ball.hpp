#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>

class Ball{
public:
  Ball();
  void update();
  sf::Vector2f getSize();
  sf::Vector2f getPosition();
  void trunX();
  void trunY();

  sf::RectangleShape rect;
  int adx=0;
  int ady=0;
private:
};
