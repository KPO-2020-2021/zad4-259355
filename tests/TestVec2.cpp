// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

#include "../tests/doctest/doctest.h"
#include "Vector2.hh"
#include "size.hh"
#include "example.h"
#include <cmath>
#include <fstream>

// Tests for Vector2D

TEST_CASE("Vector2 - sum"){
    double arg1[] = {100,100};
    double arg2[] = {300,300};
    Vector2 vec1 = Vector2(arg1);
    Vector2 vec2 = Vector2(arg2);
    double argt[] = {400,400};
    Vector2 temp = Vector2(argt);
    CHECK( (vec1 + vec2) == temp);
}

TEST_CASE("Vector2 - difference"){
    double arg1[SIZE] = {100,100};
    double arg2[SIZE] = {300,300};
    Vector2 vec1 = Vector2(arg1);
    Vector2 vec2 = Vector2(arg2);
    double argt[SIZE] = {-200,-200};
    Vector2 temp = Vector2(argt);
    CHECK( temp == vec1 - vec2);
}

TEST_CASE("Vector2 - multiplication"){
    double arg1[SIZE] = {100,100};
    double arg = 2;
    Vector2 vec1 = Vector2(arg1);
    double argt[SIZE] = {200,200};
    Vector2 temp = Vector2(argt);
    CHECK( temp == vec1 * arg);
}

TEST_CASE("Vector2 - division (arg = 2)"){
    double arg1[SIZE] = {100,100};
    double arg = 2;
    Vector2 vec1 = Vector2(arg1);
    double argt[SIZE] = {50,50};
    Vector2 temp = Vector2(argt);
    CHECK( temp == vec1 / arg);
}

TEST_CASE("Vector2 - division (arg = 0)"){
    double arg1[SIZE] = {100,100};
    double arg = 0;
    Vector2 vec1 = Vector2(arg1);
    WARN_THROWS(vec1 / arg);
}

TEST_CASE("Index operator"){
  double value[] = {3,4};
  double a, b;
  Vector2 Vec(value);
  a = Vec[0];
  b = Vec[1];
  CHECK( (a == 3 && b == 4));
}

TEST_CASE("Index operator values to vector"){
  double a = 3;
  double b = 4;
  Vector2 Vec;
  Vec[0] = a;
  Vec[1] = b;
  CHECK( (Vec[0] == 3 && Vec[1] == 4));
}

TEST_CASE("Constructor values in"){
  double value[] = {3,4};
  Vector2 Vec(value);
  CHECK( (Vec[0] == 3 && Vec[1] == 4));
}

// TEST_CASE("Out of range"){
//   double value[] = {3,4};
//   Vector2 Vec(value);
//   WARN_THROWS( Vec[2]);
// }

TEST_CASE("Start Constructor"){
  Vector2 Vec;
  CHECK( (Vec[0] == 0 && Vec[1] == 0));
}

TEST_CASE(">> operator"){
  Vector2 vec;
  std::istringstream in("0 1");
  in >> vec;
  CHECK( (vec[0] == 0 && vec[1] == 1) );
}

TEST_CASE("Vector2 - display"){
    double arg[] = {0,1};
    Vector2 vec1(arg);
    std::ostringstream stream;
    stream << vec1;
    CHECK( "    0.0000000000    1.0000000000" == stream.str());
}