#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <string.h>
#include <algorithm>
#include "../Header/DrawGame.h"
#include "../Header/DrawMenu.h"
#include "../Header/GamePlayer.h"
#include "../Header/GameObject.h"

#include "../Header/GamePlayer.h"



auto difference_lenght(std::string a, std::string b)->int;
//using namespace sf;
//using namespace std;
int main()
{

    GamePlayer player;
    GameObject obj1;
    std::vector<std::vector<std::string>> images_obj1 = {
    {"../Animation/Bomb/Explosion/2200.png","../Animation/Bomb/Explosion/2200.png",
    "../Animation/Bomb/Explosion/2200.png","../Animation/Bomb/Explosion/2200.png",
    "../Animation/Bomb/Explosion/2200.png","../Animation/Bomb/Explosion/2200.png",
    "../Animation/Bomb/Explosion/2200.png","../Animation/Bomb/Explosion/2200.png",
      "../Animation/Bomb/Explosion/2200.png","../Animation/Bomb/Explosion/2200.png"},
    {"../Animation/Bomb/Walking/aaaaaa00.png","../Animation/Bomb/Walking/aaaaaa01.png",
    "../Animation/Bomb/Walking/aaaaaa02.png","../Animation/Bomb/Walking/aaaaaa03.png",
    "../Animation/Bomb/Walking/aaaaaa04.png","../Animation/Bomb/Walking/aaaaaa05.png",
    "../Animation/Bomb/Walking/aaaaaa06.png","../Animation/Bomb/Walking/aaaaaa07.png",
      "../Animation/Bomb/Walking/aaaaaa08.png","../Animation/Bomb/Walking/aaaaaa09.png"},
    };


  //I want to use all data about the word here to check all collisions
  std::string game_location("0001000002"); //1 is player position
                                          //2 is object position
  std::string input_answer;
  std::string output_text;
  float health_damage = 0;
  //TODO(igorkkkk) add text downloading to output_text variable

  sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Game", sf::Style::Fullscreen); //TODO(igorkkkk) change game name
  //sf::Style::Fullscreen is used to avoid resizing problems


  obj1.SetStringM(images_obj1);
  obj1.GetSprite().setScale(0.05f, 0.05f);
  obj1.SetPosition(sf::Vector2f(100, 100));
  player.GetSprite().setScale(1.0f, 1.0f);
  player.SetPosition(sf::Vector2f (0,  0));
 
  //define cont frame rate
  window.setFramerateLimit(60);
  DrawMenu DrawMenu(window);
  DrawGame DrawGame(window);

  bool menuOpened = true;

  while (window.isOpen()) //main program
  {
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        switch (event.type)
        {
          case (sf::Event::MouseButtonPressed):
              switch (event.mouseButton.button) {
              case sf::Mouse::Left:
                  std::vector<int> mousePosition = DrawMenu.GetPosition(event);
                  sf::FloatRect playButtonRect = DrawMenu.playButtonGetRect();
                  sf::Vector2f playButtonCenter = DrawMenu.playButtonGetCenter();
                  sf::FloatRect exitButtonRect = DrawMenu.exitButtonGetRect();
                  sf::Vector2f exitButtonCenter = DrawMenu.exitButtonGetCenter();

                  if (mousePosition[0] <= (playButtonCenter.x + playButtonRect.width) 
                      && mousePosition[0] >= (playButtonCenter.x)
                      && mousePosition[1] <= (playButtonCenter.y + playButtonRect.height)
                      && mousePosition[1] >= (playButtonCenter.y)) {
                      menuOpened = false;
                  }
                  else if (mousePosition[0] <= (exitButtonCenter.x + exitButtonRect.width)
                      && mousePosition[0] >= (exitButtonCenter.x)
                      && mousePosition[1] <= (exitButtonCenter.y + exitButtonRect.height)
                      && mousePosition[1] >= (exitButtonCenter.y)) {
                      window.close();
                  }
                  break;
              }
          case (sf::Event::KeyReleased):
              switch (event.key.code){
              case sf::Keyboard::Escape:
                  menuOpened = true;
                  //change start sprite to continue 
                  break;
              }
        }
      //input answer string unless we write maximum lenght of the answer
      if (input_answer.length() != output_text.length()) {
        if (event.type == sf::Event::KeyPressed)
        {
          input_answer += event.key.code;
        }
      }
    }

    //now we can compare string and affect the damage
    //TODO(igorkkkk) influence on player's life balancee
//<<<<<<< HEAD
//    health_damage = difference_lenght(input_answer, output_text);
//=======
//    //health_damage = differernce_lenght(input_answer, output_text);
//>>>>>>> menu


    window.clear();
    if (menuOpened) {
      DrawMenu.Draw(window);
    }
    else {
      std::cout << player.GetTexture().getSize().y;
      DrawGame.Draw(window);
      player.DrawPlayer(window, 1);
      obj1.DrawObject(window, 1);
    }
   //TODO: draw all object before showing the main window
    window.display();
  }

  return 0;
}



auto difference_lenght(std::string a, std::string b)->int {
  auto itba = a.begin();
  auto itbb = b.begin();
  auto itea = a.end();
  auto iteb = b.end();
  int num = 0;
  for (; itba != itea;itba++,itbb++) {
    //check for the register?
    if (*itba == *itbb) {
      num++;
    }
  }
  return a.length() - num;
}