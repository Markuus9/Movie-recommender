#ifndef FILM_H
#define FILM_H
#include <iomanip>    
#include <iostream>
#include <string>
using namespace std;

class Film {
// Tipus de mòdul: dades

  private:

    string nom, genere;
    int puntuacio, num_vegades_puntuat;

  public:

   // Constructors:

   Film();
   // Pre: cert.
   // Post: crea un Film amb totes les dades a zero o buides.

   Film(const Film&);
   // Pre: cert.
   // Post: crea un Film amb les mateixes dades que les del Film "F".
   
   // Destructor:

   ~Film();
   //Post: esborra automàticament els objectes locals en sortir d'un àmbit
   //      de visibilitat.

   // Consultors:

   string GetName() const;
   //Pre: nom.size() > 0, és a dir, el nom de la pel·lícula no és buida.
   //Post: retorna el nom de la pel·lícula.

   string GetGenere() const;
   //Pre: genere.size() > 0, és a dir, el genere de la pel·lícula no és buid.
   //Post: retorna el nom del gènere de la pel·lícula.

   float GetFinalMark() const;
   //Pre: cert
   //Post: retorna la valoració final de la pel·lícula.

   // Modificadors:

   void addmark(const int&);
   //Pre: el paràmetre d'entrada és un enter entre [1,...,5].
   //Post: afegeix la valoració de l'usuari a la pel·lícula corresponent.

   Film& operator=(const Film&);
   // Pre: cert.
   // Post: el resultat és un Film amb els atributs del Film F.

   // Lectura i escriptura:

   friend ostream& operator<<(ostream &os, const Film &);
    // Pre: cert.
    // Post: s'han escrit els atributs del film del paràmetre d'entrada al canal estàndard de sortida. 

    friend istream& operator>>(istream &is, Film &);
    // Pre: Pel canal estàndard d'entrada ha d'haber dos strings no buits amb el nom i el gènere de la pel·lícula. 
    // Post: El Film del paràmetre d'entrada passa a tenir els atributs llegits del canal estàndard d'entrada.
};
#endif
