#ifndef LIST_H
#define LIST_H
#include <iostream>
template <typename T>
struct Element
{
  T value;
  Element *next;
  Element(T v, Element *n): value(v), next(n) {}
};
template <typename T>
void insert(Element<T>* &rp, T v) {
  if (rp != NULL) {
    if (v > rp->value)
    // Sortieren
      insert(rp->next, v); // Rekursion
    else rp=new Element<T>(v, rp);
  }
  else rp=new Element<T>(v, NULL);
}
template <typename T>
void remove(Element<T>* &rp, T v) {
  if (rp != NULL) {
    if (rp->value == v) {
      Element<T> *tmp=rp;
      rp = rp->next;
      delete tmp;
      remove(rp, v);
    }
    else remove(rp->next, v);// Rekursion
  }
}
template <typename T>
void print(Element<T> *p) {
  while(p) {
    std::cout << p->value<< " ";
    p=p->next;
  }
  std::cout << std::endl;    
}
template <typename T>
void insert(Element<T>* &rp, T v,int (*compare)(T&,T&)){
  if (rp != NULL) {
    if (compare(v,rp->value)>0)// Sortieren
      insert(rp->next, v); // Rekursion
    else rp=new Element<T>(v, rp);
  }
  else rp=new Element<T>(v, NULL);
  
}



#endif