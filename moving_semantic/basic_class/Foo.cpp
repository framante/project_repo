#include "Foo.hpp"
#include <iostream>


Foo::Foo(std::size_t n) : sz{n}, p{new double[n]}
{
  for(unsigned i = 0; i < sz; ++i)
    p[i] = i;
}

Foo::~Foo()
{
  delete[] p;
}

Foo::Foo(const Foo & rhs) : sz{rhs.sz}, p{new double[rhs.sz]}
{
  for(unsigned i = 0; i < sz; ++i)
    p[i] = rhs.p[i];
}

Foo & Foo::operator=(const Foo & rhs)
{
  if(this != & rhs)
    {
      delete[] p;
      sz = rhs.sz;
      p = new double[rhs.sz];
      for(unsigned i = 0; i < sz; ++i)
	p[i] = rhs.p[i];
    }
  return *this;
}

Foo::Foo(Foo && rhs) : sz{rhs.sz}, p{rhs.p}
{
  rhs.sz = 0;
  rhs.p = nullptr;
}

Foo & Foo::operator=(Foo && rhs)
{
  sz = rhs.sz;
  p = rhs.p;
  rhs.p = nullptr;
  rhs.sz = 0;
  return *this;
}

void Foo::print() const
{
  if (p != nullptr)
    {
      for (unsigned i = 0; i < sz; ++i)
	std::cout << p[i] << " ";
      std::cout << std::endl;
    }
  else
    std::cout << "empty" << std::endl;
}

std::size_t Foo::size_of_array() const
{
  return sz;
}
