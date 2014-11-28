// Klasse für rationale Zahlen
//////////////////////////////

#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;

class Rational {
   public:
     Rational();
     Rational(long z, long n);   // allgemeiner Konstruktor
//     Rational(long);             // Typumwandlungskonstruktor

     // Abfragen
     long getZaehler() const;
     long getNenner()  const;

     // arithmetische Methoden
     // (werden später durch überladene Operatoren ergänzt)
     void add(const Rational& r);
     void sub(const Rational& r);
     void mult(const Rational& r);
     void div(const Rational& r);
     

     // weitere Methoden
     void set(long zaehler, long nenner);
     void eingabe();
     void ausgabe() const;
     void kehrwert();
     void kuerzen();
     
     friend istream& operator>>(istream& in,Rational& r){
       int zahl;
       int nenn;
       char p;
       in.get(p);
       in>>zahl;
       in.get(p);
       in>>nenn;
       r.set(zahl,nenn);
       in.get(p);
       return in;
    }
    inline bool operator==(Rational& r){
      if(r.getZaehler()!=this->getZaehler()) return false;
      if(r.getNenner()!=this->getNenner()) return false;
      return true;
    }
    void operator+=(Rational& r){
      this->add(r);
    }
    

   private:
     long zaehler, nenner;
};

// inline Methoden
inline Rational::Rational()               : zaehler(0), nenner(1) {}
inline Rational::Rational(long z, long n) : zaehler(z), nenner(n) {
  kuerzen();
}
//inline Rational::Rational(long ganzeZahl) : zaehler(ganzeZahl), nenner(1) {}

inline long Rational::getZaehler() const {return zaehler;}
inline long Rational::getNenner()  const {return nenner;}

// globale Funktionen
const Rational operator+(const Rational& a, const Rational& b);
const Rational operator-(const Rational& a, const Rational& b);
const Rational operator*(const Rational& a, const Rational& b);
const Rational operator/(const Rational& z, const Rational& n);
const Rational operator+(long a, const Rational& b);
const Rational operator+(const Rational& a, long b);
const void ausgabe(Rational& a);


#endif
