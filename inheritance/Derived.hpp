#include "Base.hpp"

class Derived: public Base
{
public:
  void hi() const
    {
      std::cout<<"Hello, I am a Derived object\n";
    }
};
