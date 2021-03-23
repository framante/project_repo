#include "Base.hpp"

class Derived: public Base
{
public:
  virtual ~Derived() = default;
  Derived() {
    std::cout << "Constructor: constructing Derived object" << std::endl;
    Base();
  }
  Derived(Derived const &)
  {
    std::cout<<"Copy constructor: constructing a Derived object"<< std::endl;
  }
  ptr_type clone() const override
    {
      std::cout<<"I am cloning myself: a Derived object\n";
      return std::make_unique<Derived>(*this);
    }
};
