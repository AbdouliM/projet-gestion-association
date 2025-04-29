#include "revenueDonation.h"
#include <iostream>
#include<iomanip>
 ostream& operator<<(ostream& os, const RevenueDonation& don) {

    os << static_cast<const Ressource&>(don);
    os << "Montant : " << don.montant << "\n";
    os << "Moyen de donation : " << don.moyenDonation << "\n";
    return os;
}

istream& operator>>(istream& is, RevenueDonation& don) {
    is >> static_cast<Ressource&>(don);
    cout << "Montant : ";
    is >> don.montant;
    cout << "Moyen de donation : ";
    is>> don.moyenDonation;
    return is;
}


bool RevenueDonation::estDonSignificatif(double seuil) {
    return montant >= seuil;
}
RevenueDonation& RevenueDonation::operator=(const RevenueDonation& other) {
    if (this != &other) {

        Ressource::operator=(other);


        montant = other.montant;
        moyenDonation = other.moyenDonation;
    }
    return *this;
}


ostream& operator<<(ostream& os, const RevenueDonation* don){
    os << static_cast<const Ressource*>(don);
    os <<  " "<<setw (10)<< don->montant <<" "<<setw (10)<< don->moyenDonation ;
    return os;

}
 istream& operator>>(istream& is, RevenueDonation* don){
      is >> static_cast<Ressource*>(don);
    is >> don->montant>>don->moyenDonation;
    return is;
}


