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

bool  running;
mutex Q_mutex;

/***********************************************/
/* Bitte die folgenden Makros einkommentieren, */
/* so bald die entsprechende Unteraufgabe      */
/* gelöst ist !!!                              */
/***********************************************/
#define A3_a
#define A3_b
#define A3_c

#ifdef  A3_a
void start_thread()
{
    running = true;
    T = thread([&]
       {
           while(running) {
               string s = "";
               {
                  lock_guard<mutex> lg(Q_mutex);
                  if (Q.size() != 0) {
                     s = Q.back();
                     Q.pop_back();
                  }
               }
               if (s != "") {
                   for (char c: s) {
                       S << c;
                       //cout << c << endl;
                       this_thread::sleep_for(chrono::milliseconds(100));
                   }
               }
               else {
                   S << "-";
                   //cout << "-" << endl;
                   this_thread::sleep_for(chrono::milliseconds(100));
               }
           }  
       } );
}
#endif

#ifdef  A3_b

void send_word(const string & s)
{
    lock_guard<mutex> lg(Q_mutex);
    Q.push_back(s);
}
#endif

#ifdef  A3_c
void stop_thread()
{
    running = false;
    T.join();
}
#endif
