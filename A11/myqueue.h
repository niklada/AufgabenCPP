#ifndef MYQUEUE
#define MYQUEUE
#include <initializer_list>
#include <list>
#include <iostream>
using namespace std;
template <typename T>
class MyQueue{
private:
  list<T> queue;
public:
  MyQueue(MyQueue && q) : queue(move(q.queue)){};
  MyQueue(initializer_list<T> lis):queue(lis){}
  MyQueue& operator =(MyQueue<T>&& q)=default;
  void push_back(T a){
    queue.push_back(a);
  }
  void pop_front(){ 
    queue.pop_front(); 
  }
  T size(){
    return queue.size();
  }
  bool empty(){
    return queue.empty();
  }
  typename list<T>::iterator begin(){
    return queue.begin();
  }
  typename list<T>::iterator end(){
    return queue.end();
  }
  friend ostream& operator<<(ostream& o, const MyQueue<T>& q){
    for(auto iterator=q.queue.begin(), end=q.queue.end(); iterator!= end;++iterator){
      o<<*iterator<<" ";
    }
    return o;
  }
};
#endif