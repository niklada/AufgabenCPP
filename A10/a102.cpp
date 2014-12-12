#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;
int sum=0;
mutex counter_mutex;
void f(int start,int ende){
  int esum=0;
  for(int s=start+1;s<=ende;s++){
    esum+=s;
  }
  counter_mutex.lock();
  sum+=esum;
  counter_mutex.unlock();
  
}
int main(){
  cout<<"Bis wo soll aufaddiert werden? ";
  int bisWo;
  cin>>bisWo;
  int numberOf;
  cout<<"Wie viele Threads?";
  numberOf;
  cin>>numberOf;
 
  vector<thread *> threads;
  for(int i=0;i<numberOf;i++){
    thread *t=new thread(f,((bisWo)/numberOf)*i,((bisWo)/numberOf)*(i+1)+ ((i==numberOf-1) ? bisWo%numberOf : 0));
    threads.push_back(t);
    
  }
  for(int i=0;i<numberOf;i++){
    threads[i]->join();
  }
  cout<<sum<<endl;
}