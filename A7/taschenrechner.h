#ifndef TASCHENRECHNER_H
#define TASCHENRECHNER_H
#include <string>
#include "TreeElement.h"
#include "OperatorElement.h"
#include "NumberElement.h"
class Taschenrechner{
private:
  std::string anfrage;
  int error;
  int akt;
  TreeElement* leseAusdruck();
  TreeElement* leseSummand();
  TreeElement* leseFaktor();
  void checkError();
  void leseLeerzeichen();
  char getChar();
  int getZahl();
  TreeElement* head;
  void inOrderAusgeben(TreeElement*);
public:
  Taschenrechner(std::string anfrage);
  int getAnfrage();
 
  
  
};
#endif