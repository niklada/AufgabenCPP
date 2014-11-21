//auch 7.2
#include <iostream>
using namespace std;
#include "ProfessorIn.h"
#include "StudentIn.h"
#include <vector>
#include <typeinfo>
int main(){
  vector<Person *> personen;
  
  personen.push_back(new StudentIn("Derichs","Patrick","657565"));
  cout<<(*personen.at(0)).toString();
  StudentIn dummu;
  if(typeid((*personen.at(0))).name()==typeid(dummu).name())
    cout<<(dynamic_cast<StudentIn*>(personen.at(0)))->getMatrikel();
  
}