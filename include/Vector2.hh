#ifndef Vector2_HH
#define Vector2_HH

#include "vector.hh"

typedef Vector<double, 2> Vector2;

template<>
bool Vector2::operator == (const Vector2 tmp) const ;

template<>
bool Vector2::operator != (const Vector2 tmp) const ;

std::istream &operator >> (std::istream &in, Vector2 &tmp);
std::ostream &operator << (std::ostream &stream, Vector2 const &tmp);

#endif

