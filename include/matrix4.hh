#ifndef MATRIX4_HH
#define MATRIX4_HH
#include "matrix.hh"

typedef Matrix<double,4>Matrix4;

/**
 * Funkcja wypelniajaca macierz 4x4 odpowiednio obrotem o os x o kat alfa, os y o kat beta, os z o kat gamma oraz translacje o wektor vec3
 * @param Vector3 angles - katy obrotu
 * @param Vector3 vec3 - wektor translacji
 * @return Matrix4 
 */
// template<>
// Matrix4 Matrix4::fill(Vector3 angles, Vector3 vec3){
//     Matrix<double,3> matrx, matry, matrz, matrtemp;
//     angles.toradians();
//     matrx.angle = angles[0];
//     matry.angle = angles[1];
//     matrz.angle = angles[2];
//     matrtemp = matrz.after_z() * matry.after_y() * matrx.after_x();
//     for(int i = 0; i < 3; ++i){
//         for(int j = 0; j < 3; ++j){
//             value[i][j] = matrtemp(i,j);
//         }
//     }
//     for(int k = 0; k < 3; ++k){
//         value[3][k] = vec3[k];
//     }
//     return *this;
// }

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