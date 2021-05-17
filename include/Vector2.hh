#ifndef Vector2_HH
#define Vector2_HH

#include "vector.hh"

typedef Vector<double, 2> Vector2;

//Definicje metod szczegolnych gdy dzialamy na wektorach2D
//Przeciazenie operatora porownania
//Przeciazenie operatora roznych
//Przeciazenie operatora wejscia i wyjscia

template<>
bool Vector2::operator == (const Vector2 tmp) const ;

template<>
bool Vector2::operator != (const Vector2 tmp) const ;

// template<>
// Vector2 Vector();

// template<>
// Vector2(double tmp[2]);

template<>
Vector2 Vector2::operator + (const Vector2 &v);

template<>
Vector2 Vector2::operator - (const Vector2 &v);

template<>
Vector2 Vector2::operator * (const double &tmp);

template<>
Vector2 Vector2::operator / (const double &tmp);

std::istream &operator >> (std::istream &in, Vector2 &tmp);
std::ostream &operator << (std::ostream &stream, Vector2 const &tmp);

#endif

