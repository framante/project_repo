#ifndef POWPOLY_HPP
#define POWPOLY_HPP

template <unsigned int Exp,unsigned int RDegree, typename R>
auto pow(Polynomial<RDegree,R> const & p)
{
  if constexpr (Exp==0u)
  // I use R(1) to construct the scalar corresponding
  // to 1 (relying on conversion).
		 return Polynomial<0u,R>{{R(1)}};
  else if constexpr (Exp==1u)
		      return p;
  else
    return p*pow<Exp-1u>(p);
};

#endif /* POWPOLY_HPP */
