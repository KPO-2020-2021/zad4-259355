#ifndef Vector3_HH
#define Vector3_HH

#include "vector.hh"

typedef Vector<double, SIZE> Vector3;

template<>
Vector3 Vector3::operator + ( Vector3 &v);

template<>
Vector3 Vector3::operator - ( Vector3 &v);

template<>
Vector3 Vector3::operator * (const double &tmp);

template<>
Vector3 Vector3::operator / (const double &tmp);

template<>
bool Vector3::operator == (const Vector3 tmp) const ;

template<>
bool Vector3::operator != (const Vector3 tmp) const ;

std::istream &operator >> (std::istream &in, Vector3 &tmp);
std::ostream &operator << (std::ostream &stream, Vector3 const &tmp);

#endif
