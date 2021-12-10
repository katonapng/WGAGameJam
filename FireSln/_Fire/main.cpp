#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <string.h>
#include <algorithm>


auto differernce_lenght(std::string a, std::string b)->int;
//using namespace sf;
//using namespace std;
int main()
{
  //I suppose to use all data about the word here to chek all collisions
  std::string game_location("0001000002"); //1 is player position
                                          //2 is object position
  std::string input_answer;
  std::string output_text;
  float health_damage 0;
  //TODO(igorkkkk) add text downloading to output_text variable

  sf::RenderWindow window(sf::VideoMode(640, 480), "Game"); //TODO(igorkkkk) change game name

  while (window.isOpen()) //main program
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();

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
    health_damage = differernce_lenght(input_answer, output_text);


    window.clear();
   //TODO: draw all object before showing the main window
    window.display();
  }

  return 0;
}



auto differernce_lenght(std::string a, std::string b)->int {
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