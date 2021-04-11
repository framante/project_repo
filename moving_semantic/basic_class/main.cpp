#include "Foo.hpp"
#include <utility>
#include <iostream>

int main(int argc, char ** argv)
{
  std::size_t a = 3;
  Foo f1(3);
  Foo f2(f1);
  std::cout << "first print" << std::endl;
  std::cout << std::endl;
  
  f1.print();
  f2.print();
  Foo f3(std::move(f2));
  std::cout << "second print" << std::endl;
  std::cout << std::endl;

  f1.print();
  f2.print();
  f3.print();
  Foo f4(6);
  std::cout << "third print" << std::endl;
  std::cout << std::endl;

  f1.print();
  f2.print();
  f3.print();
  f4.print();
  
  f4 = std::move(f1);
  std::cout << "fourth print" << std::endl;
  std::cout << std::endl;

  f1.print();
  f2.print();
  f3.print();
  f4.print();
  
  return 0;
}
