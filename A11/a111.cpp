#include <iostream>
#include "myqueue.h"
#include <string>
using namespace std;
int main(){
  MyQueue<int> q={3,5,4};
  cout<<"startqueue "<<q<<endl;
  cout<<"popfront"<<endl;
  q.pop_front();
  cout<<q<<(q.empty()? "is empty" : "not empty")<<endl;
  cout<<"Größe "<<q.size()<<endl;
  cout<<"pushback 14"<<endl;
  q.push_back(14);
  cout<<q<<endl;
  MyQueue<int> a(move(q));
  cout<<"moved(constructor) to a: "<<(a.empty()? "is empty" : "not empty")<<endl;
  MyQueue<int> b=move(a);
  cout<<"moved(assigned) to b: "<<(b.empty()? "is empty" : "not empty")<<endl;
  cout<<"for each loop:"<<endl;
  for(auto elem : b){
    cout << elem <<endl;
  }
  MyQueue<string> stringQ={"das","ist","die","infixdarstellung"};
  cout<<"String queue"<<endl<<stringQ<<endl;
  MyQueue<char> charQ={'(','4','+','5',')','*','3'};
  cout<<"Character queue"<<endl<<charQ<<endl;
}