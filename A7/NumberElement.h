#ifndef NUMBERELEMENT_H
#define NUMBERELEMENT_H
using namespace std;
class NumberElement : public TreeElement{
public:
  NumberElement( int number):TreeElement(nullptr,nullptr),number(number){}
  int evaluate(){return number;}
  string ausgeben(){return to_string(number);}
private:
  int number;
};
#endif