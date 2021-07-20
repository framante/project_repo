#ifndef COMPLEX_HPP
#define COMPLEX_HPP


//homemade type-trait that checks if a type is a complex number.

namespace apsc
{
namespace TypeTraits
{
//! Primary template: false
template <class T>
struct is_complex : public std::false_type
{
  /*!
   * The type of the complex. Here set to void
   */
  using complex_type = void;
};

//! Specialization: true if complex
template <class T>
struct is_complex<std::complex<T>> : public std::true_type
{
  /*!
   * The type of the complex
   */
  using complex_type = std::complex<T>;
};

//! to be consistent with C++17 style
template <class T>
inline bool constexpr is_complex_v = is_complex<T>::value;

template <class T>
using is_complex_t = typename is_complex<T>::type;

} // end namespace TypeTraits
} // end namespace apsc


#endif /* COMPLEX_HPP */
