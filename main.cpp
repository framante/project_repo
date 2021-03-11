#include <iostream>
#include <cmath>
#include "my_subfolder/myclass.hpp"

int main(int argc, char ** argv)
{
  myclass mm(5, 7.0);
  std::cout << "this is a modification" << std::endl;
  std::cout << "I also print the content of myclass" << std::endl;
  std::cout << "my class contains " << mm.get_i() << " , " <<
    mm.get_j() << std::endl;

  return 0;
}
