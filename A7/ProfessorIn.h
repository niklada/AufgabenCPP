#ifndef PROF_H
#define PROF_H
#include "Person.h"
using namespace std;
class ProfessorIn: public Person{
public:
  ProfessorIn():Person("Merten","Nagel"){}
  ProfessorIn(string nn, string vn, string lehr):Person(vorname,nachname),lehrgebiet(lehr){}
  const string& getLehrgebiet(){return lehrgebiet;}
  const string toString(){return( vorname+" "+nachname+" "+lehrgebiet);}
private:
  string lehrgebiet;
  
};
#endif
