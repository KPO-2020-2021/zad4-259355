#include "matrix2.hh"

typedef Matrix<double,2>Matrix2;

/**
 * Przeciazenie operatora porownania macierzy const
 * @param const Macierz2D tmp
 * @return True or False
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

/**
 * Przeciazenie operatora wejsciowy
 * @param strumien wejsciowy out
 * @param const Macierz2D mat
 * @return strumien in
 */
std::istream &operator>>(std::istream &in, Matrix2 &mat) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}

/**
 * Przeciazenie operatora wyswietlania
 * @param strumien wejsciowy out
 * @param const Macierz2D mat
 * @return strumien out
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

/**
 * Przeciazenie operatora wejsciowy
 * @param Wektor2D tmp
 * @return Wektor2D result
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

///<Przeciazenie operatora dodawania dwoch macierzy
    /**
     * @param - macierz tmp
     * @return - wynik dodawania result
    */
template<>
Matrix2  Matrix2::operator + (Matrix2 tmp){
    Matrix result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

///<Przeciazenie operatora mnozenia macierzy razy macierz 
    /**
     * @param sec - macierz
     * @return macierz tmp - wynik mnozenia
     */
template<>
Matrix2 Matrix2::operator * (Matrix2 sec){
    Matrix tmp;
    for( int i = 0; i < 2; ++i){
        for( int j = 0; j < 2; ++j){
            for( int k = 0; k < 2; ++k){
                tmp(i,j) += this->value[i][k] * sec(j,k);
            }
        }
    }   
    return tmp;
    }