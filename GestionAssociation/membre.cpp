#include "membre.h"
#include <iostream>
using namespace std;
#include<iomanip>
int Membre::nbmembres = 0;


ostream& operator<< (ostream& out, Membre* m)
{
    out << static_cast<Personne*>(m) << " "
        << setw(10) << m->role << " "
        << setw(10) << m->dateAdhesion;
    return out;
}

istream& operator>> (istream& in, Membre* m)
{
    in >> static_cast<Personne*>(m);
    in >> m->role;
    in >> m->dateAdhesion;
    return in;
}


istream& operator>>(istream& in, Membre& m) {
    in >> static_cast<Personne&>(m);
    cout << "Role: ";
    in >> m.role;
    cout << "Date d'adhesion (JJ/MM/AAAA): ";
    in>> m.dateAdhesion;
    return in;
}

ostream& operator<<(ostream& out, const Membre& m) {
    out << static_cast<const Personne&>(m);
    out << "Role: " << m.role << "\n"
        << "Date d'adhesion: " << m.dateAdhesion << "\n"
        << "--------------------------------------------------\n";
    return out;
}










