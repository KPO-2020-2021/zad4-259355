#pragma once

#include "size.hh"
#include <iostream>
#include <math.h>
#include <iomanip>

/**
 * \brief Klasa Wektora
 * 
 * Klasa pozwalajaca operowac na argumentach wektora
 * Klasa jest szablonem ktory dziala dla wektora2D i wektora3D
 * Szablon przyjmuje wartości <typ danych, rozmiar macierzy>
 * 
 */
template <typename type, unsigned int size_table>
class Vector {

private:

    type size[size_table];     /**< Tablica wektora */

public:

    ///<Konstruktor Vector
    /**
     * Wypelnia vector zerami
     */ 
    Vector(){
    for (int i = 0; i < SIZE; ++i) {
        size[i] = 0;
    }
    };

    ///<Konstruktor wypelniajacy Vector wartosciami
    /** 
     * @param tablica double tmp[SIZE]
     * @return Wypelniona tablica wektora
     */ 
    Vector(double tmp[SIZE]){
    for (int i = 0; i < SIZE; ++i) {
        size[i] = tmp[i];
    }
    };

    ///<Przeciazenie operatora dodawania wektorow
    /** 
     * @param const Vector &v 
     * @return result Vector
     */ 
    Vector operator + (const Vector &v){
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] += v[i];
    }
    return result;
    };

    ///<Przeciazenie operatora odejmowania wektorow
    /** 
     * @param const Vector &v 
     * @return result Vector
     */ 
    Vector operator - (const Vector &v){
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] -= v[i];
    }
    return result;
    };

    ///<Przeciazenie operatora mnozenia wektora razy cyfra
    /** 
     * @param const double &tmp - mnoznik 
     * @return result Vector
     */ 
    Vector operator * (const double &tmp){
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] *= tmp;
    }
    return result;
    };

    ///<Przeciazenie operatora dzielenia wektora przez cyfra
    /** 
     * @param const double &tmp - dzielnik 
     * @return result Vector
     */ 
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

    ///<Funktor wektora
    /** 
     * @param index - index wektora 
     * @return Wartosc wektora w danym miejscu tablicy jako stala
     */ 
    const double &operator [] (int index) const{
        if (index < 0 || index >= SIZE) {
            throw std::out_of_range("Error: Vector jest poza zasiegiem");    
        } 
        return size[index];    
    };

    ///<Funktor wektora
    /** 
     * @param index - index wektora 
     * @return Wartosc wektora w danym miejscu tablicy 
     */ 
    double &operator [] (int index){
        return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
    };

    // Vector gauss(Matrix mat);

    ///<Przeciazenie operatora porownania wektorow const
    /** 
     * @param tmp - const Vector 
     * @return True or False
     */ 
    bool operator == (const Vector tmp) const ;

    ///<Przeciazenie operatora porownania (!=) wektorow const
    /** 
     * @param tmp - const Vector 
     * @return True or False
     */ 
    bool operator != (const Vector tmp) const ;

};

///<Przeciazenie operatora wyjscia Vector3D
std::ostream &operator << (std::ostream &stream, Vector<double,3> const &tmp);

///<Przeciazenie operatora wejscia Vector3D
std::istream &operator >> (std::istream &in, Vector<double,3> &tmp);

///<Przeciazenie operatora wyjscia Vector2D
std::ostream &operator << (std::ostream &stream, Vector<double,2> const &tmp);

///<Przeciazenie operatora wejscia Vector2D
std::istream &operator >> (std::istream &in, Vector<double,2> &tmp);






