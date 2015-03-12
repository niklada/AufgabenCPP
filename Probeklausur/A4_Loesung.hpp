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
  public:
#ifdef  A4_a
    vector< function<int(int)> > v;
#endif

#ifdef  A4_b
  void operator+= (function<int(int)> f) {
      v.push_back(f);
  }
#endif

#ifdef  A4_c
int eval(int p)
{
    int res = 0;
    for (auto f : v) res += f(p); 
    return res;
}
#endif

#ifdef  A4_d
int operator() (int p) {
    return eval(p);
}
#endif

};


