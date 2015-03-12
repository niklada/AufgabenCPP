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
#define A4_a
#define A4_b
#define A4_c
#define A4_d

class add_formel
{
#ifdef  A4_a
// member v
public:
  vector<function<int(int)>> v;
#endif

#ifdef  A4_b
// operator+=
public:
  void operator+=(function<int(int)> f){
    v.push_back(f);
  }
#endif

#ifdef  A4_c
int eval(int x)
{
  int sum=0;
  for(function<int(int)> f:v){
    sum+=f(x);
  }
    return sum;
}
#endif

#ifdef  A4_d
// operator()
int operator()(int x){
  return eval(x);
}
#endif

};


