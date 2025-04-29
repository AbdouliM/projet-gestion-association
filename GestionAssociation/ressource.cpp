#include "ressource.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <stdexcept>
using namespace std;
#include<iomanip>

istream& operator>>(istream& in, Ressource& r) {
    cout << "Date : ";
    in >> r.date;

    cout << "Type : ";
    in >> r.type;

    for (Projet* p : r.projets) delete p;
    r.projets.clear();

    cout << "Nombre de projets à ajouter : ";
    int nbProjets;
    in >> nbProjets;

    for (int i = 0; i < nbProjets; ++i) {
        Projet* p = new Projet();
        cout << "Projet " << i + 1 << " : " << endl;
        in >> *p;
        r.projets.push_back(p);
    }

    return in;
}





ostream& operator<<(ostream& out, const Ressource& r) {
    out << "Ressource: " << endl;
    out << "Date: " << r.date << endl;
    out << "Type: " << r.type << endl;
    out << "Projets associes: " << endl;
    for (Projet* p : r.projets) {
        out << *p;
    }
    return out;
}

void Ressource::supprimerProjetParNom(const string& nomProjet) {
    bool trouve = false;
    for (auto it = projets.begin(); it != projets.end(); ++it) {
        if ((*it)->getNom() == nomProjet) {
            delete *it;
            projets.erase(it);
            cout << "Projet supprime : " << nomProjet << endl;
            trouve = true;
            break;
        }
    }
    if (!trouve) {
        cout << "Aucun projet avec ce nom trouve." << endl;
    }
}
 ostream& operator<<(ostream& os, const Ressource* r) {
    os <<setw(10)<< r->date << " "<<setw (10) << r->type << " "<<setw (10)<<r->projets.size();
    for (Projet* p : r->projets) {
        os << " "<<setw (10)<< p ;
    }
    return os;
}
istream& operator>>(istream& in, Ressource* r) {

in>> r->date >> r->type ;
 size_t nbProjets;
    in >> nbProjets;
    r->projets.clear();
    for (size_t i = 0; i < nbProjets; i++) {
        Projet* projet = new Projet();
        in >> projet;
        r->projets.push_back(projet);
    }

    return in;
}



