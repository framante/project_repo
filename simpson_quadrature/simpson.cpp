#include <iostream>
#include <cmath>

typedef double real;
using pointer_to_func = real (*)(real);

real simpson_quad_version1(pointer_to_func const &, real, real, unsigned);
real simpson_quad_version2(pointer_to_func const &, real, real, unsigned);
real simpson_quad_version3(pointer_to_func const &, real, real, unsigned);

int main(int argc, char ** argv)
{
  pointer_to_func func = std::sin;
  real a = 0;
  real b = M_PI;
  unsigned intervals = 150;
  real res1 = simpson_quad_version1(func, a, b, intervals);
  real res2 = simpson_quad_version2(func, a, b, intervals);
  real res3 = simpson_quad_version3(func, a, b, intervals);

  
  std::cout << "the integral in the interval (" << a << "," << b << ") for version 1 is: " << res1 << std::endl;
  std::cout << "the integral in the interval (" << a << "," << b << ") for version 2 is: " << res2 << std::endl;
  std::cout << "the integral in the interval (" << a << "," << b << ") for version 3 is: " << res3 << std::endl;

  
  return 0;
}

real simpson_quad_version1(pointer_to_func const & integrand, real a, real b,
			   unsigned N)
{
  // to be implemented:
  // h/6 * sum i = 0 -> i = N-1 {f(a+i*h) + 4*f(a+(i+0.5*h)) + f(a+(i+1)*h)}
 
  const real h = (b - a) / static_cast<real>(N);
  real result = 0.;
  for(unsigned i = 0; i < N; ++i)
    {
      result += integrand(a + i*h) + 4.*integrand(a + (i +0.5)*h) +
	integrand(a + (i+1)*h);
      // here we're repeating twice the evaluation of a function
      // write it to better understand
    }
  result *= h/6.;
  return result;
}

// considering N equally spaced intervals the formula can be better written 
// h/6 * {f(a) + 4*f(a+h/2) + f(b) + 4*f(b-h/2) + 2*f(b-h) +
//              sum i=1 -> i = N-2 [2 * f(a+i*h) + 4 * f(a+(i+0.5*h))] }
// which is
// h/6 * {f(a) + 4*f(a+h/2) + f(b) +
//         sum i=1 -> i = N-1 [2 * f(a+i*h) + 4 * f(a+(i+0.5*h))] }


real simpson_quad_version2(pointer_to_func const & integrand, real a, real b,
			   unsigned N)
{
  const real h = (b - a) / static_cast<real>(N);
  real result = integrand(a) + integrand(b) + 4.*integrand(a +0.5*h);
  for(unsigned i = 1; i < N; ++i)
    {
      result += 2.*integrand(a + i*h) + 4.*integrand(a + (i +0.5)*h);
    }
  result *= h/6.;
  return result;
}


real simpson_quad_version3(pointer_to_func const & f, real a, real b,
                           unsigned n)
{
 real sum = 0.;
 const real h = (b - a) / static_cast<real>(n);

 real current_term = f(a);

 for(unsigned i = 0.; i < n; ++i){
  real const next_term = f(a + (i + 1.) * h);
  sum += current_term + 4.*f(a + (i + 0.5) * h) + next_term;
  current_term = next_term;
 }

 return h * sum / 6.;
}
