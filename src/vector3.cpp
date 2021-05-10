#include "Vector3.hh"

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
std::ostream& operator << ( std::ostream &stream, Vector3 const &tmp){

    stream << std::setw(16) << std::fixed << std::setprecision(10) << tmp[0]
           << std::setw(16) << std::fixed << std::setprecision(10) << tmp[1]
           << std::setw(16) << std::fixed << std::setprecision(10) << tmp[2];

    return stream;
}


/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
std::istream &operator >> (std::istream &in, Vector3 &tmp) {
    for (int i = 0; i < 3; ++i) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}

//Przeciazennie ktore sprawdza czy dane wektory sa rowne
template<>
bool Vector3::operator == ( const Vector3 tmp) const {
    if(abs(this->size[0] - tmp[0]) <= MIN_DIFF && abs(this->size[1] - tmp[1]) <= MIN_DIFF && abs(this->size[2] - tmp[2]) <= MIN_DIFF){
        return true;
    }
    else{
        return false;
    }
}

// Przeciazenie sprawdzajace czy wektory sa rozne
template<>
bool Vector3::operator != (const Vector3 tmp) const{
    if(abs(this->size[0] - tmp[0]) > MIN_DIFF || abs(this->size[1] == tmp[1]) > MIN_DIFF || abs(this->size[2] == tmp[2]) > MIN_DIFF){
        return true;
    }
    else{
        return false;
    }
}

