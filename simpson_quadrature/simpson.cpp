#include <iostream>
#include <cmath>

typedef double real;
using pointer_to_func = real (*)(real);

real simpson_quad(pointer_to_func const, real, real, unsigned);

int main(int argc, char ** argv)
{
  pointer_to_func func = std::sin;
  real a = 0;
  real b = 2*M_PI;
  unsigned intervals = 150;
  real res = simpson_quad(func, a, b, intervals);
  std::cout << "the integral in the interval (" << a << "," << b << ") is: " <<
    res << std::endl;
  return 0;
}

real simpson_quad(pointer_to_func const integrand, real a, real b, unsigned N)
{
  const real h = (b - a) / N;
  real result = 0.;
  for(unsigned i = 0; i < N; ++i)
    {
      result += integrand(a + i*h) + integrand(a + (i +0.5)*h) +
	integrand(a + (i+1)*h);
    }
  result *= h/6;
  return result;
}
