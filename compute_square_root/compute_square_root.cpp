#include <iostream>
#include <algorithm>
#include <complex>

typedef float real;

std::complex<real> compute_square_root(real);

int main(int argc, char ** argv)
{
  real x = 0.;
  std::cout << "insert a number: ";
  std::cin >> x;
  std::complex<real> y = compute_square_root(x);
  std::cout << "the square root of " << x << " is: " << y << std::endl;
  return 0;
}

std::complex<real> compute_square_root(real x)
{
  real tol = 1e-7;
  if(x == 0)
    return x;
  else if(x > 0)
    {
      real y0 = x;
      real y1 = 0.5 * std::max(x, 1.f);
      while(std::abs(y1 - y0) > tol)
	{
	  y0 = y1;
	  y1 = 0.5 * (y0 + x/y0);
	}
      return std::complex<real>(y1, 0.);
    }
  else
    {
      std::complex<real> sqrt = compute_square_root(-x);
      return std::complex<real>(0., sqrt.real());
    }
}

