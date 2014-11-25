#ifndef TREEELEMENT_H
#define TREEELEMENT_H
using namespace std;
class TreeElement{
public:
  TreeElement* left;
  TreeElement* right;
  TreeElement(TreeElement* left,TreeElement* right) :left(left),right(right){}
  virtual int evaluate() =0;
  virtual string ausgeben()=0;
private:
};

#endif