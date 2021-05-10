#ifndef Vector3_HH
#define Vector3_HH

#include "vector.hh"

typedef Vector<double, 3> Vector3;

template<>
bool Vector3::operator == (const Vector3 tmp) const ;

template<>
bool Vector3::operator != (const Vector3 tmp) const ;

std::istream &operator >> (std::istream &in, Vector3 &tmp);
std::ostream &operator << (std::ostream &stream, Vector3 const &tmp);

#endif
