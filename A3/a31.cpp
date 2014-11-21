#include <iostream>
#include <cmath>
using namespace std;
long long fak(long long i);
double ehoch(double x){
  if(x<0) return (1/ehoch(-x));
  long double back=1;
  long double lastelement=1;
  int i=0;
  for(i=1;i<=10000;i++){
    lastelement=lastelement*x;
    lastelement=lastelement/i;
    back+=lastelement;
    
  }
  return back;
  
}


int main(){
  int i=0;
  for(i=-40;i<=40;i+=10){
    cout<<"Für i="<<i<<" :"<< ehoch(i)<<" und die normale e Funktion"<<exp(i)<<endl;
  }
}