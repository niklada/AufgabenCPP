#include <iostream>
using namespace std;
int main(){
  int a=1;
  int b=10;
  int z=5;
  auto doubleAddition=[] (double a,double b,double c){
    return a+b+c;
  };
  auto inIntervall = [a,b](int c){
    if(c>=a && c<=b) return true;
    return false;
  };
  auto toMinusZ = [&](){
    z=-z;
  };
  cout<<doubleAddition(1.2,0.1,0.1)<<endl;
  cout<<inIntervall(30)<<endl;
  toMinusZ();
  cout<<z<<endl;
}