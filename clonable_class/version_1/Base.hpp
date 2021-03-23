#include <iostream>
#include <memory>

class Base; //forward declaration!
using ptr_type=std::unique_ptr<Base>;

class Base
{
public:
  virtual ~Base()=default;
  Base()=default;

  Base(Base const &){std::cout<<"Constructing a Base object\n";}

  virtual ptr_type clone() const
    {
      std::cout<<" I am cloning myself: a Base object\n";
      return std::make_unique<Base>(*this);
    }
};
