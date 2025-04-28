#pragma once
#include "personne.h"
#include<vector>
#include"dons.h"
#include<string>
#include<iostream>
using namespace std;
class Donateur : virtual public Personne {
protected:
    double nombreDons;
    vector<Dons*> dons;

public:
    friend ostream& operator<< (ostream&, Donateur*);
    friend istream& operator>> (istream&, Donateur*);

    friend istream& operator>>(istream& in, Donateur& d);
    friend ostream& operator<<(ostream& out, const Donateur& d);


    Donateur() : Personne() {nombreDons=0;}

    Donateur(const string& n, const string& p, const string& d, double nd): Personne(n, p, d){
     nombreDons=nd;
     for (int i = 0; i < nombreDons; i++) {
        Dons* don = new Dons();
        cout << "Saisir les informations du don numéro " << i + 1 << " : " << endl;
        cin >> *don;
        dons.push_back(don);
        }
    }

     Donateur(const Donateur& dona) : Personne(dona){
     nombreDons=dona.nombreDons;
     for (auto don : dona.dons)  dons.push_back(new Dons(*don));
     }

    void afficher() const override {
    cout << "Nombre de dons : " << nombreDons << endl;
    cout << "Liste des dons : " << endl;
    for (auto& don : dons) don->afficher();

    }
    void ajouterDon(const Dons&);
    double calculerTotalDons();
    double getNombreDons() { return nombreDons; }
    void setNombreDons(double nd) { nombreDons = nd; }

    vector<Dons*> getDons() { return dons; }
    void setDons(const vector<Dons*>& ds) { dons = ds; }
    ~Donateur();
};
