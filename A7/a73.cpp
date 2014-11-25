#include <iostream>
#include "taschenrechner.h"
using namespace std;
int main(){
  cout<<"geben Sie einen Ausdruck ein und drucken sie enter"<<endl;
  string eingabe;
  cin>>eingabe;
  Taschenrechner tr(eingabe);
 cout<< tr.getAnfrage()<<endl;
}