#include <iostream>
#include <fstream>
#include <cctype>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
bool isName(string &str){
  if(!isalpha(str[0]))
  return false;
  for (std::string::iterator it=str.begin()+1; it!=str.end(); ++it){
    if( (!isalnum(*it)) && (*it!='_') )
    return false;
  }
  return true;
}
inline bool isBuchstabe(char c){
  return(isalpha(c) || c=='_');
}
bool comp(map<string,size_t>::iterator a,map<string,size_t>::iterator b){
  return ((a->second)>(b->second));
}
struct comperator{
  bool operator() (map<string,size_t>::iterator a,map<string,size_t>::iterator b){return ((a->second)>(b->second));}
};

int main(){
  vector<map<string,size_t>::iterator> vec;
  map<string,size_t> m;
  cout << "Dateiname= " ;
  char * name = new char[20];
  cin.getline(name, 20);
  ifstream ifs(name);
  if(ifs){
    cout << "Datei enthaelt die folgenden Namen:" << endl;
    char c;
    while(ifs.get(c)){
      if(isBuchstabe(c)){
	string word;
	word+=c;
	while(ifs.get(c) && (isBuchstabe(c) || isdigit(c))){
	  word+=c;
	}
	//zu hashmap hinzufuegen
	  if(m.find(word)==m.end()){
	    m[word]=1;
	  }else{
	    m[word]+=1;
	  }
     }
   }
  } else {
    cout << "Datei wurde nicht gefunden" << endl;
  }
  comperator a;
  for(map<string,size_t>::iterator iter=m.begin(); iter!=m.end();++iter){
    vec.push_back(iter);
    
  }
  sort(vec.begin(),vec.end(), a);
  for(int i=0; i<vec.size();i++){
    cout<<vec[i]->first<<" Vorkommen: "<<vec[i]->second<<endl;
  }
}