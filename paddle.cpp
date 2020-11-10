#include "paddle.hpp"

Paddle::Paddle(){
  rect.setSize(sf::Vector2f(125,16));
  rect.setPosition(sf::Vector2f(1280/2-100,650));
  rect.setFillColor(sf::Color::White);
}

void Paddle::moveLeft(){
  if(0 < rect.getPosition().x-movespeed)
    rect.setPosition(rect.getPosition()+sf::Vector2f(-movespeed,0));
}

void Paddle::moveRight(){
  if(rect.getPosition().x+rect.getSize().x+movespeed < 1280)
    rect.setPosition(rect.getPosition()+sf::Vector2f(movespeed,0));
}
