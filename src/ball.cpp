#include "ball.hpp"

Ball::Ball(){
  srand(time(0));
  adx=rand()%20-10;
  ady=-rand()%10;
  rect.setSize(sf::Vector2f(20,20));
  rect.setFillColor(sf::Color::White);
  rect.setPosition(1280/2-10,600);
}

void Ball::update(){
  rect.setPosition(rect.getPosition()+sf::Vector2f(adx,ady));
  if(rect.getPosition().x < 0 or 1280 < rect.getPosition().x+rect.getSize().x){
    trunX();
    rect.setPosition(rect.getPosition()+sf::Vector2f(adx,ady));
  }
  if(rect.getPosition().y < 0 or 720  < rect.getPosition().y+rect.getSize().y){
    trunY();
    rect.setPosition(rect.getPosition()+sf::Vector2f(adx,ady));
  }
}

void Ball::trunX(){
  adx=-adx;
}
void Ball::trunY(){
  ady=-ady;
}

sf::Vector2f Ball::getSize(){
  return rect.getSize();
}
sf::Vector2f Ball::getPosition(){
  return rect.getPosition();
}
