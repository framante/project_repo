#include <iostream>
#include <algorithm>
#include <complex>

typedef double real;

std::complex<real> compute_square_root(real);
template <class T>
std::tuple<T,unsigned int> Sqrt(T const & x);

int main(int argc, char ** argv)
{
  real x = 0.;
  std::cout << "insert a number: ";
  std::cin >> x;

  std::complex<real> y = compute_square_root(x);
  std::cout << "the square root of " << x << " is: " << y << std::endl;

  decltype(auto) y1 = sqrt(x);
  std::cout << "the square root of " << x << " is: " << std::get<0>(y1) <<
    " with " << std::get<1>(y1) << " iterations" << std::endl;

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

template <class T>
std::tuple<T,unsigned int> Sqrt(T const & x)
{
  // a trick to make it work for complex
  using Scalar =decltype(std::abs(x));
  unsigned int counter = 0u;
  constexpr unsigned int max_iter=100;
  if (x==0.0 || x==1.0)return {x,counter};
  Scalar tol = 10.0*std::numeric_limits<Scalar>::epsilon();
  // Starting point (it can be improved)
  T result = 0.5*(std::abs(x)> 1.0? x: T{1.0});
  T prevresult=0.0;
  while (std::abs(result-prevresult)>tol && counter++<max_iter)
  {
    prevresult=result;
    result = (result + x/result)*0.5;
  }
  return {result,counter};
}
