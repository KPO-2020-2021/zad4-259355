#ifndef MATRIX2_HH
#define MATRIX2_HH
#include "matrix.hh"

typedef Matrix<double,2>Matrix2;

//Definicje metod szczegolnych gdy dzialamy na Macierzach2D
//Przeciazenie operatora porownania
//Przeciazenie operatora wejscia i wyjscia
//Przeciazenie operatora mnozenia macierzy2D razy Vector2D
std::istream &operator>>(std::istream &in, Matrix2 &mat);

std::ostream &operator<<(std::ostream &out, Matrix2 const &mat);

template<>
bool Matrix2::operator == ( const Matrix2 tmp) const;

template<>
Vector2 Matrix2::operator * (Vector2 tmp) const ;

template<>
Matrix2 Matrix2::operator + (Matrix2 tmp);

template<>
Matrix2 Matrix2::operator * (Matrix2 sec);

#endif
