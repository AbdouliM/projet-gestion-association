#include "dons.h"
#include <iostream>
#include<iomanip>

ostream& operator<< (ostream& out, Dons* d)
{
    out << setw(10) << d->montant << " "
        << setw(10) << d->date << " "
        << setw(10) << d->type;
    return out;
}

istream& operator>> (istream& in, Dons* d)
{
    in >> d->montant;
    in >> d->date;
    in >> d->type;
    return in;
}

void Dons::afficher()  {
    cout << "Don :"<<endl<<"Montant:"<<montant<<endl<<"date"<<date<<endl<<"Type"<<type<<endl;
}

istream& operator>>(istream& in, Dons& d) {
    cout << "Montant: ";
    in >> d.montant;
    cout << "Date: ";
    in >> d.date;
    cout << "Type: ";
    in >> d.type;

    return in;
}

ostream& operator<<(ostream& out, const Dons& d) {
    out << "Montant: " << d.montant << endl;
    out << "Date: " << d.date << endl;
    out << "Type: " << d.type << endl;

    return out;
}
