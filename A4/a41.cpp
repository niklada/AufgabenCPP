#include <iostream>
#include "rational.h"
using namespace std;
int main(){
  Rational a(4,2);
  Rational b=add(4l,a);
  b.ausgabe();
}