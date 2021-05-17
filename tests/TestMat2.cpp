#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

#include "../tests/doctest/doctest.h"
#include "matrix2.hh"
#include "size.hh"
#include "example.h"
#include <cmath>
#include <fstream>

// Test Matrix2D

TEST_CASE("Matrix2 - toradians"){
    Matrix2 matr;
    matr.angle = 30;
    matr.toradians();
    double radangle = 0.5235987756;
    CHECK( abs(matr.angle - radangle) <= MIN_DIFF );
}

TEST_CASE("Matrix2 - sum of matrixs"){

    double arg1[][2] = {{20,20}, {20,20}};
    Matrix2 matr = Matrix2(arg1);

    double arg2[][2] = {{20,20}, {30,30}};
    Matrix2 matr2 = Matrix2(arg2);

    double argtemp[][2] = {{40,40}, {50,50}};
    Matrix2 matrtemp = Matrix2(argtemp);

    for(int i = 0; i < 2; ++i){
    CHECK( abs(matrtemp(i,i) - (matr(i,i) + matr2(i,i))) <= MIN_DIFF );
    }
}

TEST_CASE("Matrix2 - multiplication (vector)"){

    double arg1[2] = {20,20};
    Vector2 vec = Vector2(arg1);

    double arg2[][2] = {{20,30}, {20,30}};
    Matrix2 matr = Matrix2(arg2);

    double argtemp[2] = {1000,1000};
    Vector2 vectemp = Vector2(argtemp);

    CHECK( vectemp == matr * vec );
}

TEST_CASE("Index operator"){
  double value[][2] = { {3,4}, {3,4}};
  double a, b;
  Matrix2 mat(value);
  a = mat(0,0);
  b = mat(0,1);
  CHECK( (a == 3 && b == 4) );
}

TEST_CASE("Index operator values to vector"){
  double a = 3;
  double b = 4;
  double c = 0;
  double d = 5;
  Matrix2 mat;
  mat(0,0) = a;
  mat(0,1) = b;
  mat(1,0) = c;
  mat(1,1) = d;

  CHECK( (mat(0,0) == 3 && mat(0,1) == 4 && mat(1,0) == 0 && mat(1,1) == 5) );
}

TEST_CASE("Matrix2 - Constructor values in"){
  double value[][2] = {{3,4}, {4,5}};
  Matrix2 mat(value);
  CHECK( (mat(0,0) == 3 && mat(0,1) == 4 && mat(1,0) == 4 && mat(1,1) == 5) );
}

TEST_CASE("Matrix2 - Out of range"){
  double value[][2] = {{3,4}, {4,5}};
  Matrix2 mat(value);
  WARN_THROWS( mat(2,2));
}

TEST_CASE("Matrix2 - Start Constructor"){
  Matrix2 mat;
  CHECK( (mat(0,0) == 0 && mat(0,1) == 0 && mat(1,0) == 0 && mat(1,1) == 0) );
}

TEST_CASE("Matrix2 - >> operator"){
  Matrix2 mat;
  std::istringstream in("0 0 1 1");
  in >> mat;
  CHECK( (mat(0,0) == 0 && mat(0,1) == 0 && mat(1,0) == 1 && mat(1,1) == 1) );
}

TEST_CASE("Matrix2 - display"){
    double value[][2] = {{3,4}, {4,5}};
    Matrix2 mat(value);
    std::ostringstream stream;
    stream << mat;
    CHECK( "| 3 | | 4 | | 4 | | 5 | " == stream.str());
}

TEST_CASE("Matrix2 - to radians"){
    double cos1;
    double ang;
    double t = 0;
    ang = -M_PI/2;
    cos1 = cos(ang);
    CHECK((t - cos1) <= MIN_DIFF);
}

TEST_CASE("Matrix2 - multiplication by another matrix"){
    double arg[][2] = {{1,1}, {2,2}};
    double arg1[][2] = {{1,2}, {1,2}};
    double res[][2] = {{5,5}, {5,5}};
    Matrix2 mat1 = Matrix2(arg);
    Matrix2 mat2 = Matrix2(arg1);
    Matrix2 tmp(res);
    CHECK( tmp == mat1 * mat2);
}

TEST_CASE("Matrix2 - determinant"){
  double value[][2] = {{3,3}, {4,5}};
  Matrix2 mat(value);
  double deter;
  double tmp = 3;
  deter = mat.determinant();
  CHECK( (deter - tmp) < MIN_DIFF);
}

