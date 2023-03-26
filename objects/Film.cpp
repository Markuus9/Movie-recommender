#include "Film.hpp"

// IMPLMENTACIÓ DE LA CLASSE FILM

Film::Film(){
    nom = "";
    genere = "";
    puntuacio = 0;
    num_vegades_puntuat = 0;
}

Film::Film(const Film& F){
    nom = F.nom;
    genere = F.genere;
    num_vegades_puntuat = F.num_vegades_puntuat;
    puntuacio = F.puntuacio;
}

// Destructor:

Film::~Film(){
    
}
        
// Consultors:

string Film::GetName() const
{
    return nom;
}

string Film::GetGenere() const
{
    return genere;
}

float Film::GetFinalMark() const
{
    if (num_vegades_puntuat==0){
        return 0.0;
    } else {
        return ((float)puntuacio/(float)num_vegades_puntuat);
    }
}

// Modificadors:

Film& Film::operator=(const Film &F)
{
    nom = F.nom;
    genere = F.genere;
    num_vegades_puntuat = F.num_vegades_puntuat;
    puntuacio = F.puntuacio;
    return *this;
}

void Film::addmark(const int& valoracio)
{
    ++num_vegades_puntuat;
    puntuacio += valoracio;
} 
            
// Lectura i escriptura:

ostream& operator<<(ostream &os, const Film &F)
{
    float puntuacio = 0.0;
    if(F.num_vegades_puntuat !=0 ) puntuacio = (float)F.puntuacio/(float)F.num_vegades_puntuat;
    os.precision(1); 
    os << " (" << F.nom << ", " << F.genere << ", " << fixed << puntuacio << ", " << F.num_vegades_puntuat<<")" << endl;
    return os;
}

istream& operator>>(istream &is, Film &F)
{
    is >> F.nom >> F.genere;
    return is;
}