//Klasse IntMenge.h
#ifndef INTMENGE_H
#define INTMENGE_H
#include <vector>
#include <algorithm>
class IntMenge{
  public:
    IntMenge();
    IntMenge(IntMenge& andereMenge);
    void hinzufuegen(int e1);
    void entfernen(int e1);
    bool istMitglied(int e1);
    size_t size();
    void anzeigen();
    void loeschen();
    int getMax();
    int getMin();
    void loeschen();
    
  private:
  std::vector<int> menge;
  int grosse;
};

#endif