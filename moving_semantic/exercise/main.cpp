#include "Norms2.hpp"
#include <vector>


int main(int argc, char ** argv)
{
  // define the container
  std::vector<double> v {1.,3.,6.,9.};
  Norms norm(v); // v a container
  auto x = norm.compute<3>(); // the 3-norm
  std::cout << "the norm of v is : " << x << std::endl; 
  return 0;
}
