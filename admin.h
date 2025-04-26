#pragma once
#include "personne.h"
#include <string>
using namespace std;

#include <vector>

class Administrateur : public Personne {
protected:
    string responsabilites;
    string dateNomination;

public:
    friend ostream& operator<< (ostream&, Administrateur*);
   friend istream& operator>> (istream&, Administrateur*);


     Administrateur() : Personne(), responsabilites(""), dateNomination("") {}

    Administrateur(const string& n, const string& p, const string& d, const string& r, const string& dateN)
        : Personne(n, p, d), responsabilites(r), dateNomination(dateN) {}

    Administrateur(const Administrateur& a)
        : Personne(a), responsabilites(a.responsabilites), dateNomination(a.dateNomination) {}

    friend ostream& operator<<(ostream& os, Administrateur& admin);
    friend istream& operator>>(istream& is, Administrateur& admin);

    string getResponsabilites();
    void setResponsabilites(const string& newResponsabilites);

    string getDateNomination();
    void setDateNomination(const string& newDateNomination);

    ~Administrateur();
    void afficher() ;
};
