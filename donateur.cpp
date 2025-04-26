#include "donateur.h"
#include <iostream>
#include"dons.h"
#include<iomanip>

using namespace std;

ostream& operator<< (ostream& out, Donateur* d){
    out << static_cast<Personne*>(d);
    out << " " << setw(5) << d->nombreDons;
    for (auto don : d->dons) out << " " << don;
    return out;
}

istream& operator>> (istream& in, Donateur* d){
    in >> static_cast<Personne*>(d);
    in >> d->nombreDons;
    for (int i = 0; i < d->nombreDons; i++) {
        Dons* don = new Dons();
        in >> don;
        d->dons.push_back(don);
    }
    return in;
}

istream& operator>>(istream& in, Donateur& d) {
    in >> static_cast<Personne&>(d);
    cout << endl<<"Nombre de dons : ";
    in >> d.nombreDons;
    d.dons.clear();
    for (int i = 0; i < d.nombreDons; i++) {
        Dons* don = new Dons();
        cout << "Don #" << i + 1 << " : " << endl;
        in >> *don;
        d.dons.push_back(don);
    }

    return in;
}


ostream& operator<<(ostream& out, const Donateur& d) {
    out << static_cast<const Personne&>(d);
    out << "Nombre de dons: " << d.nombreDons << endl;
    out << "Dons: " << endl<<endl;
    if (d.nombreDons==0 ){
            cout<<"Aucun don";
            cout <<endl<< "--------------------------------------------------" << endl;
            return out;}
    int i=0;
    for (auto don : d.dons) {
        cout << "Don #" << i + 1 << " : " << endl;
        out << *don<<endl;
    }

    cout <<endl<< "--------------------------------------------------" << endl;

    return out;
}

void Donateur::afficher() {
    Personne::afficher();
    cout << "Nombre de dons : " << nombreDons << endl;
    cout << "Liste des dons : " << endl;
    for (auto& don : dons) don->afficher();

}

double Donateur::calculerTotalDons() {
    double total = 0;
    for ( auto& d : dons) {
        total += d->getMontant();
    }
    return total;
}

void Donateur::ajouterDon(const Dons& don) {
      dons.push_back(new Dons(don));
       nombreDons++;
}
Donateur::~Donateur() {
    for (auto don : dons) {
        delete don;
    }
    dons.clear();
}
