#include <iostream>
#include <memory>

class Base
{
public:
  virtual ~Base()=default;
  virtual void hi()const
    {
      std::cout<<"Hello, I am Base object\n";
    }
};
