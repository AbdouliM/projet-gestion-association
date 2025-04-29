#include "projet.h"
#include <iostream>
#include<iomanip>

using namespace std;


ostream& operator<< (ostream& out, Projet* p)
{
    out<<setw(10)<< p->nom<<" "<<setw(10)<<p->description;
    return out;
}

istream& operator>> (istream& in, Projet* p)
{
    in >> p->nom>>p->description;
    return in;
}
Projet::Projet(const Projet& p) {
    nom = p.nom;
    description = p.description;  }

istream& operator>>(istream& in, Projet& p) {
    cout << "Nom du projet : ";
    in >>  p.nom;

    cout << "Description du projet : ";
    in>> p.description;

    return in;
}

ostream& operator<<(ostream& out, const Projet& p) {
    out << "Nom : " << p.nom << endl;
    out << "Description : " << p.description << endl;
    return out;
}

void Projet::afficher() {
    cout << "Projet - Nom : " << nom << ", Description : " << description << endl;
}
