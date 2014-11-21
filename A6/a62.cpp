#include "Teilnehmer.h"
using namespace std;
int main(){
  Teilnehmer otto("Otto");
  Teilnehmer andrea("Andrea");
  Teilnehmer jens("Jens");
  Teilnehmer * const alle[]= {&otto,&andrea,&jens,0};
  otto.lerntKennen(jens);
  andrea.lerntKennen(otto);
  int i=0;
  while(alle[i]){
    cout << alle[i]->gibNamen() <<" kennt : ";
    alle[i]->druckeBekannte();
    cout<<endl;
    ++i;
  }
}