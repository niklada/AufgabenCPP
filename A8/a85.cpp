#include <iostream>
#include "meinstring.h"
using namespace std;
int main(){
  MeinString a("Hallo");
  MeinString b("danach");
  a+=b;
  cout<<"Jetzt wird Hallo zu Hallodanach"<<endl;
  cout<<a<<endl;
  MeinString c;
  c=a+b;
  cout<<"Jetzt wurde Hallodanach mit danach addiert und einer neuen Variable zugewiesen"<<endl;
  cout<<c<<endl;
}