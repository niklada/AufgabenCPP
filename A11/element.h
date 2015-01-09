#ifndef ELEMENT_H
#define ELEMENT_H
class Element{
  private:
  public:
    Element(int a):content(a){}
    int content;
    element* next;
    element* last;
};
#endif