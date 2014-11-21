#include <iostream>
#include "IntMenge.h"
using namespace std;
int main(){
  IntMenge menge;
  menge.hinzufuegen(1);
  menge.hinzufuegen(6);
  menge.hinzufuegen(3);
  menge.hinzufuegen(4);
  menge.hinzufuegen(3);
  menge.anzeigen();
  menge.entfernen(3);
  menge.entfernen(12);
  menge.anzeigen();
  cout<< menge.getMax()<<endl;
  cout<< menge.getMin()<<endl;
  IntMenge menge2=menge;
  menge2.anzeigen();
}