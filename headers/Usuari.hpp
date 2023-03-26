#ifndef USUARI_H
#define USUARI_H
#include "Film.hpp"
#include <iostream>
using namespace std;

class Usuari {
// Tipus de mòdul: dades
	
  public:

   Usuari();
   // Pre: cert
   // Post: crea un usuari amb les dades inicialitzades a zero o buides.

   Usuari(const Usuari&);
   // Pre: el paràmetre d'entrada és un Usuari.
   // Post: crea una còpia exacta de l'Usuari del paràmetre d'entrada.

   ~Usuari(); 
   // Pre: cert.
   // Post: esborra les dades locals del contingut Usuari.
 
   string getNickname() const;
   // Pre: cert.
   // Post: retorna en un stirng el nom de l'usuari.

   Usuari& operator=(const Usuari&);
   // Pre: les dades de l'usuari no estan buides.
   // Post: l'usuari passa a tenir els mateixos atributs que l'Usuari del paràmetre d'entrada.

   void incValorations();
   // Pre: cert.
   // Post: incrementa el valor de les valoracions en 1 de l'Usuari.

   void setID(int);
   // Pre: el paràmetre d'entrada és un nombre natural.
   // Post: modifica el valor de l'Id d'usuari amb el paràmetre d'entrada.
			 
   // Lectura i escriptura:
   
   friend ostream& operator<<(ostream &os, const Usuari &U);
   // Pre: cert.
   // Post: s'han escrit els atributs de la pel·lícula "F" al canal estàndard de sortida.  
   
   friend istream& operator>>(istream &is, Usuari &U);
   // Pre: pel canal estàndard d'entrada ha d'haver un strings no buit amb el nom de l'usuari.
   // Post: l'Usuari del paràmetre d'entrada passa a tenir els mateixos atributs
   // llegits pel canal estàndard d'entrada.

  private:

   string nickname;
   int id, nVal;
};
#endif
