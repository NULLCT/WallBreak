#include "wall.hpp"

Wall::Wall(){
  rect.setSize(sf::Vector2f(100,32));
  rect.setFillColor(sf::Color::White);
  rect.setPosition(0,0);
}

void Wall::setPosition(int x,int y){
  rect.setPosition(sf::Vector2f(x,y));
}

void Wall::setEnable(bool tr){
  enable=tr;
}

bool Wall::isEnable(){
  return enable;
}

sf::Vector2f Wall::getPosition(){
  return rect.getPosition();
}

sf::Vector2f Wall::getSize(){
  return rect.getSize();
}
