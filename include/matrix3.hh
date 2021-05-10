#include "matrix.hh"

typedef Matrix<double,3>Matrix3;

std::istream &operator>>(std::istream &in, Matrix3 &mat);

std::ostream &operator<<(std::ostream &out, Matrix3 const &mat);

template<>
bool Matrix3::operator == ( const Matrix3 tmp) const;

template<>
Matrix3 Matrix3::after_z();

template<>
Matrix3 Matrix3::after_x();

template<>
Matrix3 Matrix3::after_y();

template<>
Vector3 Matrix3::operator * (Vector3 tmp) const ;






