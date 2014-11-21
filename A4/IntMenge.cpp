//Definition der Methoden fuer IntMenge
#include <iostream>
#include <cstddef>
#include <vector>
#include "IntMenge.h"
using namespace std;

IntMenge::IntMenge(): grosse(0){
  
}
IntMenge::IntMenge(IntMenge& andereMenge): menge(vector<int>(andereMenge.menge)), grosse(andereMenge.size()){
 
}
void IntMenge::hinzufuegen(int e1){
  if(!istMitglied(e1)){
    grosse++;
    menge.push_back(e1);
  }
  
}
void IntMenge::entfernen(int e1){
  if(istMitglied(e1)){
    menge.erase(std::remove(menge.begin(),menge.end(), e1),menge.end());
    grosse--;
  }
    
}
bool IntMenge::istMitglied(int e1){
  for(int i =0;i<size();i++){
    if(menge.at(i)==e1) return true;
  }
  return false;
}
size_t IntMenge::size(){
  return grosse;
}
void IntMenge::anzeigen(){
  for(int i=0;i<size();i++){
    cout<<menge.at(i)<<" ";
  }
  cout<< endl;
}
int IntMenge::getMax(){
  int max=0;
  if(size()>0) max=menge.at(0);
  else return max;
  for(int i=0;i<size();i++){
    if(menge.at(i)>max) max=menge.at(i);
  }
  return max;
}
int IntMenge::getMin(){
  int min =0;
  if(size()>0) min=menge.at(0);
  else return min;
  for(int i=0;i<size();i++){
    if(menge.at(i)<min) min=menge.at(i);
  }
  return min;
}
void IntMenge::loeschen(){
  menge.clear();
  grosse=0;
}
