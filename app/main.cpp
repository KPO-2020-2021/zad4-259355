// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
#include "example.h"
#include "Vector3.hh"
#include "Prostokat.hh"
#include "matrix.hh"
#include "../include/lacze_do_gnuplota.hh"

using namespace std;

// template <typename T, typename U>
// void Wymnoz( T Arg1, U (&Arg2_Tab)[4]){
//   for(U &Mnoznik : Arg2_Tab) Mnoznik = Arg1 * Mnoznik;
// }

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */

int main() {
  std::cout << "Project Rotation 3D based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << std::endl;

  double arg1[] = {100,100,150};
  double arg2[] = {50,100,150};
  double arg3[] = {100,25,150};
  double arg4[] = {50,25,150};
  double arg5[] = {100,25,75};
  double arg6[] = {50,25,75};
  double arg7[] = {100,100,75};
  double arg8[] = {50,100,75};
  Vector3 vec1 = Vector3(arg1);
  Vector3 vec2 = Vector3(arg2);
  Vector3 vec3 = Vector3(arg3);
  Vector3 vec4 = Vector3(arg4);
  Vector3 vec5 = Vector3(arg5);
  Vector3 vec6 = Vector3(arg6);
  Vector3 vec7 = Vector3(arg7);
  Vector3 vec8 = Vector3(arg8);
  Vector3 arguments1[] = { vec1, vec2, vec3, vec4, vec5, vec6, vec7, vec8};
  Prostokat pro = Prostokat(arguments1);

  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.UstawZakresX(-300,300);
  Lacze.UstawZakresY(-300,300);
  Lacze.UstawZakresZ(-300,300);
  pro.Save("../datasets/prostokat.dat");
  Lacze.Rysuj();

  cout << "Beginning" << endl;
  double temp1, temp2, temp3, howm;
  char choice;
  if(SIZE == 2){
  pro.lenght2();
  temp1 = pro.blen;
  temp2 = pro.slen;
  temp3 = pro.high;}
  Vector3 tmp;
  
  cout << "m - menu" << endl;
  cout << "o - turn" << endl;
  cout << "t - same turning" << endl;
  cout << "s - check length" << endl;
  cout << "r - display rotation matrix" << endl;
  cout << "w - cords" << endl;
  cout << "p - move" << endl;
  cout << "k - end" << endl;

  while (choice != 'k'){
    cout << "Your choice?  (m-menu) >" << endl;
    cin >> choice;

    switch( choice ){
      case 'o': 
        cout << "Choose axle ( 'x' 'y' 'z') " << endl;
        cin >> pro;
        cout << "Choose how many times to turn rectangle: ";
        cin >> howm;

        // pro.turning(pro, "../datasets/prostokat.dat", ang, howm, Lacze, which);
        for(int i = 0; i < howm-1; ++i ){
        pro = pro * pro.matrixtmp;
        pro.Save("../datasets/prostokat.dat");
        }
        // std::cout << pro << std::endl;
        pro.Save("../datasets/prostokat.dat");
        Lacze.Rysuj();

        if(SIZE == 2){
        pro.showres(temp1,temp2, temp3);
        cout << endl;}
        else if(SIZE == 3){
          pro.showres3D();
          cout << endl;
        }
      break;
      case 't':
        cout << "Turn once again" << endl;
        pro = pro * pro.matrixtmp;
        pro.Save("../datasets/prostokat.dat");
        Lacze.Rysuj();
        break;
      case 'r':
        cout << "Display rotation matrix" << endl;
        cout << pro.matrixtmp << endl;
        break;
      case 's':
        cout << "Checking the length of sides" << endl;
        pro.showres3D();
        break;
      case 'p': 
        cout << "Vector to move: ";
        cin >> tmp;
        pro.moving(tmp,"../datasets/prostokat.dat", Lacze);

        if(SIZE == 2){
          pro.showres(temp1,temp2, temp3);
          cout << endl;}
        else if(SIZE == 3){
          pro.showres3D();
          cout << endl;
        }
      break;

      case 'w': 
        cout << "Cooridantes" << endl;
        cout << pro << endl;
        break;
      case 'm': 
        cout << "m - menu" << endl;
        cout << "o - turn" << endl;
        cout << "t - same turning" << endl;
        cout << "s - check length" << endl;
        cout << "r - display rotation matrix" << endl;
        cout << "w - cords" << endl;
        cout << "p - move" << endl;
        cout << "k - end" << endl;
      break;

      case 'k': 
        cout << "The end" << endl;
      break;

      default:
        cout << "Wrong Option" << endl;
      break;
    }
  }

  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}
