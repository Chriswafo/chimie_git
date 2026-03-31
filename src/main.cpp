#include <iostream>
#include <string>
#include <cmath>
#include <locale>
using namespace std;
int main()
{
  setlocale(LC_ALL,"");
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 800.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;

}
