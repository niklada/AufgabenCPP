#include <iostream>
#include "datum.h"
using namespace std;
int main(){
  Datum a(3,3,1995);
  Datum b;
  b.aktuell();
  if(a!=b)
    cout <<"ungleich!"<<endl;
  if(a==b)
    cout <<"gleich!"<<endl;
  if(a<b) cout<<"a kleiner als b"<<endl;
  else cout<<"a größer gleich b"<<endl;
  cout<<DatumDifferenz(a,b)<<endl;
}