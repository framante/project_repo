#ifndef NORMS_HPP
#define NORMS_HPP

#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <iostream>
#include <complex>
#include <type_traits>


template <typename Container>
class Norms
{
public:
   
   Norms(Container const & c) : myContainer{c} {};
   template <unsigned int p>
   auto compute() const
  {
   if constexpr (p!=0u)
		  return std::pow(std::accumulate(myContainer.begin(),
						  myContainer.end(), 0.,
                                      [](auto const & x,auto const& y)
				      {
					return x+std::pow(std::abs(y),p);
				      }
						  ),
				  1./static_cast<double>(p)
				  );
      else
         return std::count_if(myContainer.begin(), myContainer.end(),
                           [](auto i){return i;}
			      );
  }
private:
  const Container & myContainer;
};



#endif /* NORMS_HPP */
