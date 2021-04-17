#ifdef DERPOLY_HPP
#define DERPOLY_HPP

template<unsigned int order, unsigned int RDegree, typename R>
auto Derivative(Polynomial<RDegree, R> const & p)
{
  if constexpr (order == 0u)
		 return p;
  else if constexpr (order == 1u)
		      return 
    return
      Derivative




#endif /* DERPOLY_HPP */
