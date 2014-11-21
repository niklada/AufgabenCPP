// Einfache String-Klasse (mit Optimierungen)
#ifndef MEINSTRING_H
#define MEINSTRING_H
#include <cstddef>    // size_t
#include <iostream>   // ostream

class MeinString {
  public:
   MeinString();                     // Default-Konstruktor
   MeinString(const char *);         // allg. Konstruktor
   MeinString(const MeinString&);    // Kopierkonstruktor
   ~MeinString();                    // Destruktor
   MeinString& assign(const MeinString&); // Zuweisung eines MeinString
   MeinString& assign(const char *);      // Zuweisung eines char*
   const char& at(size_t position) const; // Zeichen holen
   char& at(size_t position);             // Zeichen holen, die Referenz erlaubt �ndern des Zeichens
   size_t length() const { return len;}   // Stringl�nge zur�ckgeben
   size_t capacity() const { return cap;} // Kapazit�t zur�ckgeben
   void reserve(size_t bytes);            // Platz reservieren mit Erhalt des Inhalts
   void shrink_to_fit();                  // Platz minimieren
   const char* c_str() const { return start;}  // C-String zur�ckgeben
   void insert (size_t pos, const MeinString& m);
  private:
   size_t len;                         // L�nge
   size_t cap;                         // Kapazit�t
   char *start;                        // Zeiger auf den Anfang
   void reserve_only(size_t bytes);    // Hilfsmethode: nur Platz reservieren
};

void anzeigen(std::ostream& os, const MeinString& m);

#endif

