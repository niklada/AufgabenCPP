#include "Teilnehmer.h"
#include <algorithm>
using namespace std;
int idCounter=0;
Teilnehmer::Teilnehmer(string name): name(name),bekannte(0),id(idCounter++) {
}
string Teilnehmer::gibNamen(){
  return name;
}

void Teilnehmer::lerntKennen(Teilnehmer &t){
  if(&t==this) return;
  if((std::find(bekannte.begin(), bekannte.end(), &t))!=bekannte.end()){
    return;
  }else{
    //Wenn man mit pointern arbeitet, kann es sein dass der pointer auf nichts zeigt wenn man den speicher freigibt
    //Man kann sich entweder nur den namen der bekannte speichern, dann kan man allerdings nciht zwei gleiche unterscheiden 
    //oder man bastelt sich aus der id und dem namen was zusammen und kann gleiche namen unterscheiden aufgrund der id
    bekannte.push_back(&t);
    t.lerntKennen((*this));
  }
}
void Teilnehmer::druckeBekannte(){
    for(vector<Teilnehmer *>::iterator iter=bekannte.begin();iter!=bekannte.end();++iter){
      cout<<(*iter)->gibNamen()<<" ";
    }
  
}