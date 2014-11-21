#include <iostream>
using namespace std;
int main(){
  long long a;
  cout<<"Geben Sie Ihre Startzahl ein! \n";
  cin>>a;
  long long max=0;
  int iterationen=0;
  while(a>1){
    cout<<"Aktuelle Zahl "<<a<<"\n";
    iterationen++;
    if(a>max){max=a;cout<<"Neues Maximum: "<<max<<"\n";string dummy; getline(cin,dummy);}
    if(a%2==0) a/=2;
    else a=a*3+1;
    
  }
  cout<<"Iterationen: "<<iterationen<<" Maximum: "<<max<<"\n";
  return 0;
}
  