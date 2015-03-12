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
#define A2_c
#define A2_d
#define A2_e

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
auto lambda1 = [](char a){
  vector<char> v={'a','e','i','o','u','A','E','I','O','U'};
  for(char b:v){
    if(b==a) return true;
  }
  return false;
};
#endif

#ifdef  A2_c
int vokal_counter = 0;
auto lambda2 = [](string s){
  int c=0;
  for(unsigned int i=0;i<s.size();i++){
    if(lambda1(s[i])) c++;
  }
  vokal_counter+=c;
  return c;
};

#endif

#ifdef  A2_d
function<bool(string,string)> getComp() {
  function<bool(string,string)> f = [](string s,string t){
    return(lambda2(s)<lambda2(t));
  };
  return f;
}
#endif

#ifdef  A2_e
void sortieren() {
  sort(text.begin(),text.end(),getComp());
}
#endif
