# pragma once
#include<string>
#include<iostream>
using namespace std;
#include<vector>
#include"projet.h"
class Personne {
protected:
    string nom;
    string prenom;
    string dateNaissance;
    vector<Projet*> projets;

public:
    friend ostream& operator<< (ostream&, Personne*);
    friend istream& operator>> (istream&, Personne*);


    bool operator==(const Personne& p) const;

    friend istream& operator>>(istream& in, Personne& p);
    friend ostream& operator<<(ostream& out, const Personne& p);

    Personne(){nom="";prenom="";dateNaissance="";}
    Personne(const string& n, const string& p, const string& d){
    nom = n; prenom = p; dateNaissance = d;
    for (size_t i = 0; i < projets.size(); ++i) {
        Projet* projet = new Projet;
        cout << "Entrez le nom du projet #" << i + 1 << ": ";
        cin >> *projet;
        projets.push_back(projet);
       }
    }

    Personne(const Personne& p) {
        nom = p.nom; prenom = p.prenom; dateNaissance = p.dateNaissance;

        for (auto projet : p.projets) {
          projets.push_back(new Projet(*projet));
          }
     }
    Personne& operator=(const Personne& autre) {
    if (this != &autre) {
        nom = autre.nom;
        prenom = autre.prenom;
        dateNaissance = autre.dateNaissance;

        for (auto projet : projets) {
            delete projet;
        }
        projets.clear();

        for (auto projet : autre.projets) {
            projets.push_back(new Projet(*projet));
        }
    }
    return *this;
}
    virtual ~Personne() ;
    virtual void afficher() const =0;
    void ajouterProjet(const Projet& );

    string getNom(){ return nom; }
    void setNom(const string& n) { nom = n; }

    string getPrenom() { return prenom; }
    void setPrenom(const string& p) { prenom = p; }

    string getDateNaissance() { return dateNaissance; }
    void setDateNaissance(const string& d) { dateNaissance = d; }

    vector<Projet*> getprojets()  { return projets; }
    void setprojets (const vector<Projet*>& newP) { projets = newP; }
};
