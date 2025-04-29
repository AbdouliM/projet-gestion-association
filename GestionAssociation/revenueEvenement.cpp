#include "revenueEvenement.h"
#include <iostream>
#include<iomanip>
  double RevenueEvenement::calculerRevenuNet(double tauxTaxe) {
        return (montantEv - (montantEv * tauxTaxe));
    }
ostream& operator<<(ostream& os, const RevenueEvenement& re) {
       os << static_cast<const Ressource&>(re);
    os << "Montant : " << re.montantEv << "\n";
    os << "Lieu : " << re.lieuEvenement << "\n";
    os << "Type : " << re.typeEvenement << "\n";
    return os;
}

istream& operator>>(istream& is, RevenueEvenement& re) {
    is >> static_cast<Ressource&>(re);
    cout << "Montant : ";
    is >> re.montantEv;

    cout << "Lieu : ";
    is>>re.lieuEvenement;

    cout << "Type : ";
    is>> re.typeEvenement;

    return is;
}
 ostream& operator<<(ostream& os, const RevenueEvenement* re){
    os << static_cast<const Ressource*>(re);
    os  << " "<<setw (10)<< re->montantEv << " "<<setw (10)<< re->lieuEvenement << " "<<setw (10)<< re->typeEvenement;
    return os;
}
 istream& operator>>(istream& is, RevenueEvenement* re){
        is >> static_cast<Ressource*>(re);
        is >> re->montantEv>>re->lieuEvenement>>re->typeEvenement;

    return is;
    }



