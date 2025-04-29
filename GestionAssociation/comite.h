#pragma once
#include <list>
#include <string>
#include "admin.h"
#include <iostream>
#include <algorithm>

using namespace std;

class ComiteAdministration {
private:
    int nombreMembres;
    list<Administrateur*> administrateurs;

public:
    friend ostream& operator<< (ostream&, ComiteAdministration*);
    friend istream& operator>> (istream&, ComiteAdministration*);

    void operator+=(Administrateur* admin);

    friend ostream& operator<<(ostream& os, const ComiteAdministration& comite);
    friend istream& operator>>(istream& is, ComiteAdministration& comite);

    ComiteAdministration() {nombreMembres = 0;}

    ComiteAdministration(int nm){
     nombreMembres=nm;
     for (int i = 0; i < nombreMembres; ++i) {
            Administrateur* admin = new Administrateur();
            administrateurs.push_back(admin);
            }
    }

    ComiteAdministration(const ComiteAdministration& comite){
    nombreMembres=comite.nombreMembres;
    for (auto admin : comite.administrateurs) {
        administrateurs.push_back(new Administrateur(*admin));
        }
    }

    int getNombreMembres() const { return nombreMembres; }
    void setNombreMembres(int newNombreMembres) { nombreMembres = newNombreMembres; }

    list<Administrateur*> getAdministrateurs() const { return administrateurs; }
    void setAdministrateurs(const list<Administrateur*>& newAdministrateurs) {
        administrateurs = newAdministrateurs;
        nombreMembres = administrateurs.size();
    }

    void ajouterAdministrateur(Administrateur*);
    void supprimerAdministrateur(size_t);

    void afficher() {
    cout << "Comité Administration : " << "nombre des membres: " << nombreMembres << endl;
      for_each(administrateurs.begin(), administrateurs.end(), [](Administrateur* admin)
             {if (admin) admin->afficher();} );
    }

    ~ComiteAdministration();


    void chargerDepuisFichier(const string&);
    void sauvegarderDansFichier(const string&) const;

};
