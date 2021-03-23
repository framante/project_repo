#include "Composer.hpp"

int main()
{
  Composer composer(std::make_unique<Derived>());
  std::cout << "\nnow I construct another object\n" << std::endl;
  auto composer2=composer;
  Composer composer3;
  composer3 = composer2;
  return 0;
}
