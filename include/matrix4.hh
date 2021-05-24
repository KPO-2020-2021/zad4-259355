#ifndef MATRIX4_HH
#define MATRIX4_HH
#include "matrix.hh"

typedef Matrix<double,4>Matrix4;

/**
 * Funkcja wypelniajaca macierz 4x4 odpowiednio obrotem o os x o kat alfa, os y o kat beta, os z o kat gamma oraz translacje o wektor vec3
 * @param double a - kat alpha
 * @param double b - kat beta
 * @param double g - kat gamma
 * @param Vector3 trans - wektor translacji
 * @return Matrix4 result
 */
template<>
Matrix4 Matrix4::Rot_and_trans(double a, double b, double g, Vector3 trans) {
    Matrix4 result;

    result(0,0) = cos(a*M_PI/180) * cos(b*M_PI/180);
    result(0,1) = cos(a*M_PI/180) * sin(b*M_PI/180) * sin(g*M_PI/180) - sin(a*M_PI/180) * cos(g*M_PI/180);
    result(0,2) = cos(a*M_PI/180) * sin(b*M_PI/180) * cos(g*M_PI/180) + sin(a*M_PI/180) * sin(g*M_PI/180);
    result(0,3) = trans[0];
    result(1,0) = sin(a*M_PI/180) * cos(b*M_PI/180);
    result(1,1) = sin(a*M_PI/180) * sin(b*M_PI/180) * sin(g*M_PI/180) + cos(a*M_PI/180) * cos(g*M_PI/180);
    result(1,2) = sin(a*M_PI/180) * sin(b*M_PI/180) * cos(g*M_PI/180) - cos(a*M_PI/180) * sin(g)*M_PI/180;
    result(1,3) = trans[1];
    result(2,0) = -sin(b*M_PI/180);
    result(2,1) = cos(b*M_PI/180) * sin(g*M_PI/180);
    result(2,2) = cos(b*M_PI/180) * cos(g*M_PI/180);
    result(2,3) = trans[2];
    result(3,0) = 0;
    result(3,1) = 0;
    result(3,2) = 0;
    result(3,3) = 1;

    return result;
}

#endif