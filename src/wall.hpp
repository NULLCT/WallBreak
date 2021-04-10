#pragma once
#include <SFML/Graphics.hpp>

class Wall{
public:
  Wall();
  void setPosition(int x,int y);
  void setEnable(bool tr);
  bool isEnable();
  sf::Vector2f getPosition();
  sf::Vector2f getSize();

  sf::RectangleShape rect;
private:
  bool enable=true;
};
