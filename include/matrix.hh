#pragma once

#include "size.hh"
#include "Vector3.hh"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <stdexcept>

template<typename type, unsigned int table_size>
class Matrix {

private:
    type value[table_size][table_size];               // Wartosci macierzy

public:
    double angle; 

    Matrix(double [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    Vector3 operator * (Vector3 tmp) const;           // Operator mnożenia przez wektor

    Matrix operator + (Matrix tmp);

    double determinant();

    Matrix after_x();

    Matrix after_y();

    Matrix after_z();

    double toradians();

    // Matrix init(char tmp, double num, Prostokat &pr);


    double  &operator () (unsigned int row, unsigned int column){
        if (row >= SIZE) {
        throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    if (column >= SIZE) {
        throw std::out_of_range("Error: Macierz jest poza zasiegiem"); 
    }

    return value[row][column];
    };
    


    const double &operator () (unsigned int row, unsigned int column) const{
        if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }
    return value[row][column];
    };



    Matrix operator * (Matrix sec);

    bool operator == ( const Matrix tmp) const;

};

// std::istream &operator>>(std::istream &in, Matrix &mat);

// std::ostream &operator<<(std::ostream &out, Matrix const &mat);

