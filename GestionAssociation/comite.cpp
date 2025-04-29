#include "comite.h"
#include <iostream>
#include <algorithm>
using namespace std;
#include<iomanip>
#include <fstream>


void ComiteAdministration::chargerDepuisFichier(const string& nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        cerr << "Erreur: Impossible d'ouvrir le fichier " << nomFichier << endl;
        return;
    }

    for (auto admin : administrateurs) {
        delete admin;
    }
    administrateurs.clear();

    fichier >> this;

    fichier.close();
}

void ComiteAdministration::sauvegarderDansFichier(const string& nomFichier) const {
    ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        cerr << "Erreur: Impossible d'ouvrir le fichier " << nomFichier << endl;
        return;
    }

    fichier << nombreMembres << endl;

    for (const auto& admin : administrateurs) {
        if (admin) {
            fichier << admin;
        }
    }

    fichier.close();
}

ostream& operator<< (ostream& out, ComiteAdministration* c)
{
    out << setw(10) << c->nombreMembres;
    for (auto admin : c->administrateurs) {
        out << " " << admin;
    }
    return out;
}

istream& operator>> (istream& in, ComiteAdministration* c)
{
    in >> c->nombreMembres;
    for (auto admin: c->administrateurs) delete admin;
    c->administrateurs.clear();
    for (int i = 0; i < c->nombreMembres; i++) {
        Administrateur* admin = new Administrateur();
        in >> admin;
        c->administrateurs.push_back(admin);
    }
    return in;
}



ComiteAdministration::~ComiteAdministration() {
    for (auto admin : administrateurs) delete admin;
}

ostream& operator<<(ostream& os, const ComiteAdministration& comite) {
    os << "Comite avec " << comite.nombreMembres << " membres:" << endl;
    for (auto admin : comite.administrateurs) {
        os << *admin;
        cout << "--------------------------------------------------" << endl;
    }
    return os;
}

istream& operator>>(istream& is, ComiteAdministration& comite) {
    int nm;
    cout << "Entrez le nombre d'administrateurs: ";
    is >> nm;
    comite.administrateurs.clear();
    for (int i = 0; i < nm; ++i) {
        cout << "\nAdministrateur #" << i+1 << ":" << endl;
        Administrateur* admin = new Administrateur();
        is>> *admin;
        comite.administrateurs.push_back(admin);
    }
    comite.nombreMembres = comite.administrateurs.size();
    return is;
}


void ComiteAdministration::operator+=(Administrateur* admin) {
    administrateurs.push_back(admin);
    nombreMembres = administrateurs.size();
}
void ComiteAdministration::ajouterAdministrateur(Administrateur* admin) {
    administrateurs.push_back(admin);
    nombreMembres = administrateurs.size();
}

void ComiteAdministration::supprimerAdministrateur(size_t i) {
    if (i < 0 || i >= administrateurs.size()) return;

    auto it = administrateurs.begin();
    advance(it, i);
    administrateurs.erase(it);
    nombreMembres = administrateurs.size();
}
