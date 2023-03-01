#include <iostream>
#include "cat.h"

int main(int argc, char *argv[]) {
  int numberOfCats = argc/2;
  Cat * cats = new Cat[numberOfCats];
  for (int i = 0; i < numberOfCats; i++) {
    if (argc > (2*i)+2) {
      Cat temp(argv[2*i+1], std::stoi(argv[2*i+2]));
      cats[i] = temp;
    } else {
      std::cout <<"Haha!" << std::endl;
      Cat temp(argv[2*i+1]);
      cats[i] = temp;
    }
  }
  for(int i = 0; i < numberOfCats; i++) {
    std::cout << cats[i].get_name() << " has "
        << cats[i].get_lives() << " lives." << std::endl;
  }
  delete[] cats;
  return 0;
}
