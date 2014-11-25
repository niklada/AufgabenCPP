#ifndef OPERATORELEMENT_H
#define OPERATORELEMENT_H
enum class Operator {ADD,SUB,MULT,DIV};
class OperatorElement:public TreeElement{
public:
  
  OperatorElement(TreeElement* left,TreeElement* right,Operator op): TreeElement(left,right),op(op){}
  int evaluate(){
    switch(op){
      case Operator::ADD: return (left->evaluate()+right->evaluate());
      case Operator::SUB: return (left->evaluate()-right->evaluate());
      case Operator::MULT: return (left->evaluate()*right->evaluate());
      case Operator::DIV: return (left->evaluate()/right->evaluate());
    }
  }
  string ausgeben(){
    switch(op){
      case Operator::ADD: return "+";
      case Operator::SUB: return "-";
      case Operator::MULT: return "*";
      case Operator::DIV: return "/";
    }
  }
private:
  Operator op;
  
  
};
#endif