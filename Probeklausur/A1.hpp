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
#define A1_e

class Audioformat {
public:
    
    virtual string titel() { return ""; }
    virtual string info()  { return ""; }
};

int mp3_counter = 0;

class MP3_Format : public Audioformat {
public:
    MP3_Format(MP3_Format& r):song(r.song){
      mp3_counter++;
    }
    MP3_Format(const MP3_Format& r):song(r.song){
      mp3_counter++;
    }
    MP3_Format(string tit) : song(tit){
      mp3_counter++;
    }
    MP3_Format(const char * s) : song(s){
      mp3_counter++;
    }
    MP3_Format():song(""){
      mp3_counter++;
    }
    virtual string titel() { return  song; }
    virtual string info()  { return "MP3"; }
    operator string () const{
      return song;
    }
    virtual ~MP3_Format(){
      mp3_counter--;
    }
    bool operator==(MP3_Format& a){
      return (this->song==a.song);
    }
    bool operator!=(MP3_Format& a){
      return !(this->song==a.song);
    }
    
    MP3_Format& operator=(const char *a){
      
      song=a;
      return *this;
    }
    MP3_Format& operator=(string a){
      
      song=a;
      return *this;
    }

private:
    string song;
};
