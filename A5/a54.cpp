#include <iostream>

using namespace std;
void leerzeichenEntfernen(char* s){
   char * i = s;
   //wenn nciht ende
    while(*s){
      //wenn kein leerzeichen
      if(*s!=' ')
	//eine stelle nach vorne verlegen
	*(i++)=*s;
      s++;
    }
    //ende des strings vorverlegen(wenn leerezeichen vorkamen
    *i='\0';
}