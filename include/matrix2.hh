#include "matrix.hh"

typedef Matrix<double,2>Matrix2;

std::istream &operator>>(std::istream &in, Matrix2 &mat);

std::ostream &operator<<(std::ostream &out, Matrix2 const &mat);

template<>
bool Matrix2::operator == ( const Matrix2 tmp) const;

template<>
Vector2 Matrix2::operator * (Vector2 tmp) const ;



