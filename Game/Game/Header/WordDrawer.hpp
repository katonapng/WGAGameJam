#ifndef WORDDRAWER_HPP
#define WORDDRAWER_HPP

#include "SFML/Graphics.hpp"
#include <string>

class WordDrawer {
public:
  WordDrawer(const std::string &string, const std::string &font_path,
             const std::size_t window_width);

private:
  void InitFont(const std::string &path);

public:
  void Draw(sf::RenderWindow &window);

  [[nodiscard]] inline bool FillNextSymbol(const char symbol) noexcept {
    if (last_index_ == value_.size()) {
      return false;
    }

    if (value_[last_index_] == symbol) {
      ++last_index_;
      return true;
    }
    return false;
  }

  void SetNewWord(std::string new_word);

  inline std::size_t GetCursor() { return last_index_; }

  inline std::size_t GetWordSize() { return value_.size(); }
  bool  GetInputRes() { return (value_.size() - last_index_); }
private:
  std::string value_;
  sf::Color filled_color_;
  sf::Color unfilled_color_;
  std::size_t last_index_;
  sf::Font font_;
  float font_size_;
};

#endif // WORDDRAWER_HPP
