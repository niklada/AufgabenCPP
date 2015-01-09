#include "myqueue.h"
#include <iostream>
#include <initializer_list>
using namespace std;
template <typename T>
MyQueue::MyQueue(initializer_list<T> lis):queue(lis){
  
}
//MyQueue::MyQueue(MyQueue && q) queue(q.queue){
//  q.queue=
//}
template <typename T>
void MyQueue::push_back(T a){
  queue.push_back(a);
  
}
template <typename T>
void MyQueue::pop_front(){
  
  queue.pop_front();
 
}
template <typename T>
T MyQueue::size(){
  return queue.size();
}
template <typename T>
bool MyQueue::empty(){
  return queue.empty();
}
template <typename T>
typename list<T>::iterator MyQueue::begin(){
  return queue.begin();
}
template <typename T>
typename list<T>::iterator MyQueue::end(){
  return queue.end();
}
template<typename T>
ostream& operator<<(ostream& o, const MyQueue<T>& q){
    o<<"ausgabe"<<endl;
    for(auto iterator=q.queue.begin(), end=q.queue.end(); iterator!= end;++iterator){
      o<<*iterator<<" ";
    }
  return o;
}