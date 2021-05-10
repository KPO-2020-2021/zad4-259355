#include "Prostokat.hh"
typedef Matrix<double,SIZE>Matrix3;

// /******************************************************************************
//  |  Konstruktor klasy Prostokat.                                                 |
//  |  Argumenty:                                                                |
//  |      Brak argumentow.                                                      |
//  |  Zwraca:                                                                   |
//  |      Prostokat wypelnione wartoscia 0.                                       |
//  */
Prostokat::Prostokat() {
    for (int i = 0; i < NOPOINTS; ++i) {
        for(int j = 0; j < SIZE; ++j) {
        pro[i][j] = 0;
    }
    }
}


// /******************************************************************************
//  |  Konstruktor parametryczny klasy Prostokat.                                   |
//  |  Argumenty:                                                                |
//  |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
//  |  Zwraca:                                                                   |
//  |      Prostokat wypelniona wartosciami podanymi w argumencie.                 |
//  */
Prostokat::Prostokat(Vector3 tmp[NOPOINTS]) {
    for (int i = 0; i < NOPOINTS; ++i) {
        for(int j = 0; j < SIZE; ++j) {
        pro[i][j] = tmp[i][j];
    }
    }
}

/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
double &Prostokat::operator()(unsigned int row, unsigned int column) {

    if (row >= NOPOINTS) {
        throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    if (column >= SIZE) {
        throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    return pro[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
const Vector3 &Prostokat::operator () (unsigned int row) const {

    if (row >= NOPOINTS) {
        throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    // if (column >= SIZE) {
    //     std::cout << "Error: Prostokat jest poza zasiegiem";
    //     exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    // }

    return pro[row];
}

//Przeciazenie operatora () indeksowania dla prostokata z odpowiednimi zabezpieczeniami

const double &Prostokat::operator () (unsigned int row, unsigned int column) const {

    if (row >= NOPOINTS) {
        throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    if (column >= SIZE) {
        throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    return pro[row][column];
}

//Przeciazenie operatora przyjmująca jako argument macierz i zmieniajaca wartosci wspolrzednych prostokata

Prostokat Prostokat::operator * (const Matrix3 &matrix){
    Prostokat result;
    for (int i = 0; i < NOPOINTS; ++i){
            result.pro[i] = matrix * this->pro[i];
            // if( SIZE == 3){
            // result(i,2) = matrix(0,2) * this->pro[i][0] + matrix(1,2) *  this->pro[i][1] + matrix(2,2) * this->pro[i][2];
    }
    // }
    return result;
}

//Funkcja przyjmujaca jako argument wektor i zmieniajaca wartosci wspolrzednych prostokata (przesuniecie o wektor)

Prostokat Prostokat::move(const Vector3 &vec){
    for (int i = 0; i < NOPOINTS; ++i){
        for (int j = 0; j < SIZE; ++j){
        this->pro[i][j] += vec[j];
    }}
    
    // this->Save(sNazwaPliku);
    // Lacze.Rysuj();
    return *this;
}

// Funkcja powodujaca animacje przesuniecia prostokata o wektor

void Prostokat::moving(Vector3 &vec, const char *sNazwaPliku, PzG::LaczeDoGNUPlota Lacze){

    Vector3 temp;
    temp = vec / 100.00 ;
    for(int i = 0; i < 100; ++i){
        this->move(temp);
        this->Save(sNazwaPliku);
        usleep(4000);
        Lacze.Rysuj(); 
        usleep(4000); 
    }
}

//Metoda ktora oblicza wartosci dluzszego (blen) i krotszego (slen) boku prostokata

Prostokat Prostokat::lenght2(){

   this->slen = sqrt(pow(this->pro[0][0] - this->pro[1][0],2) + pow(this->pro[0][1] - this->pro[1][1],2));
   this->blen = sqrt(pow(this->pro[0][0] - this->pro[2][0],2) + pow(this->pro[0][1] - this->pro[2][1],2));
   this->high = sqrt(pow(this->pro[0][0] - this->pro[3][0],2) + pow(this->pro[0][1] - this->pro[3][1],2));
   return *this;
}

 Prostokat Prostokat::lenght3D(){

   this->lenght[0][0] = sqrt(pow(this->pro[0][0] - this->pro[2][0],2) + pow(this->pro[0][1] - this->pro[2][1],2) + pow(this->pro[0][2] - this->pro[2][2],2));
   this->lenght[0][1] = sqrt(pow(this->pro[1][0] - this->pro[3][0],2) + pow(this->pro[1][1] - this->pro[3][1],2) + pow(this->pro[1][2] - this->pro[3][2],2)); 
   this->lenght[0][2] = sqrt(pow(this->pro[6][0] - this->pro[4][0],2) + pow(this->pro[6][1] - this->pro[4][1],2) + pow(this->pro[6][2] - this->pro[4][2],2)); 
   this->lenght[0][3] = sqrt(pow(this->pro[7][0] - this->pro[5][0],2) + pow(this->pro[7][1] - this->pro[5][1],2) + pow(this->pro[7][2] - this->pro[5][2],2)); 
   
   this->lenght[1][0] = sqrt(pow(this->pro[0][0] - this->pro[1][0],2) + pow(this->pro[0][1] - this->pro[1][1],2) + pow(this->pro[0][2] - this->pro[1][2],2));
   this->lenght[1][1] = sqrt(pow(this->pro[2][0] - this->pro[3][0],2) + pow(this->pro[2][1] - this->pro[3][1],2) + pow(this->pro[2][2] - this->pro[3][2],2)); 
   this->lenght[1][2] = sqrt(pow(this->pro[4][0] - this->pro[5][0],2) + pow(this->pro[4][1] - this->pro[5][1],2) + pow(this->pro[4][2] - this->pro[5][2],2)); 
   this->lenght[1][3] = sqrt(pow(this->pro[7][0] - this->pro[6][0],2) + pow(this->pro[7][1] - this->pro[6][1],2) + pow(this->pro[7][2] - this->pro[6][2],2)); 
   
   this->lenght[2][0] = sqrt(pow(this->pro[0][0] - this->pro[6][0],2) + pow(this->pro[0][1] - this->pro[6][1],2) + pow(this->pro[0][2] - this->pro[6][2],2));
   this->lenght[2][1] = sqrt(pow(this->pro[2][0] - this->pro[4][0],2) + pow(this->pro[2][1] - this->pro[4][1],2) + pow(this->pro[2][2] - this->pro[4][2],2)); 
   this->lenght[2][2] = sqrt(pow(this->pro[1][0] - this->pro[7][0],2) + pow(this->pro[1][1] - this->pro[7][1],2) + pow(this->pro[1][2] - this->pro[7][2],2)); 
   this->lenght[2][3] = sqrt(pow(this->pro[0][0] - this->pro[6][0],2) + pow(this->pro[0][1] - this->pro[6][1],2) + pow(this->pro[0][2] - this->pro[6][2],2)); 
   return *this;
}

//Przeciazenie operatora przesuniecia bitowego w lewo
//Pozwala w odpowiedni sposob wyswietlic wspolrzedne prostokata 

std::ostream& operator << ( std::ostream &stream, const Prostokat &Pr){

for (int i = 0; i < NOPOINTS; ++i){
    if( i%2 == 0 ){
            stream << std::endl;
        }
    stream << std::setw(16) << std::fixed << std::setprecision(10) << Pr(i) << std::endl;
    }
    stream << std::endl;
    stream << std::setw(16) << std::fixed << std::setprecision(10) << Pr(0) << std::endl;
    stream << std::setw(16) << std::fixed << std::setprecision(10) << Pr(1) << std::endl;
    return stream;
}

std::istream& operator >> ( std::istream &stream, Prostokat &pr){

char tmp;
double num;
double arg[][SIZE] = {{1,0,0}, {0,1,0}, {0,0,1}};
Matrix3 matrixtmp = Matrix3(arg);
    while(tmp != '.'){
        stream >> tmp;
        if(tmp == '.'){
            break;
        }
        if(stream.fail())
            return stream;
        stream >> num;
        switch (tmp){
            case 'x':
                pr.turn(num,tmp,matrixtmp);
                break;
            case 'y':
                pr.turn(num,tmp,matrixtmp);
                break;
            case 'z':
                pr.turn(num,tmp,matrixtmp);
                break;
            case '.':
                break;
            default:
                std::cerr << "Wrong Option, try again" << std::endl;
                break;
        }
    }
    return stream;
}

//Funkcja przyjmujaca odpowiednio temp1 - dlugosc dluzszego boku oraz temp2 - dlugosc krotszego boku trojkata (na poczatku)
//Porownuje ona dlugosci bokow po operacji przesuniecia i obrotu

void Prostokat::showres(double const temp1, double const temp2, double const temp3){

    this->lenght2();

    if((temp2 - this->slen) < MIN_DIFF){
       std::cout << ":) Shorter sides are equal." << std::endl;
       std::cout << "Before operation: " << temp2 << std::endl;
       std::cout << "After operation: " << this->slen << std::endl;
   } 
   else{
       std::cout << ":( Shorter sides are not equal." << std::endl;
       std::cout << "Before operation: " << temp2 << std::endl;
       std::cout << "After operation: " << this->slen << std::endl; 
   }
   std::cout << std::endl;
   if((temp1 - this->blen) < MIN_DIFF){
       std::cout << ":) Longer sides are equal." << std::endl;
       std::cout << "Before operation: " << temp1 << std::endl;
       std::cout << "After operation: " << this->blen << std::endl;
   } 
   else{
       std::cout << ":( Longer sides are not equal." << std::endl;
       std::cout << "Before operation: " << temp1 << std::endl;
       std::cout << "After operation: " << this->blen << std::endl; 
   }
   if(SIZE == 3){
   std::cout << std::endl;
   if((temp1 - this->high) < MIN_DIFF){
       std::cout << ":) High sides are equal." << std::endl;
       std::cout << "Before operation: " << temp3 << std::endl;
       std::cout << "After operation: " << this->high << std::endl;
   } 
   else{
       std::cout << ":( High sides are not equal." << std::endl;
       std::cout << "Before operation: " << temp3 << std::endl;
       std::cout << "After operation: " << this->high << std::endl; 
   }}
}



void Prostokat::showres3D(){

    std::cout << std::setw(8) << std::fixed << std::setprecision(7);
    this->lenght3D();
    if((this->lenght[0][0] - this->lenght[0][1]) < MIN_DIFF && (this->lenght[0][0] - this->lenght[0][2]) < MIN_DIFF && (this->lenght[0][0] - this->lenght[0][3]) < MIN_DIFF ){
       std::cout << ":) Longest sides are equal." << std::endl;
       for(int i = 0; i < 4; ++i){
           std::cout << this->lenght[0][i] << std::endl;
       }
       std::cout << std::endl;
   } 
   else{
       std::cout << ":( Longest sides are not equal." << std::endl;
       for(int i = 0; i < 4; ++i){
           std::cout << this->lenght[0][i] << std::endl;
       }
       std::cout << std::endl;
   }
   if((this->lenght[1][0] - this->lenght[1][1]) < MIN_DIFF && (this->lenght[1][0] - this->lenght[1][2]) < MIN_DIFF && (this->lenght[1][0] - this->lenght[1][3]) < MIN_DIFF ){
       std::cout << ":) Height sides are equal." << std::endl;
       for(int i = 0; i < 4; ++i){
           std::cout << this->lenght[1][i] << std::endl;
       }
       std::cout << std::endl;
   } 
   else{
       std::cout << ":( Height sides are not equal." << std::endl;
       for(int i = 0; i < 4; ++i){
           std::cout << this->lenght[1][i] << std::endl;
       }
       std::cout << std::endl;
   }
   if((this->lenght[2][0] - this->lenght[2][1]) < MIN_DIFF && (this->lenght[2][0] - this->lenght[2][2]) < MIN_DIFF && (this->lenght[2][0] - this->lenght[2][3]) < MIN_DIFF ){
       std::cout << ":) Shorter sides are equal." << std::endl;
       for(int i = 0; i < 4; ++i){
           std::cout << this->lenght[2][i] << std::endl;
       }
       std::cout << std::endl;
   } 
   else{
       std::cout << ":( Shorter sides are not equal." << std::endl;
       for(int i = 0; i < 4; ++i){
           std::cout << this->lenght[2][i] << std::endl;
       }
       std::cout << std::endl;
   }
}

//Funkcja przyjmujaca kat o ktory obracamy prostokat wokol punktu (0,0)
//Zmienia wartosci wspolrzednych prostokata o dany kata

void Prostokat::turn(double const ang, char which, Matrix3 matrtmp){
    Matrix3 matrixx,matrixy,matrixz;
    if(SIZE != 3){
        matrixx.toradians();
        *this = *this * matrixx.after_x();
    }
    else{
        if( which == 'x'){
            matrixx.angle = ang;
            matrixx.toradians();
            *this = *this * matrixx.after_x();
            // this->matrixtmp = matrix.after_x() * this->matrixtmp;
            matrtmp = matrixx.after_x() * matrtmp;
            // std::cout << this->matrixtmp << std::endl;
        }
        else if( which == 'y'){
            matrixy.angle = ang;
            matrixy.toradians();
            // std::cout << matrix.after_y() << std::endl;
            // std::cout << this->matrixtmp << std::endl;
            *this = *this * matrixy.after_y();
            // this->matrixtmp = matrix.after_y() * this->matrixtmp;
            matrtmp = matrixy.after_y() * matrtmp;
        }
        else if( which == 'z'){
            matrixz.angle = ang;
            matrixz.toradians();
            *this = *this * matrixz.after_z();
            // this->matrixtmp = matrix.after_z() * this->matrixtmp;
            matrtmp = matrixz.after_x() * matrtmp;
        }
        else{
            std::cout << "Wrong option operation dumped" << std::endl;
    }} 
    this->matrixtmp = matrtmp; 
}

//Funkcja zapisu wspolrzednych bokow do pliku

bool Prostokat::Save(const char *sNazwaPliku)
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  StrmPlikowy << *this << std::endl;

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

//Funkcja wykonujaca animacje obrotu prostokata o dany kat wykonuje sie dla mniej niz 5 powtorzen

void Prostokat::turning(Prostokat &pro, const char *sNazwaPliku, double const ang, double const howm, PzG::LaczeDoGNUPlota Lacze, char which)
{
double arg[][SIZE] = {{1,0,0}, {0,1,0}, {0,0,1}};
Matrix3 matrixtmp = Matrix3(arg);
  if(howm < 5){
    for(int i = 0; i < howm; ++i){
        for(int k = 0; k < abs(ang); ++k){
            pro.turn(ang/abs(ang), which, matrixtmp);
            pro.Save(sNazwaPliku);
            usleep(4000);
            Lacze.Rysuj(); 
            usleep(4000);
            }
        }
    }
  else{
      pro.turn(ang, which, matrixtmp);
      pro.Save(sNazwaPliku);
      Lacze.Rysuj();
  }
}

// bool operator == (const double temp1,const double temp2){
//     if(abs(temp1 - temp2) < MIN_DIFF){
//         return true;
//     }
//     else{
//         return false;
//     }
// }
