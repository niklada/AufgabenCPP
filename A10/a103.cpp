#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <condition_variable>
using namespace std;
condition_variable cv1;
condition_variable cv2;
condition_variable cv3;
mutex data_mutex;
void f1(int n){
  cout<<n<<" gestartet"<<endl;
  unique_lock<mutex> ul(data_mutex);
  cv1.wait(ul);
  cout<<n<<" notified"<<endl;
  this_thread::sleep_for(chrono::milliseconds(1000));
  cout<<n<<" beendet"<<endl;
  cv2.notify_one();
}
void f2(int n){
  cout<<n<<" gestartet"<<endl;
  unique_lock<mutex> ul(data_mutex);
  cv2.wait(ul);
  cout<<n<<" notified"<<endl;
  this_thread::sleep_for(chrono::milliseconds(1000));
  cout<<n<<" beendet"<<endl;
  cv3.notify_one();
}
void f3(int n){
  cout<<n<<" gestartet"<<endl;
  unique_lock<mutex> ul(data_mutex);
  cv3.wait(ul);
  cout<<n<<" notified"<<endl;
  this_thread::sleep_for(chrono::milliseconds(1000));
  cout<<n<<" beendet"<<endl;
}
int main(){
  thread t1(f1,1);
  thread t2(f2,2);
  thread t3(f3,3);
  this_thread::sleep_for(chrono::milliseconds(1000));
  cv1.notify_one();
  t1.join();
  t2.join();
  t3.join();
}