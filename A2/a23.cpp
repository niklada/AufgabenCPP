#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;
char toHex(char a){
  
}
int main(){
  ifstream ifs;
  ofstream ofs;
  char a;
  int count=0;
  string str;
  ifs.open("in.txt");
  ofs.open("out.txt");
  while((a=ifs.get())!=EOF){
    count++;
    
    unsigned int b=(int)(unsigned char)(a);
    if(!isprint(a))
      str+='.';
    else
      str += a;
    
     
    
      cout<<hex<<b<<" ";
    if(count==16){
      cout << str << endl;
      str="";
      count=0;
    }
    
  }
  cout<<"    " <<str;
  
  cout<<endl;
}
