#include <iostream>
using namespace std;
int main(){
  string a="1234";
  int i,j =0;
  int q=0;
  while (a[i]!='\0'){
    j=j*10;
    j=j+int(a[i]-'0');
    q=q+int(a[i]-'0');
    i++;
    
  }
  cout<<j<<" Quersumme "<<q<<"\n";
  return 0;
}