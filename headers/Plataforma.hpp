#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include "Film.hpp"
#include "Usuari.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Plataforma {
// Tipus de mòdul: dades

  public:
   // ESPECIFICACIÓ DE LA CLASSE PLATAFORMA

   // Constructors:

   Plataforma();
   // Pre: cert.
   // Post: crea una Plataforma amb totes les dades a zero o buides.

   // Destructor:

   ~Plataforma();   
   // Post: esborra automàticament els objectes locals en sortir d'un àmbit
   // de visibilitat.

   // Consultors:

   bool alreadyInUsers(Usuari&, vector<Usuari>&) const;
   // Pre: sigui User un Usuari no buit i Users un vector d'Usuari no buit.
   // Post: En cas que User estigui a Users retorna True, en cas contrari
   // retorna False.

   bool alreadyInFilms(Film&, vector<Film>&) const;
   // Pre: sigui film un Film no buit i Fi un vector de Film no buit.
   // Post: En cas que film estigui a Fi retorna True, en cas contrari
   // retorna False.

   int partition(vector<Film>&, int, int);
   // Pre: El vector de films del paràmetre d'entrada no és buit i
   // els enters són enters positius.
   // Post: els elements del vector han sigut reordenats.

   void quickSort(vector<Film>&, int, int);   
   // Pre: El vector de films del paràmetre d'entrada no és buit i
   // els enters són enters positius.
   // Post: Mostra pel canal estàndard de sortida els Films de forma que
   // estiguin ordenats per nota de valoració, en cas de ser empat
   // estiguin ordenats de forma alfabètica.

   // Modificadors:

   Plataforma& operator=(const Plataforma&);
   //Pre: cert.
   // Post: plataforma passa a tenir els mateixos atributs que la plataforma
   // del paràmetre d'entrada.
 
   // Lectura i escriptura:

   void llegirpelicules();
   // Pre: cert.
   // Post: la plataforma "P" conte el conjunt de pel·lícules, llegits pel canal
   // estàndard d'entrada.

   void llegirusuaris();
   // Pre: cert
   // Post: la plataforma "P" conte el conjunt de pelicules, llegits pel canal 
   // estandard d'entrada.

   void mostrarFilms() const;
   //Pre: cert
   //Post: mostra pel canal estàndard de sortida les pel·lícules enregistrades de
   // la plataforma.

   void mostrarUsuaris() const;
   //Pre: cert
   //Post: mostra pel canal estàndard de sortida els usuaris enregistrats de 
   // la plataforma.

   void mostrarFilmsGenere() const;
   //Pre: sigui gènere un string de caràcters no buit.
   //Post: mostra pel canal estàndard de sortida les pel·lícules enregistrades amb
   // el gènere escollit.

   void enregistrarValoracio();
   //Pre: cert.
   //Post: enregistra la valoració feta per l'usuari a la pel·lícula corresponent, afegeix el número de vegades
   // que aquest usuari ha valorat i mostra pel canal estàndard de sortida l'operació feta.  

   void recomanarMillorFilm() const;
   // Pre: cert.
   // Post: mostra els atributs del millor Film segons la seva nota
   // (en cas d'empat per orde alfabètic) pel canal estàndard  de sortida.

   void mostrarMillorsFilms();
   //Pre: cert
   // Post: mostra els atributs dels n millors Films segons la seva nota
   //       (en cas d'empat per orde alfabetic) pel canal estàndard de sortida.

   friend istream& operator>>(istream &, Plataforma &);
   /* Pre: cert */
   /* Post: la plataforma "P" passa a tenir els atributs llegits del canal  
    estàndard d'entrada */
  
  private:
    string nom;	
    vector<Film> Films;
    vector<Usuari> Usuaris;
};
#endif
