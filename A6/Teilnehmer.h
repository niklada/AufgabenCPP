#ifndef TEILNEHMER_H
#define TEILNEMER_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Teilnehmer{
  public:
    Teilnehmer(string);
    void lerntKennen(Teilnehmer &);
    void druckeBekannte();
    string gibNamen();

  private:
    string name;
    vector<Teilnehmer *>bekannte;
    int id;
};

#endif