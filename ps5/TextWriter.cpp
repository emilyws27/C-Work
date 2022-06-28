// Copyright Emily Sheehan 2022

#include <iostream>
#include <string>
#include <sstream>
#include "RandWriter.hpp"

int main(int argc, char* argv[]) {
  std::string temp;
  std::string original;
  std::string transformed;

  std::string warning = "Wrong number of arguments - "
  " format should be ./TextWriter L K < <text file>";
  if (argc != 3) {
    std::cout << warning << std::endl;
  }

  int k = atoi(argv[1]);
  int L = atoi(argv[2]);


  while (std::cin >> transformed) {
    original += " " + transformed;
    transformed = "";
  }


  for (int i = 0; i < k; i++) {
    temp.push_back(original[i]);
  }
  std::cout << "After applying Markov transformation: "
  << RandWriter(original,  k).generate(temp, L) << std::endl;
}
