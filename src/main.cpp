#include <iostream>
#include <string>
#include <cmath>
#include <locale>
using namespace std;
class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  Flacon(string n,double p,double v):nom(n),pH(p),volume(v){}
  ostream& etiquette (ostream& sortie )const {
      sortie<<nom<<":"<<volume<<"mL,pH "<<pH;
      return sortie;
  }
  friend ostream& operator<<(ostream& os,const Flacon& f){
       return f.etiquette(os);
  }
  friend Flacon operator+(Flacon f,const Flacon& p){
    f.nom=f.nom+"+"+p.nom;// il s'agit de l'operation de concaténation des chaines de caractères
    f.volume+=p.volume ;
    double x,y;
    y=f.volume;
    x=((f.volume-p.volume)*pow(10.0,-f.pH)+p.volume*pow(10.0,-f.pH));
    f.pH=-log10(x/y);
    return f;
  }
  Flacon& operator+=(const Flacon& f){// l'operateur += ne prend pas friend parce qu'il est defini a l'interieur on ne fait qu'effectuer une surcharge. si l'on ajoute "friend" on devra obligatoirement mettre deuc arguments
      *this=*this+f;// "*this" represente l'instance courante dans laquelle on se trouve
      return *this;
  }

};
void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

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
