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
  MyQueue(initializer_list<T>);
  MyQueue& operator =(MyQueue&& q)=default;
  void push_back(T);
  void pop_front();
  T size();
  bool empty();
  typename list<T>::iterator begin();
  typename list<T>::iterator end();
  friend ostream& operator<<(ostream& o,const MyQueue& q);
};
#endif