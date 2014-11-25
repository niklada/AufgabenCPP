#include <iostream>
#include "array2d.h"
using namespace std;
int main(){
  int arr[3][4]={{1,2,3,4},{2,6,1,8},{5,1,2,1}};
  int arrb[4][1]={1,9,11,5};
  Array2d<int> A(arr);
  printArray(A);
  Array2d<int> B(arrb);
  Array2d<int> C=mmult(A,B);
  printArray(C);
  
}