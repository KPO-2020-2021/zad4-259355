#include "matrix.hh"

typedef Matrix<double,SIZE>Matrix3;

std::istream &operator>>(std::istream &in, Matrix3 &mat);

std::ostream &operator<<(std::ostream &out, Matrix3 const &mat);

template<>
Matrix3 Matrix3::operator * (Matrix3 sec);

template<>
bool Matrix3::operator == ( const Matrix3 tmp) const;

template<>
Vector3 Matrix3::operator * (Vector3 tmp) const;           // Operator mnożenia przez wektor

template<>
Matrix3 Matrix3::operator + (Matrix3 tmp);

template<>
double Matrix3::determinant();

template<>
double Matrix3::toradians();

template<>
Matrix3 Matrix3::after_x();

template<>
Matrix3 Matrix3::after_y();

template<>
Matrix3 Matrix3::after_z();

// template<>
// Matrix3 Matrix3::init(char tmp, double num, Prostokat &pr);


