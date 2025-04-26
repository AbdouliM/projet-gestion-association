#include "personne.h"
#include <iostream>
using namespace std;
#include<iomanip>


ostream& operator<< (ostream& out, Personne* p)
{
    out <<setw(10) << p->nom << setw(10) <<  p->prenom << setw(10) << " " << p->dateNaissance;
    out << " " << setw(10) << p->projets.size();
    for (auto projet : p->projets) {
        out << " " <<setw(10)  << projet;
    }
    return out;
}

istream& operator>> (istream& in, Personne* p)
{
    in >>p->nom >> p->prenom >> p->dateNaissance;

    size_t nbProjets;
    in >> nbProjets;

    p->projets.clear();
    for (size_t i = 0; i < nbProjets; i++) {
        Projet* projet = new Projet();
        in >> projet;
        p->projets.push_back(projet);
    }

    return in;
}
bool Personne::operator==(const Personne& p) const {
    return (nom == p.nom && prenom == p.prenom && dateNaissance == p.dateNaissance);
}
void Personne::afficher() const {
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "Date de Naissance: " << dateNaissance << endl;

    cout << "Projets:" << endl;
    for (size_t i = 0; i < projets.size(); i++) {
        cout << "--------------------------------------------------" << endl;
        if (projets[i] != nullptr) {
            projets[i]->afficher();
        }
        cout << "--------------------------------------------------" << endl;

    }
}

void Personne::ajouterProjet(const Projet& p) {
    projets.push_back(new Projet(p));
}

istream& operator>>(istream& in, Personne& p) {
    cout << "Entrez le nom : ";
    in >> p.nom;
    cout << "Entrez le prenom : ";
    in >> p.prenom;
    cout << "Entrez la date de naissance : ";
    in >> p.dateNaissance;
    int nbProjets;
    cout << "Nombre de projets : ";
    in >> nbProjets;

    for (int i = 0; i < nbProjets; ++i) {
        Projet* projet = new Projet;
        cout <<endl<< "Projet #" << i + 1 << " : " << endl;
        in >> *projet;
        p.projets.push_back(projet);
    }

    return in;
}

ostream& operator<<(ostream& out, const Personne& p) {
    out << "Nom : " << p.nom << endl;
    out << "Prenom : " << p.prenom << endl;
    out << "Date de naissance : " << p.dateNaissance << endl;
if (p.projets.size()==0 ) { out << "Aucun projet" << endl;
return out;}
    out << "Projets : " << endl<<endl;
    for (size_t i = 0; i < p.projets.size(); ++i) {
        out << "Projet " << i + 1 << " : "<<endl;
        if (p.projets[i] != nullptr) out << *p.projets[i] << endl;

    }
    return out;
}
Personne::~Personne() {
    for (auto p : projets) delete p;
    projets.clear();
}
