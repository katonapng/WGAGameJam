#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <string.h>
#include <algorithm>
#include "DrawMenu.h"

using namespace std;


auto differernce_lenght(std::string a, std::string b)->int;
//using namespace sf;
//using namespace std;
int main()
{
  //I want to use all data about the word here to check all collisions
  std::string game_location("0001000002"); //1 is player position
                                          //2 is object position
  std::string input_answer;
  std::string output_text;
  float health_damage = 0;
  //TODO(igorkkkk) add text downloading to output_text variable

  sf::RenderWindow window(sf::VideoMode(2560, 1600), "Game", sf::Style::Fullscreen); //TODO(igorkkkk) change game name
  //sf::Style::Fullscreen is used to avoid resizing problems

  DrawMenu DrawMenu(window);

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
                  vector<int> mousePosition = DrawMenu.GetPosition(event);
                  sf::FloatRect playButtonRect = DrawMenu.playButtonGetRect();
                  sf::Vector2f playButtonCenter = DrawMenu.playButtonGetCenter();
                  sf::FloatRect exitButtonRect = DrawMenu.exitButtonGetRect();
                  sf::Vector2f exitButtonCenter = DrawMenu.exitButtonGetCenter();

                  if (mousePosition[0] <= (playButtonCenter.x + playButtonRect.width) 
                      && mousePosition[0] >= (playButtonCenter.x)
                      && mousePosition[1] <= (playButtonCenter.y + playButtonRect.height)
                      && mousePosition[1] >= (playButtonCenter.y)) {
                      //start the game
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
    //health_damage = differernce_lenght(input_answer, output_text);


    window.clear();
    if (menuOpened) DrawMenu.Draw(window);
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