#include <iostream>
#include <string>
using namespace std;

/***********************************************/
/* Bitte die folgenden Makros einkommentieren, */
/* so bald die entsprechende Unteraufgabe      */
/* gelöst ist !!!                              */
/***********************************************/
#define A1_a
#define A1_b
#define A1_c
#define A1_d
//#define A1_e

class Audioformat {
public:

    virtual string titel() { return ""; }
    virtual string info() =0;
};

int mp3_counter = 0;

class MP3_Format : public Audioformat {
public:
    MP3_Format(string title):song(title){
      mp3_counter++;
    }
    MP3_Format(MP3_Format& m):song(m.song){
      mp3_counter++;
    }
    MP3_Format():song(""){
      mp3_counter++;
    }
    operator string () const{
      return song;
    }
    bool operator==(MP3_Format& m){
      return song==m.song;
    }
    bool operator!=(MP3_Format& m){
      return song!=m.song;
    }
/*    MP3_Format& operator=(const char * s){
      cout<<"zuweisung"<<endl;
      strcpy(song, s);
      song=s;
      return *this;
    }*/
    MP3_Format& operator=(const string s){
      cout<<"zuweisung"<<endl;
      song=s;
      return *this;
    }
    MP3_Format& operator=(const char* s){
      cout<<"zuweisung"<<endl;
      string ssong=s;
      song=ssong;
      return *this;
    }
    string titel() { return  song; }
    string info()  { return "MP3"; }
    virtual ~MP3_Format(){
      mp3_counter--;
    }
private:
    string song;
};
