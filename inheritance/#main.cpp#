#include "Derived.hpp"
#include <iostream>

void fun1(Base * p)
{
  p->hi();
}
void fun2(const Base & p)
{
  p.hi();
}

void fun3(Base p)
{
  p.hi();
}

int main()
{
  std::cout<<"Polymorphism works only throgh pointers or references!\n";
  Base * p = new Derived;

  fun1(p);
  fun2(*p); // Here I pass a reference to Base!
  fun3(*p); // here I have a Base object!

  auto d = *p; // d is a Base 
  d.hi();
  auto const & e = *p;
  e.hi(); // e is a Base&
  p->hi(); // p is a Base*
  return 0;
}
