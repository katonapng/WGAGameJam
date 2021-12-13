#include "../Headers/WordDrawer.hpp"

WordDrawer::WordDrawer(const std::string &string, const std::string &font_path,
                       std::size_t window_width)
    : value_{string}, filled_color_{sf::Color::Red},
      unfilled_color_{sf::Color::Black}, last_index_{},
      font_size_{window_width * 0.6f / string.size()} {
  InitFont(font_path);
}

void WordDrawer::InitFont(const std::string &font_path) {
  if (!font_.loadFromFile(font_path)) {
    std::exit(3);
  }
}

void WordDrawer::Draw(sf::RenderWindow &window) {
  std::size_t begin_pos{static_cast<std::size_t>(window.getSize().x * 0.45f)};
  std::size_t pos_y{static_cast<std::size_t>(window.getSize().y * 0.35f)};

  sf::Text text;
  text.setFont(font_);
  text.setCharacterSize(font_size_);
  for (std::size_t index{}, size{value_.size()}; index < size; ++index) {
    if (index < last_index_) {
      text.setFillColor(filled_color_);
    } else {
      text.setFillColor(unfilled_color_);
    }
    text.setString(value_[index]);
    text.setPosition(begin_pos + font_size_ * index, pos_y);
    window.draw(text);
  }
}

void WordDrawer::SetNewWord(std::string new_word) {
  font_size_ *= static_cast<float>(value_.size()) / new_word.size(); 
  value_ = std::move(new_word);
  last_index_ = 0;
}
