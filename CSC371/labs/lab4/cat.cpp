#include "cat.h"
#include <iostream>

Cat::Cat() : name("Tom"), lives(9) {
  std::cout << "Default constructor called..." << std::endl;
}

Cat::Cat(std::string inputname) : name(inputname), lives(9) {
  std::cout << "Constructor called with name..." << std::endl;
}

Cat::Cat(std::string inputname, unsigned int inputlives) : name(inputname), lives(inputlives) {
  std::cout << "Constructor called with name and lives..." << std::endl;
}

Cat::~Cat() {
  std::cout << "Destructor called..." << std::endl;
}

const std::string& Cat::get_name() {
  return name;
}

const unsigned int& Cat::get_lives() {
  return lives;
}

void Cat::set_name(const std::string& inputName) {
    name = inputName;
    std::cout << "set_name called..." << std::endl;
}

void Cat::set_lives(const unsigned int& inputLives) {
    std::cout << "set_lives called..." << std::endl;
    if (inputLives >= lives) return;
    if (inputLives == 0) set_name("The Cat formerly known as " + get_name());
    lives = inputLives;
}
