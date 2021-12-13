#ifndef WORDGENERATOR_HPP
#define WORDGENERATOR_HPP

#include <fstream>
#include <random>
#include <string>
#include <vector>

class WordsGenerator {
 private:
  void InitWords(const std::string& path);

 public:
  WordsGenerator(const std::string& path, std::size_t default_capacity = 100);

  [[nodiscard]] const std::string& Generate();

 private:
  std::vector<std::string> words_;
  std::mt19937 gen_;
  std::uniform_int_distribution<> dist_;
};

#endif  // !WORDGENERATOR_HPP
