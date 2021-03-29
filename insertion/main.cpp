#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <set>
#include <optional>

int main(int argc, char ** argv)
{
  std::vector<int> a;
  std::vector<int> b;
  std::set<int> c;
		     
  // fill a and b with values
  a.insert(a.begin(), {1,2,4,7,3});
  b.insert(b.begin(), {5,3,2,10,9});
  std::vector<int> d ( std::min(a.size(), b.size()) );
  std::vector<std::optional<int>> e (std::min(a.size(), b.size()));
  
  std::vector<int> intersect;
  // sort vectors
  std::sort(a.begin(),a.end());
  std::sort(b.begin(),b.end());

  // insertion in an empty vector intersect. Here you need back_inserter
  // since the vector is empty and you have to do push_back for every
  // element
  std::set_intersection(a.begin(),a.end(),b.begin(),b.end(),
			std::back_inserter(intersect) );
  
  // insertion in an empty set. Here you need inserter since you have to
  // insert eache element in a set, notice that the second argument is just
  // a hint because the structure is managed based on the order relation
  std::set_intersection(a.begin(),a.end(),b.begin(),b.end(),
			std::inserter(c, c.begin()) );

  // insertion in a resized vector. Here you don't need back_inserter since
  // the vector has already been resized conveniently
  std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), d.begin());

  // insertion in a resized vector. Here you don't need back_inserter since
  // the vector has already been resized conveniently
  std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), e.begin());
  
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

  for(auto & elem: d)
    std::cout << elem << " ";
  std::cout << std::endl;

  for(std::size_t i = 0; i < e.size(); ++i)
    {
      if(e[i])
	std::cout << *e[i] << " ";
      else
	std::cout << "value unset ";
    }
  std::cout << std::endl;
  return 0;
}
