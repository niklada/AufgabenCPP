#include <iostream>
#include <string>
#include <cstdlib>
#include "taschenrechner.h"
using namespace std;
Taschenrechner::Taschenrechner(string anfrage): anfrage(anfrage),error(0),akt(0),head(nullptr){
  
}
int Taschenrechner::getAnfrage(){
  head=leseAusdruck();
  inOrderAusgeben(head);
  cout<<endl;
  return head->evaluate(); 
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
TreeElement* Taschenrechner::leseAusdruck(){
  error=0;
  TreeElement* lhs=leseSummand(); 
  OperatorElement *tmp=new OperatorElement(nullptr,nullptr,Operator::ADD);
  leseLeerzeichen();
  checkError();
  while((anfrage[akt])=='+'||(anfrage[akt])=='-'){
    
    char c;
    c=getChar();
    TreeElement* rhs=leseAusdruck();
    checkError();
    if(c=='+')
    tmp=new OperatorElement(lhs,rhs,Operator::ADD);
    else tmp=new OperatorElement(lhs,rhs,Operator::SUB);
    
    leseLeerzeichen();
  }
  
  if(tmp->left!=nullptr){
    return tmp;
  }
  else return lhs;
}
TreeElement* Taschenrechner::leseSummand(){
  OperatorElement* tmp=new OperatorElement(nullptr,nullptr,Operator::ADD);
  TreeElement* lhs=leseFaktor();
  checkError();
  leseLeerzeichen();
  while((anfrage[akt])=='*'||(anfrage[akt])=='/'){
    char c;
    c=getChar();
    TreeElement* rhs =leseSummand();
    checkError();
    if(c=='*') tmp=new OperatorElement(lhs,rhs,Operator::MULT);
    else tmp=new OperatorElement(lhs,rhs,Operator::DIV);
    leseLeerzeichen();
  }
  if(tmp->left!=nullptr)
  return tmp;
  else return lhs;
}
TreeElement* Taschenrechner::leseFaktor(){
  leseLeerzeichen();
  NumberElement* result=new NumberElement(1);
  
  if((anfrage[akt])=='-'||(anfrage[akt])=='+'){
    char c;
    c=getChar();
    result=new NumberElement(leseFaktor()->evaluate());
    checkError();
    if(c=='-') result=new NumberElement(-result->evaluate());
  }else{
    char c;
    
    if(isdigit(anfrage[akt])){
      result=new NumberElement(getZahl());  
    }else{
      c=getChar();
      if(c=='('){
	TreeElement *result2=leseAusdruck();
	checkError();
	leseLeerzeichen();
	c=getChar();
	
	if(c!=')') error=1;
	return result2;
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
void Taschenrechner::inOrderAusgeben(TreeElement* head){
  //Wenn das zutrifft, dann ist head eine zahl
  if(head->left!=nullptr){
    if(head->ausgeben()!="*"&&head->ausgeben()!="/")cout<< "(";
    inOrderAusgeben(head->left);
    cout<<head->ausgeben();
    inOrderAusgeben(head->right);
    if(head->ausgeben()!="*"&&head->ausgeben()!="/")cout<< ")";
  }
  else cout<<head->ausgeben();
}