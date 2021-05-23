#include "Prostopadl.hh"

/******************************************************************************
 |  Konstruktor klasy Prostopadl.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Prostopadl wypelnione wartoscia 0.                                       |
 */
Prostopadl::Prostopadl() {
    for (int i = 0; i < NOPOINTS; ++i) {
        for(int j = 0; j < SIZE; ++j) {
        pro[i][j] = 0;
    }
    }
}


/**
 * Metoda przyjmujaca jeden argument pozwalajaca poruszac sie po tablicy wierzcholkow
 * @param tablica wektorow 3D
 * @return nothing
 */ 
Prostopadl::Prostopadl(Vector3 tmp[NOPOINTS]) {
    for (int i = 0; i < NOPOINTS; ++i) {
        for(int j = 0; j < SIZE; ++j) {
        pro[i][j] = tmp[i][j];
    }
    }
}

/**
 * Przeciazenie operatora indeksowania pilnujaca czy nie wychodzi poza zakres
 * Przyjmuje dwa argument: 
 * @param int numer wiersza
 * @param int numer kolumny 
 * @return tablica wierzcholkow
 */ 
double &Prostopadl::operator()(unsigned int row, unsigned int column) {

    if (row >= NOPOINTS) {
        throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    if (column >= SIZE) {
        throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    return pro[row][column];
}


/**
 * Funktor Wektora (const) pilnujacy czy nie wychodzimy poza tablice wektora
 * @param int numer wiersza
 * @return wektor
 */ 
const Vector3 &Prostopadl::operator () (unsigned int row) const {

    if (row >= NOPOINTS) {
        throw std::out_of_range("Error: Vector jest poza zasiegiem");
    }

    // if (column >= SIZE) {
    //     std::cout << "Error: Prostopadl jest poza zasiegiem";
    //     exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    // }

    return pro[row];
}

/**
 * Przeciazenie operatora () (const) indeksowania dla Prostopadla z odpowiednimi zabezpieczeniami
 * @param int numer wiersza
 * @param int numer kolumny 
 * @return Tablica wierzcholkow
 */ 
const double &Prostopadl::operator () (unsigned int row, unsigned int column) const {

    if (row >= NOPOINTS) {
        throw std::out_of_range("Error: Prostopadloscian jest poza zasiegiem");
    }

    if (column >= SIZE) {
        throw std::out_of_range("Error: Prostopadloscian jest poza zasiegiem");
    }

    return pro[row][column];
}

/**
 * Przeciazenie operatora mnozenia wierzcholkow razy macierz  
 * @param const macierz 3D
 * @return Prostopadloscian result
 */ 
Prostopadl Prostopadl::operator * (const Matrix3 &matrix){
    Prostopadl result;
    for (int i = 0; i < NOPOINTS; ++i){
        result.pro[i] = (matrix * this->pro[i]) + this->mid;
    }
    result.matrixtmp = this->matrixtmp;
    result.angles = this->angles;
    return result;
}

/**
 * Przeciazenie operatora mnozenia wierzcholkow razy macierz  
 * @param const macierz 4D
 * @return Prostopadloscian result
 */ 
Prostopadl Prostopadl::operator * (const Matrix<double,4> &matrix){
    Prostopadl result;
    Matrix3 matrtmp;
    Vector3 vectmp;
    for( int i = 0; i < 3; ++i){
        vectmp[i] = matrix(3,i);
        for( int j = 0; j < 3; ++j){
            matrtmp(i,j) = matrix(i,j);
        }
    }
    for (int i = 0; i < NOPOINTS; ++i){
        result.pro[i] = (matrtmp * this->pro[i]) + this->mid;
    }
    for (int i = 0; i < NOPOINTS; ++i){
        for( int j = 0; j < 3; ++j){
            result.pro[i][j] = this->pro[i][j] + vectmp[j];
        }}
    result.matrixtmp = this->matrixtmp;
    result.angles = this->angles;
    return result;
}

/**
 * Funkcja przyjmujaca jako argument wektor i zmieniajaca wartosci wspolrzednych Prostopadla (przesuniecie o wektor)
 * @param const Wektor 3D
 * @return Prostopadloscian 
 */ 
Prostopadl Prostopadl::move(const Vector3 &vec){
    for (int i = 0; i < NOPOINTS; ++i){
        for (int j = 0; j < SIZE; ++j){
        this->pro[i][j] += vec[j];
    }}
    return *this;
}

/**
 * Funkcja powodujaca animacje przesuniecia Prostopadla o wektor
 * @param referencja Wektor 3D vec
 * @param const char pointer sNazwaPliku
 * @param LaczeDoGnuplota 
 */ 
void Prostopadl::moving(Vector3 &vec, const char *sNazwaPliku, PzG::LaczeDoGNUPlota Lacze){

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

/**
 * Metoda ktora oblicza wartosci dluzszego (blen) i krotszego (slen) boku Prostopadla
 * @return Prostopadloscian
 */ 
Prostopadl Prostopadl::lenght2(){

   this->slen = sqrt(pow(this->pro[0][0] - this->pro[1][0],2) + pow(this->pro[0][1] - this->pro[1][1],2));
   this->blen = sqrt(pow(this->pro[0][0] - this->pro[2][0],2) + pow(this->pro[0][1] - this->pro[2][1],2));
   this->high = sqrt(pow(this->pro[0][0] - this->pro[3][0],2) + pow(this->pro[0][1] - this->pro[3][1],2));
   return *this;
}

/**
 * Metoda porownujaca boki prostopadloscianu 
 * @return Prostopadloscian
 */ 
 Prostopadl Prostopadl::lenght3D(){

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

/**
 * Przeciazenie operatora przesuniecia bitowego w lewo
 * Pozwala w odpowiedni sposob wyswietlic wspolrzedne Prostopadla  
 * @param strumien wejsciowy stream
 * @param referencja const Prostopadloscian Pr
 * @return strumien wejsciowy stream
 */ 
std::ostream& operator << ( std::ostream &stream, const Prostopadl &Pr){

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

/**
 * Funkcja Void przyjmujaca odpowiednio temp1 - dlugosc dluzszego boku oraz temp2 - dlugosc krotszego boku trojkata (na poczatku)
 * Porownuje ona dlugosci bokow po operacji przesuniecia i obrotu
 * @param double const temp1 - dlugosc dluzszego boku
 * @param double const temp2 - dlugosc krotszego boku 
 * @param double const temp3 - dlugosc wysokosci
 */
void Prostopadl::showres(double const temp1, double const temp2, double const temp3){

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

/**
 * Metoda wyswietlania i porownywania dlugosci bokow prostopadloscianu      
 * @return Prostopadloscian wypelniony wartoscia 0
 */
void Prostopadl::showres3D(){

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

/**
 * Funkcja Void przyjmujaca kat o ktory obracamy Prostopadl wokol punktu (0,0)
 * Zmienia wartosci wspolrzednych Prostopadla o dany kata 
 * @param double const ang - kat
 * @param char which - os 
 */
void Prostopadl::turn(double const ang, char which, Prostopadl &loc){
    Matrix3 matrixx,matrixy,matrixz;
    double anglx,angly,anglz;
    if(SIZE != 3){
        matrixx.toradians();
        *this = *this * matrixx.after_x();
    }
    else{
        if( which == 'x'){

            this->angles[0] += ang;
            matrixx.angle = ang;
            anglx = this->angles[0];

            matrixx.toradians();
            this->matrixtmp = this->matrixtmp * matrixx.after_x();

            this->angles[0] = anglx;
        }
        else if( which == 'y'){

            this->angles[1] += ang;
            matrixy.angle = ang;  
            angly = this->angles[1];          
            
            matrixy.toradians();
            this->matrixtmp = this->matrixtmp * matrixy.after_y();

            this->angles[1] = angly;

        }
        else if( which == 'z'){

            this->angles[2] += ang;
            matrixz.angle = ang;
            anglz = this->angles[2];

            matrixz.toradians();
            this->matrixtmp = this->matrixtmp * matrixz.after_z();

            this->angles[2] = anglz;
        }
        else{
            std::cout << "Wrong option operation dumped" << std::endl;
    }} 
    loc.matrixtmp = matrixtmp;
    loc.angles = angles;
    *this = loc * matrixtmp;
}

/**
 * Funkcja zapisu wspolrzednych bokow do pliku 
 * @param const char pointer sNazwaPliku
 * @return wartosc zwracana funkcji StrmPlikowy.fail()
 */
bool Prostopadl::Save(const char *sNazwaPliku)
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

/**
 * Funkcja wykonujaca animacje obrotu Prostopadla o dany kat wykonuje sie dla mniej niz 5 powtorzen
 * @param referencja Protokat pro
 * @param const char pointer sNazwaPlikowy
 * @param double const ang - kat
 * @param double const howm - ile razy obrocic
 * @param LaczeDoGnuplota
 * @param char which - os
 */
void Prostopadl::turning(Prostopadl &pro, const char *sNazwaPliku, double const ang, double const howm, PzG::LaczeDoGNUPlota Lacze, char which)
{
  Prostopadl loc;  
  if(howm < 5){
    for(int i = 0; i < howm; ++i){
        for(int k = 0; k < abs(ang); ++k){
            pro.turn(ang/abs(ang), which,loc);
            pro.Save(sNazwaPliku);
            usleep(4000);
            Lacze.Rysuj(); 
            usleep(4000);
            }
        }
    }
  else{
      pro.turn(ang, which,loc);
      pro.Save(sNazwaPliku);
      Lacze.Rysuj();
  }
}

bool Prostopadl::operator == (const Prostopadl &Pr){
    int k = 0;
    for(int i = 0; i < NOPOINTS; ++i){
    if(Pr(i) == this->pro[i])
        k++;
    }
    if(k == 8){
        return true;
    }
    else{
        return false;
    }
}

Prostopadl Prostopadl::operator + (const Vector3 vec2){
    for (int i = 0; i < NOPOINTS; ++i){
        for (int j = 0; j < SIZE; ++j){
            this->pro[i][j] = this->pro[i][j] + vec2[j];
        }}
    return *this;
}

Prostopadl Prostopadl::operator - (const Vector3 vec2){
    for (int i = 0; i < NOPOINTS; ++i){
        for (int j = 0; j < SIZE; ++j){
            this->pro[i][j] = this->pro[i][j] - vec2[j];
        }}
    return *this;
}


