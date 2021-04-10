#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <string>
#include "wall.hpp"
#include "ball.hpp"
#include "paddle.hpp"

using namespace std;

int main(const int argc, char const *argv[]) {
  sf::RenderWindow window(sf::VideoMode(1280, 720), "WallBreak");
  window.setFramerateLimit(60);
  vector<vector<Wall>> walls(3,vector<Wall>(7));
  Ball ball;
  Paddle paddle;
  bool lefttr=false;
  bool righttr=false;

  if(1 < argc and string(argv[1]).substr(0,10) == "-pointress"){
    cout<<"enable pointress"<<endl;
    ball.ady = 0;
  }

  for(int y=0;y<walls.size();y++){
    for(int x=0;x<walls[0].size();x++){
      walls[y][x].setPosition(32+x*180,25+y*72);
    }
  }

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Left){
          lefttr=true;
        }
        if(event.key.code == sf::Keyboard::Right){
          righttr=true;
        }
      }
      if(event.type == sf::Event::KeyReleased){
        if(event.key.code == sf::Keyboard::Left){
          lefttr=false;
        }
        if(event.key.code == sf::Keyboard::Right){
          righttr=false;
        }
      }
    }

    if(lefttr)
      paddle.moveLeft();
    if(righttr)
      paddle.moveRight();

    vector<sf::Vector2f> poses = {
      ball.getPosition(),
      ball.getPosition()+sf::Vector2f(ball.getSize().x,0),
      ball.getPosition()+sf::Vector2f(0,ball.getSize().y),
      ball.getPosition()+ball.getSize()
    };
    for(auto &pos:poses)
      pos+=sf::Vector2f(ball.adx,ball.ady);

    for(auto &i:walls) for(auto &wall:i){
      for(auto &pos:poses){
        if(wall.isEnable() and wall.getPosition().x < pos.x and pos.x < wall.getPosition().x+wall.getSize().x and
           wall.getPosition().y < pos.y and pos.y < wall.getPosition().y+wall.getSize().y){
           wall.setEnable(false);

           if(pos.y-ball.ady<wall.getPosition().y or wall.getPosition().y < pos.y-ball.ady)
             ball.trunY();
           else
             ball.trunX();
        }
      }
    }

    if(paddle.getPosition().x <= ball.getPosition().x and ball.getPosition().x+ball.getSize().x <= paddle.getPosition().x+paddle.getSize().x and
        paddle.getPosition().y <= ball.getPosition().y and ball.getPosition().y+ball.getSize().y <= paddle.getPosition().y+paddle.getSize().y){
      ball.trunY();
    }

    ball.update();

    window.clear();
    for(auto &i:walls) for(auto &wall:i){
      if(wall.isEnable())
        window.draw(wall.rect);
    }
    window.draw(ball.rect);
    window.draw(paddle.rect);
    window.display();
  }

  return 0;
}
