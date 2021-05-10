#pragma once

#include "size.hh"
#include <iostream>
#include <math.h>
#include <iomanip>


template <typename type, unsigned int size_table>
class Vector {

private:

    type size[size_table];     //Tablica wektora

public:

    // typedef Vector Vector3;

    Vector(){
    for (int i = 0; i < SIZE; ++i) {
        size[i] = 0;
    }
    };

    Vector(double tmp[SIZE]){
    for (int i = 0; i < SIZE; ++i) {
        size[i] = tmp[i];
    }
    };

    Vector operator + ( Vector &v){
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] += v[i];
    }
    return result;
    };

    Vector operator - ( Vector &v){
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] -= v[i];
    }
    return result;
    };

    Vector operator * (const double &tmp){
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] *= tmp;
    }
    return result;
    };

    Vector operator / (const double &tmp){
    Vector result;
    if(tmp != 0){
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] / tmp;
    }}
    else{
        throw std::invalid_argument("Division by 0");
    }
    return result;
    };

    /******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
    const double &operator [] (int index) const{
        if (index < 0 || index >= SIZE) {
            throw std::out_of_range("Error: Vector jest poza zasiegiem");    
        } 
        return size[index];    
    };

    /******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
    double &operator [] (int index){
        return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
    };

    // Vector gauss(Matrix mat);

    bool operator == (const Vector tmp) const ;

    bool operator != (const Vector tmp) const ;

};

std::ostream &operator << (std::ostream &stream, Vector<double,3> const &tmp);

std::istream &operator >> (std::istream &in, Vector<double,3> &tmp);

std::ostream &operator << (std::ostream &stream, Vector<double,2> const &tmp);

std::istream &operator >> (std::istream &in, Vector<double,2> &tmp);






