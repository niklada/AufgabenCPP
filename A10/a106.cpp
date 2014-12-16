#include <iostream>
#include <functional>
#include <cmath>
using namespace std;
double newton(function<double(double)> f,function<double(double)> fs){
  //startwert
  double x=1.;
  while(true){
    double xn=x-(f(x)/fs(x));
    if( abs(xn-x) < 0.0001) break;
    x=xn;
  }
  cout<<"mit normaler Funktion:"<<endl;
  return x;
}
int main(){
  //funktioniert mit und ohne auto
  function<double(double)> f = [] (double x){
    return (x*x);
  };
  auto fs = [] (double x){
    return 2*x;
  };
  function<double(double)> f2 = [] (double x){
    return (2*x*x+4*x+2);
  };
  auto f2s = [] (double x){
    return 4*x+4;
  };
  auto lambdaNewton = [] (function<double(double)> f,
			  function<double(double)> fs){
  double x=1.;
  while(true){
    double xn=x-(f(x)/fs(x));
    if( abs(xn-x) < 0.0001) break;
    x=xn;
  }
  cout<<"mit lambda Funktion:"<<endl;
  return x;
  };
  cout<<"testfall 1:"<<endl;
  cout << newton(f,fs)<<endl;
  cout << lambdaNewton(f,fs)<<endl;
  cout<<"testfall 2:"<<endl;
  cout << newton(f2,f2s)<<endl;
  cout << lambdaNewton(f2,f2s)<<endl;
}