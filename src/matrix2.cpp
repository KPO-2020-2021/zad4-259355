#include "matrix2.hh"

typedef Matrix<double,2>Matrix2;

/*********************************************************************************
//  |  Przeciazenie operatora porownania dla macierzy 2D                         |
//  |  Argumenty:                                                                |
//  |      Macierz2D (tmp) .                                                     |
//  |  Zwraca:                                                                   |
//  |      True or False. 
*/
template<>
bool Matrix2::operator == ( const Matrix2 tmp) const {
    int k = 0;
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            if(this->value[i][j] == tmp(i,j)){
                k++;
            }
        }
    }
    if(k == 4){
        return true;
    }
    else{
        return false;
    }
}

/*********************************************************************************
//  |  Przeciazenie operatora wpisywania wartosci do macierzy2D                  |
//  |  Argumenty:                                                                |
//  |      Strumień wejściowy (in), Macierz2D (mat) .                            |
//  |  Zwraca:                                                                   |
//  |      Strumien. 
*/
std::istream &operator>>(std::istream &in, Matrix2 &mat) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}

/*********************************************************************************
//  |  Przeciazenie operatora wypisywania wartosci do macierzy2D                 |
//  |  Argumenty:                                                                |
//  |      Strumień wyjściowy (out), Macierz2D (mat) .                            |
//  |  Zwraca:                                                                   |
//  |      Strumien. 
*/
std::ostream &operator<<(std::ostream &out, const Matrix2 &mat) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}

/*********************************************************************************
//  |  Przeciazenie operatora mnozenia wartosci macierzy2D razy wektor2D         |
//  |  Argumenty:                                                                |
//  |      Vector2D (tmp).                                                       |
//  |  Zwraca:                                                                   |
//  |      Vector2D (result). 
*/
template<>
Vector2 Matrix2::operator * (Vector2 tmp) const {
    Vector2 result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}