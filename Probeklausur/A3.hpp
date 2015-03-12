#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <sstream>
#include <thread>
#include <string>
#include <mutex>
#include <chrono>
using namespace std;

extern vector<string> Q;
extern stringstream S;
extern thread T;
mutex mtex;
bool running;
/***********************************************/
/* Bitte die folgenden Makros einkommentieren, */
/* so bald die entsprechende Unteraufgabe      */
/* gelöst ist !!!                              */
/***********************************************/
#define A3_a
#define A3_b
#define A3_c

#ifdef  A3_a
void f(){
  running=true;
  while(running){
    string s="";
    {
      lock_guard<mutex> lg(mtex);
      if(Q.size()>0){
	s=Q.back();
	Q.pop_back();
      }
    }
    if(s!=""){
      for(char a:s){
	S<<a;
	this_thread::sleep_for(chrono::milliseconds(100));
      }
    }
    else{
      S<<'-';
      this_thread::sleep_for(chrono::milliseconds(100));
    }
  }
}
void f1(){
  cout<<"Anfang 1"<<endl;
  this_thread::sleep_for(chrono::milliseconds(1000));
  cout<<"Ende 1"<<endl;
}

void start_thread()
{
  T=thread(f);
  
}
#endif

#ifdef  A3_b
void send_word(const string & s)
{
  lock_guard<mutex> lg(mtex);
  Q.push_back(s);

}
#endif

#ifdef  A3_c
void stop_thread()
{
  running=false;
  T.join();
}
#endif
