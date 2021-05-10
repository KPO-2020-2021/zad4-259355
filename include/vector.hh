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

    Vector();

    Vector(double [SIZE]);

    Vector operator + ( Vector &v);

    Vector operator - ( Vector &v);

    Vector operator * (const double &tmp);

    Vector operator / (const double &tmp);

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





