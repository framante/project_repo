#include <iostream>
#include <cmath>
#include "myclass.hpp"

int main(int argc, char ** argv)
{
  myclass mm(5, 7.0);
  std::cout << "this is a modification" << std::endl;
  std::cout << "my class contains " << mm.get_i() << " , " <<
    mm.get_j() << std::endl;

  return 0;
}
