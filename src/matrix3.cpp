#include "matrix3.hh"

typedef Matrix<double,3>Matrix3;
/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
template<>
Matrix3::Matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = 0;
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
template<>
Matrix3::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}


/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
template<>
Vector3 Matrix3::operator * (Vector3 tmp) const {
    Vector3 result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
// double &Matrix3::operator()(unsigned int row, unsigned int column) {

//     if (row >= SIZE) {
//         throw std::out_of_range("Error: Macierz jest poza zasiegiem");
//     }

//     if (column >= SIZE) {
//         throw std::out_of_range("Error: Macierz jest poza zasiegiem"); 
//     }

//     return value[row][column];
// }


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
// const double &Matrix3::operator () (unsigned int row, unsigned int column) const {

//     if (row >= SIZE) {
//         std::cout << "Error: Macierz jest poza zasiegiem";
//         exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
//     }

//     if (column >= SIZE) {
//         std::cout << "Error: Macierz jest poza zasiegiem";
//         exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
//     }

//     return value[row][column];
// }

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
template<>
Matrix3 Matrix3::operator + (Matrix3 tmp) {
    Matrix3 result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
std::istream &operator>>(std::istream &in, Matrix3 &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}

// Matrix3 Matrix3::operator * (const Prostokat &pro){
//     Prostokat result;
//     for (int i = 0; i < NOPOINTS; ++i){
//             result(i,0) = this->value[0][0] * pro[i][0] + this->value[1][0] * pro[i][1] + this->value[2][0] * pro[i][2];
//             result(i,1) = this->value[0][1] * pro[i][0] + this->value[1][1] * pro[i][1] + this->value[2][1] * pro[i][2];
//             if( SIZE == 3){
//             result(i,2) = matrix(0,2) * this->pro[i][0] + matrix(1,2) *  this->pro[i][1] + matrix(2,2) * this->pro[i][2];
//     }}
//     return result;
// }


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
std::ostream &operator<<(std::ostream &out, const Matrix3 &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}

// template<>
// Matrix3 Matrix3::init(char tmp, double num, Prostokat &pr){
//     if(tmp == 'x'){
//         matrix.angles[0] = num;
//         matrix.toradians();
//         pr.matrixtmp = matrix.after_x();
//     }
//     else if( tmp == 'y'){
//         matrix.angles[1] = num;
//         matrix.toradians();
//         pr.matrixtmp = matrix.after_y();
//     }
//     else if(tmp == 'z'){
//         matrix.angles[2] = num;
//         matrix.toradians();
//         pr.matrixtmp = matrix.after_z();
//     }
//     else{
//         std::cerr << "Wrong option" << std::endl;
//     }
//     return pr.matrixtmp;
// }

//Metoda inicjujaca macierz obrotu wartosciami trygonometrycznymi danego kata 
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

template<>
Matrix3 Matrix3::after_y(){
    
    this->value[0][0] = cos(this->angle);
    this->value[2][0] = -sin(this->angle);
    this->value[1][1] = 1;
    this->value[0][2] = sin(this->angle);
    this->value[2][2] = cos(this->angle);

    return *this;
}

template<>
Matrix3 Matrix3::after_x(){

    this->value[0][0] = 1;
    this->value[1][1] = cos(this->angle);
    this->value[2][1] = sin(this->angle);
    this->value[1][2] = -sin(this->angle);
    this->value[2][2] = cos(this->angle);

    return *this;
}

//Funkcja zmieniajaca kat ze stopni na radiany i zwracajaca nowa wartosc katu
template<>
double Matrix3::toradians(){

    this->angle = (this->angle * M_PI)/180;
    return this->angle;
}

//Przeciazenie operatora porownania macierzy 
template<>
bool Matrix3::operator == ( const Matrix3 tmp) const {
    int k = 0;
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
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

//Funkcja obliczajaca dzialanie mnozenia dwoch macierzy 
template<>
Matrix3 Matrix3::operator * (Matrix3 sec){
    Matrix3 tmp;
    for( int i = 0; i < SIZE; ++i){
        for( int j = 0; j < SIZE; ++j){
            for( int k = 0; k < SIZE; ++k){
                tmp(i,j) += this->value[i][k] * sec(j,k);
            }
        }
    }
    return tmp;
}

//Funkcja obliczająca wyznacznik 
template<>
double Matrix3::determinant(){
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
}