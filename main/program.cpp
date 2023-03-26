#include "Film.hpp"
#include "Usuari.hpp"
#include "Plataforma.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Plataforma Film_Recomendation;
	string opcions;
	bool finalitzar = false;
	cin >> Film_Recomendation;
	Film_Recomendation.llegirpelicules();
	Film_Recomendation.llegirusuaris();
	while (not finalitzar and cin >> opcions){
		if(opcions=="acabar"){
			finalitzar = true;
		} else if(opcions=="mostrarFilms"){
			Film_Recomendation.mostrarFilms();
		} else if(opcions=="mostrarUsuaris"){
			Film_Recomendation.mostrarUsuaris();
		} else if(opcions=="mostrarFilmsGenere"){
			Film_Recomendation.mostrarFilmsGenere();
		} else if(opcions=="enregistrarValoracio"){
			Film_Recomendation.enregistrarValoracio();
		} else if (opcions=="recomanarMillorFilm"){
			Film_Recomendation.recomanarMillorFilm();
		} else if(opcions=="mostrarMillorsFilms"){
			Film_Recomendation.mostrarMillorsFilms();
		} else cout << "Error: Opció no vàlida" << endl;
	}
}
