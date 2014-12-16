#include <iostream>
#include <functional>
using namespace std;
double eval(function<double(double)> func,double a){
  return func(a);
}

int main(){
  auto funk=[](double a){
    return a*2;
  };
  cout<<eval(funk,2.0)<<endl;
}