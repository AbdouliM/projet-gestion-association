#include "admin.h"
#include <iostream>
using namespace std;
#include<iomanip>

ostream& operator<< (ostream& out, Administrateur* a)
{
    out << static_cast<Personne*>(a) << " "
        << setw(20) << a->responsabilites << " "
        << setw(15) << a->dateNomination;
    return out;
}

istream& operator>> (istream& in, Administrateur* a)
{
    in >> static_cast<Personne*>(a);
    in>> a->responsabilites;
    in >> a->dateNomination;
    return in;
}


ostream& operator<<(ostream& out, Administrateur& a) {
    out << static_cast<const Personne&>(a);
    out << "Responsabilites : " << a.getResponsabilites() << endl;
    out << "Date de nomination : " << a.getDateNomination() << endl;
    cout << endl<<"--------------------------------------------------" << endl;
    return out;
}

istream& operator>>(istream& is, Administrateur& admin) {
    is >> static_cast<Personne&>(admin);
    cout << "Responsabilites : ";
    is >> admin.responsabilites;
    cout << "Date de nomination : ";
    is>>admin.dateNomination;
    return is;
}

string Administrateur::getResponsabilites() {
    return responsabilites;
}

void Administrateur::setResponsabilites(const string& newResponsabilites) {
    responsabilites = newResponsabilites;
}

string Administrateur::getDateNomination() {
    return dateNomination;
}

void Administrateur::setDateNomination(const string& newDateNomination) {
    dateNomination = newDateNomination;
}

Administrateur::~Administrateur() {}

