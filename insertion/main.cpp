#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <set>


int main(int argc, char ** argv)
{
  std::vector<int> a;
  std::vector<int> b;
  std::set<int> c;
  
  // fill a and b with values
  a.insert(a.begin(), {1,2,4,7,3});
  b.insert(b.begin(), {5,3,2,10,9});
  
  std::vector<int> intersect;
  // sort vectors
  std::sort(a.begin(),a.end());
  std::sort(b.begin(),b.end());
  
  std::set_intersection(a.begin(),a.end(),b.begin(),b.end(),
			std::back_inserter(intersect));
  // std::inserter(intersect.begin(), intersect)
  std::set_intersection(a.begin(),a.end(),b.begin(),b.end(),
			c.begin());

  
  for(auto & elem: a)
    std::cout << elem << " ";
  std::cout << std::endl;

  for(auto & elem: b)
    std::cout << elem << " ";
  std::cout << std::endl;

  for(auto & elem: intersect)
    std::cout << elem << " ";
  std::cout << std::endl;

  for(auto & elem: c)
    std::cout << elem << " ";
  std::cout << std::endl;
  
  return 0;
}
