#ifndef TASCHENRECHNER_H
#define TASCHENRECHNER_H
#include <string>
class Taschenrechner{
private:
  std::string anfrage;
  int error;
  int akt;
  int leseAusdruck();
  int leseSummand();
  int leseFaktor();
  void checkError();
  void leseLeerzeichen();
  char getChar();
  int getZahl();
public:
  Taschenrechner(std::string anfrage);
  int getAnfrage();
 
  
  
};
#endif