#include <iostream>
#include <cstdlib>
using namespace std;
int leseAusdruck();
int leseSummand();
int leseFaktor();
int error;
void leseLeerzeichen(){
  char c;
  while(cin.peek()==' ') cin.get(c);
}
void checkError(){
  if(error==1){
    cout<<"Fehler im Format!"<<endl;
    exit(1);
  }
}
int leseAusdruck(){
  error=0;
  int lhs=leseSummand();  
  
  leseLeerzeichen();
  checkError();
  while((cin.peek())=='+'||(cin.peek())=='-'){
    char c;
    cin.get(c);
    int rhs=leseSummand();
    checkError();
    if(c=='+')
    lhs+=rhs;
    else lhs-=rhs;
    leseLeerzeichen();
  }
  return lhs; 
}
int leseSummand(){
  int lhs=leseFaktor();
  checkError();
  leseLeerzeichen();
  while((cin.peek())=='*'||(cin.peek())=='/'){
    char c;
    cin.get(c);
    int rhs =leseFaktor();
    checkError();
    if(c=='*') lhs*=rhs;
    else lhs/=rhs;
    leseLeerzeichen();
  }
  return lhs;
}
int leseFaktor(){
  leseLeerzeichen();
  int result;
  
  if((cin.peek())=='-'||(cin.peek())=='+'){
    char c;
    cin.get(c);
    result=leseFaktor();
    checkError();
    if(c=='-') result=-result;
  }else{
    char c;
    
    if(isdigit(cin.peek())){
      cin >>result;
    }else{
      cin.get(c);
      if(c=='('){
	result=leseAusdruck();
	checkError();
	leseLeerzeichen();
	cin.get(c);
	if(c!=')') error=1;
      }else error=1;
    }
  }
  return result;
}
int main(){ 
  cout<<leseAusdruck()<<endl; 
}