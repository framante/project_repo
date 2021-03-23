#include "Composer.hpp"
Composer::Composer(ptr_type c):component{std::move(c)}
    {
      std::cout<<"Constructor: creating a class composed polymorphically with a Base" << std::endl;
    }
/*
Composer::Composer(Composer const & c):
    component{c.component->clone()}
  {
    std::cout << "Copy constructor of Composer" << std::endl;
  }

Composer & Composer::operator=(Composer const& c)
  {
    std::cout << "Copy assignment operator of Composer" << std::endl;
    if(this != &c)
        component = c.component->clone();
    return *this;
  }
*/
