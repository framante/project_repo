#include <iostream>
#include <vector>

typedef double real;

real Liebniz(unsigned);
real Liebniz_2(unsigned);
real Richardson_extrapolation(unsigned, real);
constexpr inline real  int_pow(real base, real exponent);


int main(int argc, char ** argv)
{
  unsigned iterations = 0;
  std::cout << "insert number of iterations: " << std::endl;
  std::cin >> iterations;
  real pi1 = Liebniz(iterations);
  real pi2 = Liebniz_2(iterations);
  real pi3 = Richardson_extrapolation(iterations, 2);

  std::cout << "for " << iterations << " iterations, pi is: " <<
    pi1 << std::endl;
  std::cout << "for " << iterations << " iterations, pi is: " <<
    pi2 << std::endl;
  std::cout << "for " << iterations << " iterations, pi is: " <<
    pi3 << std::endl;


  return 0; 

}


real Liebniz(unsigned iterations)
{
  real pi = 0.;
  for(unsigned i = 0; i < iterations; ++i)
    {
      unsigned n = 2*i + 1;
      pi += (i%2 == 0) ? 1./n : -1./n;
    }
  return 4.*pi;
}

real Liebniz_2(unsigned iterations)
{
  real pi = 0.;
  for(unsigned i = 0; i < iterations; ++i)
    {
      unsigned n = (4*i + 1) * (4*i +3);
      pi += 2./n;
    }
  return 4.*pi;
}


real Richardson_extrapolation(unsigned iterations, real t)
{
  std::vector<real>v1(iterations);
  std::vector<real>v2(iterations);

  unsigned h = 1;
  v1[0] = Liebniz_2(h);

  for(unsigned i = 1; i < iterations; ++i)
    {
      h *= t;
      v2[0] = Liebniz_2(h);

      for(unsigned j = 0; j < i; j++)
	{
	  const real c = int_pow(t, j+1);
	  v2[j+1] = (c * v2[j] - v1[j]) / (c - 1);
	}
      std::swap(v1, v2);
    }
  return v1.back();
}

constexpr inline real  int_pow(real base, real exponent)
{
 real result = 1.;
 for(unsigned i = 0; i < exponent; i++)
  result *= base;
 return result;
}
