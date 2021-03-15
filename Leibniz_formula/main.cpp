#include <iostream>

typedef double real;

real Liebniz(unsigned);
real Liebniz_2(unsigned);

int main(int argc, char ** argv)
{
  unsigned iterations = 0;
  std::cout << "insert number of iterations: " << std::endl;
  std::cin >> iterations;
  real pi1 = Liebniz(iterations);
  real pi2 = Liebniz_2(iterations);

  std::cout << "for " << iterations << " iterations, pi is: " <<
    pi1 << std::endl;
  std::cout << "for " << iterations << " iterations, pi is: " <<
    pi2 << std::endl;


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

