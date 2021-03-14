#include <iostream>
#include <algorithm>

typedef float real;

real compute_square_root(real);

int main(int argc, char ** argv)
{
  real x = 0.;
  std::cout << "insert a number: ";
  std::cin >> x;
  real y = compute_square_root(x);
  std::cout << "the square root of " << x << " is: " << y << std::endl;
  return 0;
}

real compute_square_root(real x)
{
  real tol = 1e-7;
  if(x == 0)
    return x;
  real y0 = x;
  real y1 = 0.5 * std::max(x, 1.f);
  while(std::abs(y1 - y0) > tol)
    {
      y0 = y1;
      y1 = 0.5 * (y0 + x/y0);
    }
  return y1;    
}
