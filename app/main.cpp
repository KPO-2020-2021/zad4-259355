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

#include "scena.hh"
#include "exampleConfig.h"
#include "example.h"
#include "vector.hh"
#include "Prostopadl.hh"
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

  scena sc;


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
  Vector3 arguments1[] = { vec1, vec2, vec3, vec4, vec5, vec6, vec7, vec8}; /**< inicjacja prostopadloscianu nr 1 */
  Prostopadl pro = Prostopadl(arguments1);
  double mid1[] = {75,62.5,112.5};
  pro.mid = Vector3(mid1); 
  sc.pro = Prostopadl(pro);
  Prostopadl loc;
  loc = pro - (pro.mid);
  loc.mid = Vector3(mid1);

  double argm1[] = {15,15,20};
  double argm2[] = {-10,15,20};
  double argm3[] = {15,-20,20};
  double argm4[] = {-10,-20,20};
  double argm5[] = {15,-20,10};
  double argm6[] = {-10,-20,10};
  double argm7[] = {15,15,10};
  double argm8[] = {-10,15,10};
  Vector3 vect1 = Vector3(argm1);
  Vector3 vect2 = Vector3(argm2);
  Vector3 vect3 = Vector3(argm3);
  Vector3 vect4 = Vector3(argm4);
  Vector3 vect5 = Vector3(argm5);
  Vector3 vect6 = Vector3(argm6);
  Vector3 vect7 = Vector3(argm7);
  Vector3 vect8 = Vector3(argm8);
  Vector3 arguments[] = { vect1, vect2, vect3, vect4, vect5, vect6, vect7, vect8}; /**< inicjacja prostopadloscianu nr 2 */
  Prostopadl pro2 = Prostopadl(arguments);
  double mid2[] = {75,62.5,112.5};
  pro2.mid = Vector3(mid2);
  sc.pro2 = pro2;

  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku Prostopadla

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "Prostopadl.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("../datasets/Prostopadl.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("../datasets/Prostopadl1.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("../datasets/Prostopadl.dat",PzG::RR_Punktowy,2);
  Lacze.DodajNazwePliku("../datasets/Prostopadl1.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  // Prostopadl pro;
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.UstawZakresX(-300,300);
  Lacze.UstawZakresY(-300,300);
  Lacze.UstawZakresZ(-300,300);
  const char *file;
  sc.pro.Save("../datasets/Prostopadl.dat");
  sc.pro2.Save("../datasets/Prostopadl1.dat");
  Lacze.Rysuj();
  
  cout << "Beginning" << endl;
  int  anglee = 0;
  char choice;
  
  cout << "m - menu" << endl;
  cout << "c - choose figure" << endl;
  cout << "o - turn" << endl;
  cout << "t - same turning" << endl;
  cout << "s - check length" << endl;
  cout << "r - display rotation matrix" << endl;
  cout << "w - cords" << endl;
  cout << "p - move" << endl;
  cout << "k - end" << endl;

  cout << "Choose the figure ('1', '2')" << endl;
    char fig = '_';
    while( fig != '1' && fig != '2'){
      cin >> fig;
      switch(fig){
        case '1':{
          file = "../datasets/Prostopadl.dat";
          cout << "you have chosen first one" << endl;
          pro = sc.pro;
          break;}
        case '2':{
          file = "../datasets/Prostopadl1.dat";
          cout << "you have chosen second one" << endl;
          pro = sc.pro2;
          break;}
        default:{
          cout << "Wrong option try again" << endl;
          break;}
      }
    }

  double arg[][SIZE] = {{1,0,0}, {0,1,0}, {0,0,1}};
  sc.pro.matrixtmp = Matrix3(arg);
  sc.pro2.matrixtmp = Matrix3(arg);
  Matrix3 mattemp, matturnag;
  loc.matrixtmp = Matrix3(arg);
  pro.matrixtmp = Matrix3(arg);

  while (choice != 'k'){
    char axle = '_';
    double temp1, temp2, temp3, howm;
    if(SIZE == 2){
    sc.pro.lenght2();
    temp1 = sc.pro.blen;
    temp2 = sc.pro.slen;
    temp3 = sc.pro.high;}
    Vector3 tmp;

    cout << "Your choice?  (m-menu) >" << endl;
    cin >> choice;

    switch( choice ){
      case 'o':{ 
        cout << "Choose axle ( 'x' 'y' 'z') " << endl;
        while(axle != '.'){
          cin >> axle;
            if(axle == '.'){
              break;
            }
          cin >> anglee;
        switch (axle){
            case 'x':
              pro.turn(anglee,axle,loc);
              break;
            case 'y':
              pro.turn(anglee,axle,loc);
              break;
            case 'z':
              pro.turn(anglee,axle,loc);
              break;
            case '.':
              break;
            default:
              std::cerr << "Wrong Option, try again" << std::endl;
              break;
        }
        }

        cout << "Choose how many times to turn rectangle: ";
        cin >> howm;
        Matrix3 mathowm = pro.matrixtmp;
        matturnag = pro.matrixtmp;
        for(int i = 0; i < howm-1; ++i ){
          mathowm = mathowm * matturnag;
          pro = loc * mathowm;
        }
        pro.Save(file);
        Lacze.Rysuj();

        if(SIZE == 2){
          pro.showres(temp1,temp2, temp3);
          cout << endl;}
        else if(SIZE == 3){
          pro.showres3D();
          cout << endl;
        }}
        mattemp = pro.matrixtmp;
      break;
      case 't':{
        cout << "Turn once again" << endl;
        mattemp = mattemp * matturnag;
        pro = loc * mattemp;
        pro.Save(file);
        Lacze.Rysuj();
        break;}
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
        pro.moving(tmp,file, Lacze);
        loc.mid = loc.mid + tmp;
        pro.mid = loc.mid;
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
        cout << "c - choose figure" << endl;
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

      case 'c':
        cout << "Choose the figure" << endl;
        fig = '_';
        while( fig != '1' && fig != '2'){
          cin >> fig;
          switch(fig){
            case '1':{
              file = "../datasets/Prostopadl.dat";
              cout << "you have chosen first one" << endl;
              pro = sc.pro;
              break;}
            case '2':{
              file = "../datasets/Prostopadl1.dat";
              cout << "you have chosen second one" << endl;
              pro = sc.pro2;
              break;}
            default:{
              cout << "Wrong option try again" << endl;
              break;}
          }
        }
      break;

      default:
        cout << "Wrong Option" << endl;
      break;
    }
  }

  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}
