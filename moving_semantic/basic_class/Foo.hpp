#ifndef FOO_HPP
#define FOO_HPP

#include <cstddef>

class Foo
{
public:
  // size
  std::size_t size_of_array() const;
  // default constructor
  Foo() = default;
  // constructor initilizes data
  Foo(std::size_t n);
  // Destructor clears the data (a new must be matched by a delete!)
  ~Foo();
  // Copy constructor
  Foo(const Foo & rhs);
  // Copy assignment operator
  Foo & operator=(const Foo & rhs);
  // Move Constructor
  Foo(Foo && rhs);
  // Move assignment operator
  Foo & operator=(Foo && rhs);
  // print
  void print() const;

private:
 double * p = nullptr; // always initialize pointers!
 std::size_t sz = 0;
};


#endif /* FOO_HPP */
