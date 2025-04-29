#include "membreactif.h"
#include <iostream>
using namespace std;
#include<iomanip>

ostream& operator<< (ostream& out, MembreActif* m) {
    if (!m) return out;

    out << static_cast<Membre*>(m) << " ";
    out << static_cast<Donateur*>(m) << " ";
    out << setw(5) << m->nombreHeuresBenevolat << " "<< setw(20) << m->specialite;

    return out;
}
istream& operator>> (istream& in, MembreActif* m) {
    if (!m) return in;

    in >> static_cast<Membre*>(m);
    in >> static_cast<Donateur*>(m);

    in >> m->nombreHeuresBenevolat;
    in >> m->specialite;

    return in;
}

istream& operator>>(istream& in, MembreActif& m) {
    //in >> static_cast<Membre&>(m);
    in >> static_cast<Donateur&>(m);

    cout<<"Role: "; in>>m.role ;
    cout<< endl<<  "Date adhesion: " ; in>>m.dateAdhesion;

    cout << endl<< "Nombre d'heures de benevolat : ";
    in >> m.nombreHeuresBenevolat;
    cout << "Specialite : ";
    in >> m.specialite;

    return in;
}

ostream& operator<<(ostream& out, const MembreActif& m) {
   // out << static_cast<const Membre&>(m);
    out << static_cast<const Donateur&>(m);
    out<< "Role: " << m.role <<endl<< "Date adhesion: " << m.dateAdhesion;

    out << "Nombre d'heures de benevolat : " << m.nombreHeuresBenevolat << endl;
    out << "Specialite : " << m.specialite << endl;

    return out;
}
