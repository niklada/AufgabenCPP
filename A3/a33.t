#ifndef BETRAG_T
#define BETRAG_T
#include <iostream>
#include <cstdlib>
using namespace std;
template<typename T>
T betrag(T s){
  if(s>0) return s;
  else return -s;
}
template<>
char betrag(char s){
  cout<<"Not able to build abs vor char"<<endl;
  exit(1);
}
template<>
bool betrag(bool s){
  cout<<"Not able to build abs vor boolean"<<endl;
  exit(1);
}
#endif