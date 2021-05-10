#pragma once

#include "size.hh"
#include "Vector3.hh"
#include "Vector2.hh"
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

    Matrix(double tmp[SIZE][SIZE]){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
    }                                      // Konstruktor klasy

    Matrix(){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = 0;
        }
    }
    };                               // Konstruktor klasy

    Vector2 operator * (Vector2 tmp) const;         // Operator mnożenia przez wektor

    Vector3 operator * (Vector3 tmp) const;         // Operator mnożenia przez wektor

    Matrix operator + (Matrix tmp){
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
    };

    double determinant(){
    double ratio;
    int i,j,k;
    for( i=0 ; i< SIZE-1 ; i++)
        {
            if(this->value[i][i] == 0.0)
            {
                std::cout<<"Mathematical Error!";
                exit(0);
            }
            for(j=i+1;j<SIZE;j++)
            {
                ratio = this->value[j][i]/this->value[i][i];

                for(k=0;k<SIZE;k++)
                {
                    // std::cout << *this << std::endl;
                    this->value[j][k] = this->value[j][k] - ratio*this->value[i][k];
                }
            }
        }
    // std::cout << *this << std::endl;
    // std::cout << this->value[0][0] << " i " << this->value[0][1] << " i " << this->value[1][1] << std::endl;
    double deter = 1;
    for( i = 0; i < SIZE; ++i){
        deter *= this->value[i][i];
    }

    return deter;
};

    Matrix after_x();

    Matrix after_y();

    Matrix after_z();

    double toradians(){

    this->angle = (this->angle * M_PI)/180;
    return this->angle;
    };

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

    Matrix operator * (Matrix sec){
    Matrix tmp;
    for( int i = 0; i < SIZE; ++i){
        for( int j = 0; j < SIZE; ++j){
            for( int k = 0; k < SIZE; ++k){
                tmp(i,j) += this->value[i][k] * sec(j,k);
            }
        }
    }   
    return tmp;
    };

    bool operator == ( const Matrix tmp) const;

};

// std::istream &operator>>(std::istream &in, Matrix &mat);

// std::ostream &operator<<(std::ostream &out, Matrix const &mat);

