#include "RapportFinancier.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include "fondDediee.h"
#include <iostream>
#include "rapportFinancier.h"

RapportFinancier::RapportFinancier() {
    annee=0;
    totalDepenses=0;
    totalRevenus=0;
    fondsDediesMap[""] = new FondsDedies();

}
RapportFinancier::RapportFinancier(int a, double td, double tr)
    {annee=a; totalDepenses=td;totalRevenus=tr;
    int nbFonds;
    cout << "Nombre de fonds dedies pour l'annee " << annee << " : ";
    cin >> nbFonds;

    for (int i = 0; i < nbFonds; ++i) {
        string nom;
        FondsDedies* fonds = new FondsDedies();

        cout << "Nom du fonds " << i + 1 << " : ";
        cin >> ws;
        cin >> nom;

        cout << "Donnees du fonds :\n";
        cin >> *fonds;

        fondsDediesMap[nom] = fonds;
    }
}
RapportFinancier::RapportFinancier(const RapportFinancier& autre)
    {
        annee=autre.annee; totalDepenses=autre.totalDepenses; totalRevenus=autre.totalRevenus;
    for (const auto& [nom, fonds] : autre.fondsDediesMap) {
        fondsDediesMap[nom] = new FondsDedies(*fonds);
    }
}
int RapportFinancier::getAnnee() { return annee; }
void RapportFinancier::setAnnee(int a) { annee = a; }

double RapportFinancier::getTotalDepenses()
 { return totalDepenses; }
void RapportFinancier::setTotalDepenses(double td)
         { totalDepenses = td; }

double RapportFinancier::getTotalRevenus()
         { return totalRevenus; }
void RapportFinancier::setTotalRevenus(double tr)
             { totalRevenus = tr; }

map<string, FondsDedies*> RapportFinancier::getFondsDediesMap() { return fondsDediesMap; }
void RapportFinancier::setFondsDediesMap(const map<string, FondsDedies*>& fdMap) {

    for (auto& [nom, fonds] : fondsDediesMap) {
        delete fonds;
    }
    fondsDediesMap.clear();
    fondsDediesMap = fdMap;
}


ostream& operator<<(ostream& os, const RapportFinancier& rf) {
    os << "Annee : " << rf.annee << endl;
    os << "Depenses : " << rf.totalDepenses << endl;
    os << "Revenus : " << rf.totalRevenus << endl;
    os << "Fonds dedies : " << endl;
    for (const auto& [destinataire, fonds] : rf.fondsDediesMap) {
        os << "Destinataire: " << destinataire << "\n" << *fonds << endl;
    }
    return os;
}

istream& operator>>(istream& is, RapportFinancier& rf) {
    cout << "Annee : ";
    is >> rf.annee;

    cout << "Total Depenses : ";
    is >> rf.totalDepenses;

    cout << "Total Revenus : ";
    is >> rf.totalRevenus;

    int n;
    cout << "Nombre de fonds dedies : ";
    is >> n;


    for (int i = 0; i < n; ++i) {
        FondsDedies f ;
        string dest;
        cout << "Fonds " << (i + 1) << " - Destinataire : ";
        cin >> dest;
        cout << "Entrer Details du fonds :\n";
        is >> f;

        rf.fondsDediesMap[dest] = new FondsDedies(f);
    }

    return is;
}

