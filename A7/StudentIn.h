#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
using namespace std;
class StudentIn :public Person{
public:
  StudentIn():Person("Patrick","Derichs"){}
  StudentIn(string nach,string vor, string matr):Person(vor,nach),matrikel(matr){}
  const string& getMatrikel(){return matrikel;}
  const string toString(){return (vorname+ " "+nachname+" "+matrikel);}
private:
  string matrikel;
  
};

#endif