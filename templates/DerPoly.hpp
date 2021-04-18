#ifdef DERPOLY_HPP
#define DERPOLY_HPP

/*!
   * Derivative of a Polynomial
   *
   * Usage: der<N>(p) (N>=0)
   * @tparam M The derivative order
   * @tparam RDegree The degree of the polynomial
   * @tparam R The scalar field
   * @param p The polynomial
   * @return \frac{d^{M}(p)}{dX^{M}}
   */
template <unsigned M, unsigned RDegree, typename R>
  auto der(Polynomial<RDegree, R> const & p)
  {
    if constexpr (M == 0u)
      return p;
    else if constexpr (RDegree < M)
      return Polynomial<0u,R>{{R(1)}};
    else{
      std::array<R, RDegree> C;
      for(size_t i = 1; i <= RDegree; ++i)
        C[i-1] = i * p.get_coeff()[i];
      return der<M-1>(Polynomial<RDegree-1, R>{C});
    }
  };



#endif /* DERPOLY_HPP */
