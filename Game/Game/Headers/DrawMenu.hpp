#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Image.hpp>
#include <filesystem>

#define MAX_ITEM_NUMBER 2

using namespace std;

class DrawMenu {
	// Load a texture from a file
	sf::Texture texture;
	sf::Sprite sprite;

	//TODO:add drawing menu and cheking keyboard input
public:
	DrawMenu(sf::RenderWindow& window);
	~DrawMenu();

	void Draw(sf::RenderWindow &window);
	vector<int> GetPosition(sf::Event &evnt);
	sf::FloatRect playButtonGetRect();
	sf::Vector2f playButtonGetCenter();

	sf::FloatRect exitButtonGetRect();
	sf::Vector2f exitButtonGetCenter();

private:
	sf::Texture gameName;
	sf::Sprite gameNameSprite;
	sf::Texture playButton;
	sf::Sprite playButtonSprite;
	sf::Texture exitButton;
	sf::Sprite exitButtonSprite;
	sf::Texture background;
	sf::Sprite backgroundSprite;
};