// NOCH NICHT VOLLSTÄNDIG (s. Übungsaufgaben)
#ifndef DATUM_H
#define DATUM_H
#include<string>
#include<iostream>
using namespace std;

class Datum {
  public:
    Datum();                         // Default-Konstruktor
    Datum(int t, int m, int j = 1997); // allgemeiner Konstruktor
    void set(int t, int m, int j); // Datum setzen
    void aktuell();                  // Systemdatum setzen
    bool istSchaltjahr() const;
    Datum& operator++();             // Tag hochzählen, präfix
    Datum operator++(int);           // Tag hochzählen, postfix
    int tag()   const;
    int monat() const;
    int jahr()  const;
    friend ostream& operator<<(ostream& o,Datum& d){
      o<<d.tag_<<"."<<d.monat_<<"."<<d.jahr_<<endl;
      return o;
    }
    bool operator==(Datum& d){
      if(this->jahr_!=d.jahr_) return false;
      if(this->monat_!=d.monat_) return false;
      if(this->tag_!=d.tag_) return false;
      return true;
    }
    bool operator!=(Datum& d){
      return(!((*this)==d));
    }
    bool operator<(Datum& d){
      if(this->jahr_<d.jahr_) return true;
      if(this->monat_<d.monat_) return true;
      if(this->tag_<d.tag_) return true;
      return false;
    }
    bool operator<(const Datum& d){
      if(this->jahr_<d.jahr_) return true;
      if(this->monat_<d.monat_) return true;
      if(this->tag_<d.tag_) return true;
      return false;
    }

    // besser: durch Methode string toString() ersetzen!
    // (siehe Übungsaufgabe)
    operator std::string() const;         // Typumwandlungsoperator
  private:
     int tag_, monat_, jahr_;
};

bool istSchaltjahr(int jahr); // Impl. s.u.

// inline-Methoden
inline Datum::Datum(int t, int m, int j) { set(t, m, j);}

inline int Datum::tag()   const { return tag_;  }
inline int Datum::monat() const { return monat_;}
inline int Datum::jahr()  const { return jahr_; }
inline bool Datum::istSchaltjahr() const {
  return ::istSchaltjahr(jahr_); 
}
 
// global
bool istGueltigesDatum(int t, int m, int j);
int DatumDifferenz(const Datum& a,const Datum& b);
inline bool istSchaltjahr(int jahr)  {
   return  (jahr % 4 == 0 && jahr % 100) || jahr % 400 == 0;
}
inline bool operator<(const Datum& a,const Datum& d){
      if(a.jahr()<d.jahr()) return true;
      if(a.monat()<d.monat()) return true;
      if(a.tag()<d.tag()) return true;
      return false;
    }


#endif  


