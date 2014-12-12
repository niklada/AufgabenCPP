#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
void f1(){
  cout<<"Anfang 1"<<endl;
  this_thread::sleep_for(chrono::milliseconds(1000));
  cout<<"Ende 1"<<endl;
}
void f2(){
  cout<<"Anfang 2"<<endl;
  this_thread::sleep_for(chrono::milliseconds(2000));
  cout<<"Ende 2"<<endl;
}
void f3(){
  cout<<"Anfang 3"<<endl;
  this_thread::sleep_for(chrono::milliseconds(3000));
  cout<<"Ende 3"<<endl;
}
int main(){
  thread t1(f1);
  thread t2(f2);
  thread t3(f3);
  t1.join();
  t2.join();
  t3.join();
  cout<<"Ende"<<endl;
}