// Copyright 2022 Emily Sheehan

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

#pragma once

class RandWriter {
 public:
  RandWriter(std::string text, int k);
  int orderK() const;
  int freq(std::string kgram) const;
  int freq(std::string kgram, char c) const;
  char kRand(std::string kgram);
  std::string generate(std::string kgram, int T);
  friend std::ostream& operator<< (std::ostream &o, RandWriter &rw);

 private:
  int num;
  std::map <std::string, int> kgrams;
  std::string letters_used;
  std::string words;
};
