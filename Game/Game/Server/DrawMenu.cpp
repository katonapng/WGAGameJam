#include "../Header/DrawMenu.hpp"

using namespace std;
namespace fs = std::filesystem;

DrawMenu::DrawMenu(sf::RenderWindow &window) {
  auto path{fs::current_path()
               /* .append("WGAGameJam")
                .append("Game")
                .append("Game")*/
                .append("MenuImages")};
  if (auto tmp{path};
      !gameName.loadFromFile(tmp.append("rapid_fire_bullets2.png").string())) {
    exit(1);
  }

  if (auto tmp{path};
      !playButton.loadFromFile(tmp.append("button_start_hover.png").string())) {
    exit(1);
  }

  if (auto tmp{path};
      !exitButton.loadFromFile(tmp.append("button_exit_hover.png").string())) {
    exit(1);
  }

  if (auto tmp{path};
      !background.loadFromFile(tmp.append("background.png").string())) {
    exit(1);
  }

  float width = window.getSize().x;
  float height = window.getSize().y;

  // needs modification, doesn't scale with window
  playButtonSprite.setScale(0.7, 0.7);
  exitButtonSprite.setScale(0.5, 0.5);

  sf::Vector2u gameNameSize = gameName.getSize();
  sf::Vector2u playButtonSize = playButton.getSize();
  sf::Vector2u exitButtonSize = exitButton.getSize();
  sf::Vector2u backgroundSize = background.getSize();

  float scaleX = (float)width / backgroundSize.x;
  float scaleY = (float)height / backgroundSize.y;

  backgroundSprite.setPosition(0, 0);
  backgroundSprite.setTexture(background);
  backgroundSprite.setScale(scaleX, scaleY);

  gameNameSprite.setPosition(width / 2 - gameNameSize.x / 2, height / 6);
  gameNameSprite.setTexture(gameName);

  playButtonSprite.setPosition(
      width / 2 - (playButtonSize.x * playButtonSprite.getScale().x) / 2,
      1.8 * height / 4);
  playButtonSprite.setTexture(playButton);

  exitButtonSprite.setPosition(
      width / 2 - (exitButtonSize.x * exitButtonSprite.getScale().x) / 2,
      2.7 * height / 4);
  exitButtonSprite.setTexture(exitButton);
}

DrawMenu::~DrawMenu() {}

void DrawMenu::Draw(sf::RenderWindow &window) {
  window.draw(backgroundSprite);
  window.draw(gameNameSprite);
  window.draw(playButtonSprite);
  window.draw(exitButtonSprite);
}

vector<int> DrawMenu::GetPosition(sf::Event &evnt) {
  return {evnt.mouseButton.x, evnt.mouseButton.y};
}

sf::FloatRect DrawMenu::playButtonGetRect() {
  return playButtonSprite.getGlobalBounds();
}

sf::Vector2f DrawMenu::playButtonGetCenter() {
  return playButtonSprite.getPosition();
}

sf::FloatRect DrawMenu::exitButtonGetRect() {
  return exitButtonSprite.getGlobalBounds();
}

sf::Vector2f DrawMenu::exitButtonGetCenter() {
  return exitButtonSprite.getPosition();
}
