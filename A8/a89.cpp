#include <iostream>
#include "datum.h"
#include "UngueltigesDatumException.h"
using namespace std;
int main(){
  Datum einDatum;
  try{
    einDatum.set(30,2,2010);
  }catch(const UngueltigesDatumException& e){
    cout<< e.what()<<endl;
  }
}