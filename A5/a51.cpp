//grosse vom arrray spaltenanzahl*zeilenanzahl*4
//position (zeile-1)*(spaltenanzahl)*4+(spalte)*4
#include <iostream>
using namespace std;
int main(){
  int matrix[2][3];
  cout<< sizeof(matrix)<<endl;
  cout<< &matrix<<" 1.zeile 2. element "<<&matrix[0][1]<<endl;
}