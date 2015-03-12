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
#define A1_f

class Audioformat {
public:

    virtual string titel() =0; // { return ""; }
    virtual string info()  =0; // { return ""; }
};

int mp3_counter = 0;

class MP3_Format : public Audioformat {
public:
    // CTORs
    MP3_Format() { mp3_counter++; }
    MP3_Format(const string & s) : song(s) { mp3_counter++; }
    MP3_Format(const char * s  ) : song(s) { mp3_counter++; }
    MP3_Format(const MP3_Format & m) : song(m.song)  { mp3_counter++; }

    // DTORs
    virtual ~MP3_Format() { mp3_counter--; }
    
    // ASSGN
    MP3_Format & operator= (const MP3_Format & rhs) { song = rhs.song; return *this; }
    
    string titel() { return  song; }
    string info()  { return "MP3"; }

    bool operator== (const MP3_Format & m) { return(song == m.song); }
    bool operator!= (const MP3_Format & m) { return ! (*this == m);  }
    operator string() const { return song; }

private:
    string song;
};

