#ifndef PERSON_H
#define PERSON_H
using namespace std;
class Person{
public:
  Person(string vorname,string nachname):vorname(vorname),nachname(nachname){};
  void setNachname(string nachname);
  const string& getNachname(){return nachname;}
  void setVorname(string vorname);
  const string& getVorname(){return vorname;}
  virtual const string toString()=0;
protected:
  string vorname;
  string nachname;
};
inline const string Person::toString(){
  return (vorname+" "+nachname);
}
#endif
