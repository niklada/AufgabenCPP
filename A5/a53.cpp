#include <iostream>
#include "list.h"
using namespace std;


  template<typename T>
  int aufs(T& a, T& b){
    if(a>b) return 1;
    if(a==b)return 0;
    return -1;
  }
  template <typename T>
  int abst(T& a,T& b){
    if(a>b) return -1;
    if(a==b) return 0;
    return 1;
  }
  int main(){
    Element <int> *h=NULL;
    for(int i =0;i<100;i++){
      insert(h,i);
    }
    print(h);
    Element <int> *h2=NULL;
    for(int i =0;i<100;i++){
      insert(h2,i,abst);
    }
    print(h2);
  }

