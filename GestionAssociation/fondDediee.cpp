#include "fondDediee.h"
#include <iostream>
using namespace std;

istream& operator>>(istream& in, FondsDedies& f) {
    in >> static_cast<RevenueDonation&>(f);
   cout << "Montant : ";
    in >> f.montantEv;

    cout << "Lieu : ";
    in>>f.lieuEvenement;

    cout << "Type : ";
    in>> f.typeEvenement;

    cout << "Destinataire : ";
    string dest;
    in >> dest;
    f.setDestinataire(dest);

    cout << "ID : ";
    int id;
    in >> id;
    f.setId(id);

    return in;
}
ostream& operator<<(ostream& out, const FondsDedies& f) {

    out << static_cast<const RevenueDonation&>(f);
    out << "Montant : " << f.montantEv << "\n";
    out<< "Lieu : " << f.lieuEvenement << "\n";
    out << "Type : " << f.typeEvenement << "\n";

    cout << "Destinataire : " ;
    out<< f.getDestinataire() << endl;
    cout << "ID : " ;
    out<< f.getId() << endl;

    return out;
}
void FondsDedies::afficher() const {
    cout<< "destinataire"<<destinataire<<endl;
    cout<<"id"<<id<<endl;

}
