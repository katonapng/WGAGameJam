#include "../Headers/Window.hpp"

Window::Window()
    : window_{sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                            sf::VideoMode::getDesktopMode().height),
              "Game", sf::Style::Fullscreen},
      game_{window_}, menu_{window_}, is_menu_opened_{true} {
  window_.setFramerateLimit(kFramerateLimit);
}

void Window::StartLoop() {
  while (window_.isOpen()) {
    sf::Event event;

    while (window_.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window_.close();
      }

      if (is_menu_opened_) {
        switch (event.type) {
        case (sf::Event::MouseButtonPressed):
          switch (event.mouseButton.button) {
          case sf::Mouse::Left:
            std::vector<int> mousePosition = menu_.GetPosition(event);
            sf::FloatRect playButtonRect = menu_.playButtonGetRect();
            sf::Vector2f playButtonCenter = menu_.playButtonGetCenter();
            sf::FloatRect exitButtonRect = menu_.exitButtonGetRect();
            sf::Vector2f exitButtonCenter = menu_.exitButtonGetCenter();

            if (mousePosition[0] <=
                    (playButtonCenter.x + playButtonRect.width) &&
                mousePosition[0] >= (playButtonCenter.x) &&
                mousePosition[1] <=
                    (playButtonCenter.y + playButtonRect.height) &&
                mousePosition[1] >= (playButtonCenter.y)) {
              is_menu_opened_ = false;
            } else if (mousePosition[0] <=
                           (exitButtonCenter.x + exitButtonRect.width) &&
                       mousePosition[0] >= (exitButtonCenter.x) &&
                       mousePosition[1] <=
                           (exitButtonCenter.y + exitButtonRect.height) &&
                       mousePosition[1] >= (exitButtonCenter.y)) {
              window_.close();
            }
            break;
          }
        }
      } else {
        if (event.type == sf::Event::KeyReleased) {
          if (event.key.code == sf::Keyboard::Escape) {
            is_menu_opened_ = true;
            break;
          }

          auto key = GetKey(event);
          game_.GetKeyInput(key);
        }
      }
    }

    window_.clear();
    if (is_menu_opened_) {
      menu_.Draw(window_);
    } else {
      game_.Draw();
    }
    window_.display();
  }
}

char Window::GetKey(sf::Event event) {
  switch (event.key.code) {
  case sf::Keyboard::A:
    return 'a';
  case sf::Keyboard::B:
    return 'b';
  case sf::Keyboard::C:
    return 'c';
  case sf::Keyboard::D:
    return 'd';
  case sf::Keyboard::E:
    return 'e';
  case sf::Keyboard::F:
    return 'f';
  case sf::Keyboard::G:
    return 'g';
  case sf::Keyboard::H:
    return 'h';
  case sf::Keyboard::I:
    return 'i';
  case sf::Keyboard::J:
    return 'j';
  case sf::Keyboard::K:
    return 'k';
  case sf::Keyboard::L:
    return 'l';
  case sf::Keyboard::M:
    return 'm';
  case sf::Keyboard::N:
    return 'n';
  case sf::Keyboard::O:
    return 'o';
  case sf::Keyboard::P:
    return 'p';
  case sf::Keyboard::Q:
    return 'q';
  case sf::Keyboard::R:
    return 'r';
  case sf::Keyboard::S:
    return 's';
  case sf::Keyboard::T:
    return 't';
  case sf::Keyboard::U:
    return 'u';
  case sf::Keyboard::V:
    return 'v';
  case sf::Keyboard::W:
    return 'w';
  case sf::Keyboard::X:
    return 'x';
  case sf::Keyboard::Y:
    return 'y';
  case sf::Keyboard::Z:
    return 'z';
  }
}
