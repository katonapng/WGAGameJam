#include "../Headers/WordGenerator.hpp"

WordsGenerator::WordsGenerator(const std::string& path,
                               std::size_t default_capacity)
    : gen_{std::random_device{}()}, dist_{0, default_capacity - 1} {
  words_.reserve(default_capacity);
  InitWords(path);
  if (words_.size() != default_capacity) {
    std::exit(1);
  }
}

void WordsGenerator::InitWords(const std::string& path) {
  std::ifstream file(path);
  if (!file.is_open()) {
    std::exit(2);
  }

  do {
    std::string line{};
    std::getline(file, line, '\n');
    words_.push_back(line);
  } while (!file.eof());
}

[[nodiscard]] const std::string& WordsGenerator::Generate() {
  return words_[dist_(gen_)];
}