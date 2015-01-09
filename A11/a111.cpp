#include <iostream>
#include "myqueue.h"
using namespace std;
int main(){
  MyQueue<int> q={5,4};
  //q.pop_front();
  cout<<(q.empty()? "is empty" : "not empty")<<endl;
  cout<<q.size()<<endl;
  cout<<q<<endl;
  MyQueue<int> a(move(q));
  cout<<(a.empty()? "is empty" : "not empty")<<endl;
  MyQueue<int> b=move(a);
  cout<<(b.empty()? "is empty" : "not empty")<<endl;
  for(auto elem : b){
    cout << elem <<endl;
  }
}