#include "rational.h"
using namespace std;
int main(){
  Rational x(3,4);
  Rational y(6,8);
 
  x.ausgabe();
  y.ausgabe();
  if(x==y)
  cout<<"muh"<<endl;
  Rational z=x+y;
  z.ausgabe();
}