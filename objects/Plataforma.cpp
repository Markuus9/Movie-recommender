#include "Plataforma.hpp"

Plataforma::Plataforma()
{
    nom = "";	
}

Plataforma::~Plataforma()
{

}

bool Plataforma::alreadyInUsers(Usuari& User, vector<Usuari>& Users) const
{
    for (unsigned int i = 0; i < Users.size(); ++i) {
        if (Users[i].getNickname() == User.getNickname()) return true;
    }
    return false;
}

bool Plataforma::alreadyInFilms(Film& fi, vector<Film>& Fi) const
{
    for (unsigned int i = 0; i < Fi.size(); ++i) {
        if (Fi[i].GetName() == fi.GetName()) return true;
    }
    return false;
}

int Plataforma::partition(vector<Film>& v, int start, int end)
{
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
        if(v[i].GetFinalMark()<v[pivot].GetFinalMark()){
			swap(v[i],v[j]);
			++j;
		}
        else if(v[i].GetFinalMark() == v[pivot].GetFinalMark()) {
            if(v[i].GetName() > v[pivot].GetName()) {
                swap(v[i],v[j]);
                ++j;
            } 
        }
	}
	swap(v[j],v[pivot]);
	return j;
}
 
void Plataforma::quickSort(vector<Film>& v, int start, int end)
{
    if (start >= end)
        return;
 
    int p = partition(v, start, end);
 
    quickSort(v, start, p - 1);
    //H.I: La part esquerra del vector està ordenada de manera creixent (v[0]<v[1]<...<v[p-1]).
    quickSort(v, p + 1, end);
    //H.I: La part dreta del vector està ordenada de manera creixent (v[p+1]<v[p+2]<...<v[v.size()-1]).
}

void Plataforma::enregistrarValoracio()
{
    string usuari, film;
    int valoracio;
    cin >> usuari >> film >> valoracio;
    bool filmfound = false;
    bool userfound = false;
    unsigned int i = 0, j = 0, sizeu = Usuaris.size(), sizef = Films.size();
    cout << "Nova valoració:" << endl;

    if (valoracio > 5 or valoracio < 0) {
        cout << " Error: " << valoracio << " nombre de punts no vàlid, no s'ha afegit" << endl;
        return;
    }
    while (not userfound and i < sizeu) {
        if (Usuaris[i].getNickname() == usuari) userfound = true;
        else ++i;
    }
    if (not userfound) {
        cout << " Error: " << usuari << " usuari no enregistrat a " << nom << endl;
        return;
    }
    while (not filmfound and j < sizef) {
        if (Films[j].GetName() == film) filmfound = true;
        else ++j;
    }
    if (not filmfound) {
        cout << " Error: " << film << " film no enregistrat a " << nom << endl;
        return;
    }
    Usuaris[i].incValorations();
    Films[j].addmark(valoracio);
    cout << " " << usuari << ", " << film << ", " << valoracio << endl;
}

Plataforma& Plataforma::operator=(const Plataforma& P)
{
    Films = P.Films;
    Usuaris = P.Usuaris;
    nom = P.nom;
    return *this;
}

void Plataforma::llegirpelicules()
{
    int n;
    cin >> n;
    Film f;
    for (int i = 0; i < n; ++i) {
        cin >> f;
        if (alreadyInFilms(f, Films)) cout << " Error: " << f.GetName() << " film ja existent a " << nom << ", no s'ha afegit" << endl;
        else Films.push_back(f);
    }
}

void Plataforma::llegirusuaris()
{
    int n;
    cin >> n;
    Usuari u;
    int idcount = 1;
    for (int i = 0; i < n; ++i) {
        cin >> u;
        if (alreadyInUsers(u, Usuaris)) cout << " Error: " << u.getNickname() << " usuari ja existent a " << nom << ", no s'ha afegit" << endl;
        else {
            Usuaris.push_back(u);
            Usuaris[Usuaris.size()-1].setID(idcount);
            ++idcount;
        }
    }
}

void Plataforma::recomanarMillorFilm() const
{
    cout << "Film recomanat a " << nom << ":" << endl;
    unsigned int size = Films.size();
    if (size == 0) {
        cout << " No hi ha films enregistrats a " << nom << endl;
        return;
    }
    Film best = Films[0];
    for (unsigned int i = 1; i < size; ++i) {
        if (Films[i].GetFinalMark() > best.GetFinalMark()) {
            best = Films[i];
        }
        else if(Films[i].GetFinalMark() == best.GetFinalMark() and Films[i].GetName() < best.GetName()) {
            best = Films[i];
        }
    }
    cout << best;
}

void Plataforma::mostrarMillorsFilms()
{
    int n, size = Films.size();
    cin >> n;
    cout << "Films amb millors valoracions a " << nom << " (" << n << " millors):" << endl;
    if (size == 0) {
        cout << " No hi ha films amb valoracions a " << nom << endl;
        return;
    }
    if (n < 1) {
        cout << " Error: " << n << " valor no vàlid" << endl;
        return;
    }
    if (n > size) n = size;
    vector<Film> Aux = Films;   
    quickSort(Aux, 0, size - 1);
    for (int i = 0; i < n; i++) {
        cout << Aux[size-1-i];
    }
}

void Plataforma::mostrarFilms() const
{
    cout << "Films a " << nom << " (ordre d'alta):" << endl;
    if (Films.size() == 0) {
        cout << " No hi ha films enregistrats a " << nom << endl;
        return;
    }
    for (unsigned int i = 0; i < Films.size(); ++i) cout << Films[i];
}

void Plataforma::mostrarUsuaris() const
{
    cout << "Usuaris de " << nom << " (ordre d'alta):" << endl;
    if (Usuaris.size() == 0) {
        cout << " No hi ha usuaris enregistrats a " << nom << endl;
        return;
    }
    for (unsigned int i = 0; i < Usuaris.size(); ++i) cout << Usuaris[i];
}

void Plataforma::mostrarFilmsGenere() const
{
    bool found = false;
    string genere;
    cin >> genere;
    cout << "Films del gènere " << genere << " a " << nom << ":" << endl;
    if (Films.size() == 0) {
        cout << " No hi ha films enregistrats a " << nom << endl;
        return;
    }
    for (unsigned int i = 0; i < Films.size(); ++i) {
        if (Films[i].GetGenere() == genere) {
            cout << Films[i];
            found = true;
        }
    }
    if (not found) cout << " No hi ha films del gènere " << genere << " a " << nom << endl;
}

istream& operator>>(istream &is, Plataforma &P)
{
    is >> P.nom;
    return is;
}