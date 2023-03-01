#include <string>

#ifndef CAT_H
#define CAT_H

class Cat {
  private:
    std::string name;
    unsigned int lives;

  public:
    Cat();

    Cat(const std::string inputName);

    Cat(std::string inputName, unsigned int lives);

    ~Cat();

    const std::string& get_name();

    const unsigned int& get_lives();

    void set_name(const std::string& inputName);

    void set_lives(const unsigned int& inputLives);

};

#endif
