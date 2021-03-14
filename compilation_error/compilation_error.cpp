#include <vector>
#include <iostream>

double oneNorm(std::vector<double> & x);
bool compare1Norm (const std::vector<double> & x, const std::vector<double> & y);

int main(int argc, char ** argv)
{
  std::vector<double> a{1., 2., 3., 4.};
  std::vector<double> b{3.4, 7.2, 8.3};
  std::string to_be_printed = compare1Norm(a, b) ? "norm of a < norm of b":
    "norm of b < norm of a";
  std::cout << to_be_printed << std::endl;
  return 0;
}

double oneNorm(const std::vector<double> & x)
{
  double res{0.0};
  for (std::size_t i=0;i<x.size();++i) res+=std::abs(x[i]);
  return res;
}

bool compare1Norm (const std::vector<double> & x, const std::vector<double> & y)
{
  return oneNorm(x) < oneNorm(y);
}
