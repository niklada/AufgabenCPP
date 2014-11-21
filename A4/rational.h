// Klasse f�r rationale Zahlen
//////////////////////////////

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
   public:
     Rational();
     Rational(long z, long n);   // allgemeiner Konstruktor
//     Rational(long);             // Typumwandlungskonstruktor

     // Abfragen
     long getZaehler() const;
     long getNenner()  const;

     // arithmetische Methoden
     // (werden sp�ter durch �berladene Operatoren erg�nzt)
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

   private:
     long zaehler, nenner;
};

// inline Methoden
inline Rational::Rational()               : zaehler(0), nenner(1) {}
inline Rational::Rational(long z, long n) : zaehler(z), nenner(n) {}
//inline Rational::Rational(long ganzeZahl) : zaehler(ganzeZahl), nenner(1) {}

inline long Rational::getZaehler() const {return zaehler;}
inline long Rational::getNenner()  const {return nenner;}

// globale Funktionen
const Rational add(const Rational& a, const Rational& b);
const Rational sub(const Rational& a, const Rational& b);
const Rational mult(const Rational& a, const Rational& b);
const Rational div(const Rational& z, const Rational& n);
const Rational add(long a, const Rational& b);
const Rational add(const Rational& a, long b);
const void ausgabe(Rational& a);

#endif
