#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
using namespace std;


/***********************************************/
/* Bitte die folgenden Makros einkommentieren, */
/* so bald die entsprechende Unteraufgabe      */
/* gelöst ist !!!                              */
/***********************************************/
#define A2_a
#define A2_b
//#define A2_c
//#define A2_d
//#define A2_e

vector<string> text;

#ifdef  A2_a
void einlesen() {
  ifstream ifs;
  ifs.open("Datei.txt");
  
  while(ifs){
    string line;
    getline(ifs,line);
    if(ifs)
      text.push_back(line);
    
  }
}
#endif

#ifdef  A2_b
auto lambda1 = [] (char c){
  vector<char> v={
}
#endif

#ifdef  A2_c
int vokal_counter = 0;
... lambda2 = ....
#endif

#ifdef  A2_d
... getComp() {
}
#endif

#ifdef  A2_e
void sortieren() {
...
}
#endif
