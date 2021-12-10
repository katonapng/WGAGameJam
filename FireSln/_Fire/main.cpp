#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <string.h>


//using namespace sf;
//using namespace std;
int main()
{
  //I suppose to use all data about the word here to chek all collisions
  std::string game_location("0001000002"); //1 is player position
                                          //2 is object position
  std::string input_answer;
  std::string output_text;

  sf::RenderWindow window(sf::VideoMode(640, 480), "Game"); //TODO(igorkkkk) change game name

  while (window.isOpen()) //main program
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();

      //input answer string
      if (event.type == sf::Event::KeyPressed)
      {
        input_answer += event.key.code;
      }
    }


    window.clear();
   //TODO: draw all object before showing the main window
    window.display();
  }

  return 0;
}