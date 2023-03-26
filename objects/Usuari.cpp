#include "Usuari.hpp"
#include "Film.hpp"

// IMPLMENTACIÓ DE LA CLASSE USUARI

Usuari::Usuari()
{
    nickname = "";
    nVal = 0;
    id = 0;
}

Usuari::Usuari(const Usuari& u)
{
    nickname = u.nickname;
    nVal = u.nVal;
    id = u.id;
}

Usuari::~Usuari() { 
}

string Usuari::getNickname() const
{
    return nickname;
}

Usuari& Usuari::operator=(const Usuari& U)
{
    nickname = U.nickname;
    id = U.id;
    nVal = U.nVal;
    return *this;
}

void Usuari::incValorations()
{
    ++nVal;
}

void Usuari::setID(int id)
{
    this->id = id;
}

ostream& operator<<(ostream &os, const Usuari &U){
    os << " " << U.id << " | " << U.nickname << " | " << U.nVal << endl;
    return os;
}

istream& operator>>(istream &is, Usuari &U){
    is >> U.nickname;
    return is;
}