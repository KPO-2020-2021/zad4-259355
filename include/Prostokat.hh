#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include "matrix3.hh"
#include "size.hh"
// #include "coordinates.hh"
#include "Vector3.hh"
#include <iostream>
#include <iomanip>
#include "../include/lacze_do_gnuplota.hh"
#include <unistd.h>
#include <fstream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */


class Prostokat {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  private:

  Vector3 pro [NOPOINTS];

  public:

  Prostokat(Vector3 [NOPOINTS]);             //Konstruktor klasy 

  Prostokat();                               // Konstruktor klasy
  
  double blen;

  double slen; 

  double high; 

  double lenght[3][4];

  Matrix3 matrixtmp;

  Prostokat operator * (const Matrix3 &matrix);

  Prostokat move (const Vector3 &vec);

  void moving(Vector3 &vec, const char *sNazwaPliku, PzG::LaczeDoGNUPlota Lacze);

  Prostokat operator + (const Vector3 vec2);

  double  &operator () (unsigned int row, unsigned int column);

  const double  &operator () (unsigned int row, unsigned int column) const;
    
  const Vector3 &operator () (unsigned int row) const;

  void turn(double const ang, char which, Matrix3 matrtmp);

  void turning(Prostokat &pro, const char *sNazwaPliku, double const ang, double const howm, PzG::LaczeDoGNUPlota Lacze, char which);

  Prostokat lenght2();

  Prostokat lenght3D();

  bool Save(const char *sNazwaPliku);
  
  void showres(double const temp1, double const temp2, double const temp3);
  
  void showres3D();

//   friend bool operator == (const double temp1, const double temp2);

};

std::ostream& operator << ( std::ostream &stream, const Prostokat &Pr);

std::istream& operator >> ( std::istream &stream, Prostokat &pr);

// bool operator == (const double temp1, const double temp2);

#endif
