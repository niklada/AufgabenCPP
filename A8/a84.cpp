#include <iostream>
#include "meinstring.h"
using namespace std;
int main(){
  MeinString h("Haallllooooooo");
  MeinString b;
  b=h;
  cout<<(b.c_str())<<endl;
  cout<<b[1]<<endl;
  cout<<b<<endl;
}
