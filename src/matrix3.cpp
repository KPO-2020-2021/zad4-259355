#include "matrix3.hh"

typedef Matrix<double,3>Matrix3;

/**
 * Przeciazenie operatora wejsciowy
 * @param Wektor3D tmp
 * @return Wektor3D result
 */
template<>
Vector3 Matrix3::operator * (Vector3 tmp) const {
    Vector3 result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}



/**
 * Przeciazenie operatora wejsciowy
 * @param strumien wejsciowy out
 * @param const Macierz3D mat
 * @return strumien in
 */
std::istream &operator>>(std::istream &in, Matrix3 &mat) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}


/**
 * Przeciazenie operatora wyswietlania
 * @param strumien wejsciowy out
 * @param const Macierz3D mat
 * @return strumien out
 */
std::ostream &operator<<(std::ostream &out, const Matrix3 &mat) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}

/**
 * Metoda Matrix3D inicjujaca macierz obrotu o os Oz
 * @return Prostopadloscian
 */
template<>
Matrix3 Matrix3::after_z(){

    // this->toradians();
    this->value[0][0] = cos(this->angle);
    this->value[1][0] = sin(this->angle);
    this->value[0][1] = -sin(this->angle);
    this->value[1][1] = cos(this->angle);
    this->value[2][2] = 1;

    return *this;
}

/**
 * Metoda Matrix3D inicjujaca macierz obrotu o os Oy
 * @return Prostopadloscian
 */
template<>
Matrix3 Matrix3::after_y(){
    
    this->value[0][0] = cos(this->angle);
    this->value[2][0] = -sin(this->angle);
    this->value[1][1] = 1;
    this->value[0][2] = sin(this->angle);
    this->value[2][2] = cos(this->angle);

    return *this;
}

/**
 * Metoda Matrix3D inicjujaca macierz obrotu o os Ox
 * @return Prostopadloscian
 */
template<>
Matrix3 Matrix3::after_x(){

    this->value[0][0] = 1;
    this->value[1][1] = cos(this->angle);
    this->value[2][1] = sin(this->angle);
    this->value[1][2] = -sin(this->angle);
    this->value[2][2] = cos(this->angle);

    return *this;
}

/**
 * Przeciazenie operatora porownania macierzy const
 * @param const Macierz3D tmp
 * @return True or False
 */
template<>
bool Matrix3::operator == ( const Matrix3 tmp) const {
    int k = 0;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(this->value[i][j] == tmp(i,j)){
                k++;
            }
        }
    }
    if(k == 9){
        return true;
    }
    else{
        return false;
    }
}

