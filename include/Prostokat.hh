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

/**
 * \brief Klasa Prostopadloscianu
 * 
 * Klasa pozwalajaca operowac na wierzcholkach prostopadloscianu 
 * 
 */
 

class Prostokat {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  private:

  Vector3 pro [NOPOINTS]; /**< Tablica Wektorow 3D (Wierzcholkow o trzech skladowych) */

  public:

  Prostokat(Vector3 [NOPOINTS]);             //Konstruktor klasy 

  Prostokat();                               // Konstruktor klasy
  
  double blen;  /**< dlugosc dluzszego boku prostopadloscianu */

  double slen;  /**< dlugosc krotszego boku prostopadloscianu */

  double high;  /**< dlugosc wysokosci boku prostopadloscianu */

  double lenght[3][4];  /**< tablica dlugosci poszczegolnych krawedz prostopadloscianu */

  Matrix3 matrixtmp;  /**< Macierz obrotu */

  Prostokat operator * (const Matrix3 &matrix); // Przeciazenie operatora mnozenia wierzcholkow prostokata razy macierz

  Prostokat move (const Vector3 &vec);  //Metoda przesuniecia prostopadloscianu o wektor

  void moving(Vector3 &vec, const char *sNazwaPliku, PzG::LaczeDoGNUPlota Lacze); //Animacja przesuniecia

  Prostokat operator + (const Vector3 vec2);  //Przeciazenie operatora dodawania wektora do wierzcholkow prostopadloscianu

  //Odpowiednie operatory indeksowania i poruszania sie po wierzcholkach prostopadloscianu

  double  &operator () (unsigned int row, unsigned int column); 

  const double  &operator () (unsigned int row, unsigned int column) const;
    
  const Vector3 &operator () (unsigned int row) const;

  //Koniec

  void turn(double const ang, char which);  //Metoda obrotu prostopadloscianu o dany kat i os

  void turning(Prostokat &pro, const char *sNazwaPliku, double const ang, double const howm, PzG::LaczeDoGNUPlota Lacze, char which);   //Animacja obrotu Prostokata2D

  Prostokat lenght2();  //Metoda obliczajaca dlugosc bokow prostokata2D

  Prostokat lenght3D(); //Metoda obliczajaca dlugosc bokow prostopadloscianu

  bool Save(const char *sNazwaPliku); //Metoda zapisujaca wierzcholki do pliku
  
  void showres(double const temp1, double const temp2, double const temp3); //Metoda wyswietlajaca i porownujaca dlugosci bokow
  
  void showres3D(); //Metoda wyswietlajaca oraz porownujaca dlugosci bokow prostopadloscianu

//   friend bool operator == (const double temp1, const double temp2);

};

std::ostream& operator << ( std::ostream &stream, const Prostokat &Pr); //Operator wyswietlania wierzcholkow

// bool operator == (const double temp1, const double temp2);

#endif
