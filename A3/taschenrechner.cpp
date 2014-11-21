#include <iostream>
#include <string>
#include <cstdlib>
#include "taschenrechner.h"
using namespace std;
Taschenrechner::Taschenrechner(string anfrage): anfrage(anfrage),error(0),akt(0){
  
}
int Taschenrechner::getAnfrage(){
  return leseAusdruck(); 
}
char Taschenrechner::getChar(){
  akt++;
  return anfrage[akt-1];
}


void Taschenrechner::leseLeerzeichen(){
  char c;
  while(anfrage[akt]==' ') c=getChar();
}
void Taschenrechner::checkError(){
  if(error==1){
    cout<<"Fehler im Format!"<<endl;
    exit(1);
  }
}
int Taschenrechner::leseAusdruck(){
  error=0;
  int lhs=leseSummand();  
  
  leseLeerzeichen();
  checkError();
  while((anfrage[akt])=='+'||(anfrage[akt])=='-'){
    char c;
    c=getChar();
    int rhs=leseSummand();
    checkError();
    if(c=='+')
    lhs+=rhs;
    else lhs-=rhs;
    leseLeerzeichen();
  }
  return lhs; 
}
int Taschenrechner::leseSummand(){
  int lhs=leseFaktor();
  checkError();
  leseLeerzeichen();
  while((anfrage[akt])=='*'||(anfrage[akt])=='/'){
    char c;
    c=getChar();
    int rhs =leseFaktor();
    checkError();
    if(c=='*') lhs*=rhs;
    else lhs/=rhs;
    leseLeerzeichen();
  }
  return lhs;
}
int Taschenrechner::leseFaktor(){
  leseLeerzeichen();
  int result;
  
  if((anfrage[akt])=='-'||(anfrage[akt])=='+'){
    char c;
    c=getChar();
    result=leseFaktor();
    checkError();
    if(c=='-') result=-result;
  }else{
    char c;
    
    if(isdigit(anfrage[akt])){
      result=getZahl();
    }else{
      c=getChar();
      if(c=='('){
	result=leseAusdruck();
	checkError();
	leseLeerzeichen();
	c=getChar();
	if(c!=')') error=1;
      }else error=1;
    }
  }
  return result;
}
int Taschenrechner::getZahl(){
  int zahler=1;
  int ruck=0;
  while(isdigit(anfrage[akt])){
    ruck*=zahler;
    ruck+=anfrage[akt]-'0';
    zahler*=10;
    akt++;
  }
  return ruck;
}