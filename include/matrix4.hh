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
template<>
Matrix4 Matrix4::fill(Vector3 angles, Vector3 vec3){
    Matrix<double,3> matrx, matry, matrz, matrtemp;
    angles.toradians();
    matrx.angle = angles[0];
    matry.angle = angles[1];
    matrz.angle = angles[2];
    matrtemp = matrz.after_z() * matry.after_y() * matrx.after_x();
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            value[i][j] = matrtemp(i,j);
        }
    }
    for(int k = 0; k < 3; ++k){
        value[3][k] = vec3[k];
    }
    return *this;
}

#endif