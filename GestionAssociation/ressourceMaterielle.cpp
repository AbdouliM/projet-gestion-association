#include "ressourceMaterielle.h"

#include <iostream>
#include <fstream>
#include <typeinfo>
#include <stdexcept>
#include <iomanip>
using namespace std;

int RessourceMaterielle :: qtttotale=0;




ostream& operator<<(ostream& os, const RessourceMaterielle& rm) {
    os << static_cast<const Ressource&>(rm);

    os << "Nom : " << rm.nom << endl;
    int x=rm.quantite;
    os << "Quantite : " << x << endl;
    os << "etkkkkkkkat : " << rm.etat << endl;
    os << "Stocks :\n";
    for (Stock* s : rm.vstock) {
        os << *s << endl;
    }
    return os;
}

istream& operator>>(istream& is, RessourceMaterielle& rm) {

    is >> static_cast<Ressource&>(rm);

    cout << "Nom de Ressource Materielle : ";
    is >> rm.nom;

    cout << "Quantite : ";
    is >> rm.quantite;

    cout << "Etat : ";
    is >> rm.etat;

    cout << "Nombre d'elements dans le stock : ";
    int nbStocks;
    is >> nbStocks;

    for (Stock* s : rm.vstock) delete s;
    rm.vstock.clear();

    for (int i = 0; i < nbStocks; ++i) {
        Stock* s = new Stock();
        cout << "Stock " << i + 1 << " :\n";
        is >> *s;
        rm.vstock.push_back(s);
    }

    return is;
}



void RessourceMaterielle::ajouterStock( Stock* s) {
    vstock.push_back(s);
    quantite += s->getQuantiteDisponible();
    qtttotale += s->getQuantiteDisponible();
}



void RessourceMaterielle::viderStock() {
    for (Stock* s : vstock) {
        delete s;
    }
    vstock.clear();
    qtttotale -= quantite;
    quantite = 0;
    etat = "Inexistant";
}
RessourceMaterielle::~RessourceMaterielle()  {
    for (Stock* s : vstock) {
        delete s;
    }
    vstock.clear();
    qtttotale -= quantite;
}
 ostream& operator<<(ostream& os, const RessourceMaterielle* rm){
    os<<  static_cast < const Ressource*>(rm);


    os <<  " "<<setw (10)<< rm->nom <<" "<<setw (10)<<rm->quantite << " "<<setw (10) << rm->etat<< " "<<setw (10)<<rm->vstock.size();
    for (Stock* s : rm->vstock) {
        os << " " <<setw (10)<< s;
    }
    return os;
}
istream& operator>>(istream& is, RessourceMaterielle* rm){


    is >> static_cast<Ressource*>(rm);
    is >> rm->nom>> rm->quantite>> rm->etat;
    int nbStocks;
    is >> nbStocks;

    for (Stock* s : rm->vstock) delete s;
    rm->vstock.clear();

    for (int i = 0; i < nbStocks; ++i) {
        Stock* s = new Stock();
        is >> s;
        rm->vstock.push_back(s);
    }

    return is;
}





