#include"coneteneur.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <stdexcept>

using namespace std;


Conteneur::~Conteneur() {
    for (Personne* p : tab) {
        delete p;
    }
    tab.clear();
}

Conteneur::Conteneur(const Conteneur& other) {
    for (const Personne* p : other.tab) {
        if (typeid(*p) == typeid(Donateur)) {
            tab.push_back(new Donateur(*dynamic_cast<const Donateur*>(p)));
        }
        else if (typeid(*p) == typeid(Membre)) {
            tab.push_back(new Membre(*dynamic_cast<const Membre*>(p)));
        }
        else if (typeid(*p) == typeid(Administrateur)) {
            tab.push_back(new Administrateur(*dynamic_cast<const Administrateur*>(p)));
        }
        else {
            tab.push_back(new Personne(*p));
        }
    }
}
void Conteneur::ouvrirFichier(const string& nomFichier) {
    try {
        fstream fichier;
        fichier.open(nomFichier, ios::in | ios::out | ios::trunc);

        if (!fichier.is_open()) {
            throw runtime_error("Impossible d'ouvrir le fichier: " + nomFichier);
        }

        fichier.close();
    }
    catch (const exception& e) {
        cerr << "Erreur dans ouvrirFichier: " << e.what() << endl;
        throw;
    }
}

void Conteneur::copierFichierVersVector(const string& nomFichier) {
    fstream f;
    f.open(nomFichier, ios::in);
    if (!f.is_open()) exit(-1);

    f >> this;
    f.close();
}


void Conteneur::CopierVectorVersFichier(const string& filename) {

    fstream f;
    f.open(filename, ios::out | ios::trunc);
    if (!f.is_open()) exit(-1);

    f << this;
    f.close();
}

ostream& operator<<(ostream& out, Conteneur& w) {

    for (size_t i = 0; i < w.tab.size(); i++) {
        if (typeid(*w.tab[i]) == typeid(Donateur)) {
            out << "\n ***** Donateur **** \n" << *dynamic_cast<Donateur*>(w.tab[i]) << endl;
        }
        else if (typeid(*w.tab[i]) == typeid(Membre)) {
            out << "\n **** Membre *****  \n " << *dynamic_cast<Membre*>(w.tab[i]) << endl;
        }
        else if (typeid(*w.tab[i]) == typeid(Administrateur)) {
            out << "\n **** Administrateur ****\n " << *dynamic_cast<Administrateur*>(w.tab[i]) << endl;
        }
        else if (typeid(*w.tab[i]) == typeid(Personne)) {
            out << "\n **** Personne **** \n " << *w.tab[i] << endl;
            cout << endl<<"--------------------------------------------------" << endl;

        }
    }
    return out;

}
ostream& operator<<(ostream& out, Conteneur* c) {

     for (size_t i = 0; i < c->tab.size(); i++) {
        if (typeid(*c->tab[i]) == typeid(Donateur)) {
            out << "1 " << dynamic_cast<Donateur*>(c->tab[i]) << endl;
        }
        else if (typeid(*c->tab[i]) == typeid(Membre)) {
            out << "2 " << dynamic_cast<Membre*>(c->tab[i]) << endl;
        }
        else if (typeid(*c->tab[i]) == typeid(Administrateur)) {
            out << "3 " << static_cast<Administrateur*>(c->tab[i]) << endl;
        }
        else if (typeid(*c->tab[i]) == typeid(Personne)) {
            out << "4 " << c->tab[i] << endl;
        }
    }
    return out;
}

istream& operator>>(istream& in, Conteneur& w) {
    int choix;
    char rep;
    do {
        cout << "\nTaper 1: Donateur, 2: Membre, 3: Administrateur, 4: Personne     " ;
        in >> choix; cout<<endl;

        if (choix == 1) {
            Donateur* q = new Donateur();
            in >> *q;
            w.tab.push_back(q);
        }
        else if (choix == 2) {
            Membre* q = new Membre();
            in >> *q;
            w.tab.push_back(q);
        }
        else if (choix == 3) {
            Administrateur* q = new Administrateur();
            in >> *q;
            w.tab.push_back(q);
        }
        else if (choix == 4) {
            Personne* q = new Personne();
            in >> *q;
            w.tab.push_back(q);
        }

        cout << "\nAjouter une autre personne ? (o/n)" << endl;
        in >> rep;
    } while (rep == 'o' || rep == 'O');

    return in;

}

istream& operator>>(istream& in, Conteneur* w) {
    int choix;
    in.seekg(0);
    while (1) {
        in >> choix;
        if (in.eof()) break;

        if (choix == 1) {
            Donateur* q = new Donateur();
            in >> q;
            w->tab.push_back(q);
        }
        else if (choix == 2) {
            Membre* q = new Membre();
            in >> q;
            w->tab.push_back(q);
        }
        else if (choix == 3) {
            Administrateur* q = new Administrateur();
            in >> q;
            w->tab.push_back(q);
        }
        else if (choix == 4) {
            Personne* q = new Personne();
            in >> q;
            w->tab.push_back(q);
        }
    }
    return in;
}



void Conteneur::modifierdansFichier(const string& nom, const string& nomFichier) {

    copierFichierVersVector(nomFichier);
    bool found = false;
    for (size_t i = 0; i < tab.size(); ++i) {
        if (tab[i]->getNom() == nom) {
            found = true;
            cout << "\n=== PERSONNE TROUVEE ===" << endl;
            cout<<*tab[i];

            cout << "\nVoulez-vous modifier cette personne? (o/n) ";
            char choix;
            cin >> choix;
            cin.ignore();

            if (tolower(choix) == 'o') {
                cout << "\n=== NOUVELLES VALEURS ===" << endl;

                Personne* nouvellePersonne = nullptr;

                if (dynamic_cast<Donateur*>(tab[i]) != nullptr) {
                    nouvellePersonne = new Donateur();
                    cout << "Entrez les nouvelles informations du donateur:" << endl;
                    cin >> *dynamic_cast<Donateur*>(nouvellePersonne);
                }
                else if (dynamic_cast<Membre*>(tab[i]) != nullptr) {
                    nouvellePersonne = new Membre();
                    cout << "Entrez les nouvelles informations du membre:" << endl;
                    cin >> *dynamic_cast<Membre*>(nouvellePersonne);
                }
                else if (dynamic_cast<Administrateur*>(tab[i]) != nullptr) {
                    nouvellePersonne = new Administrateur();
                    cout << "Entrez les nouvelles informations de l'administrateur:" << endl;
                    cin >> *dynamic_cast<Administrateur*>(nouvellePersonne);
                }
                else {
                    nouvellePersonne = new Personne();
                    cout << "Entrez les nouvelles informations de la personne:" << endl;
                    cin >> *nouvellePersonne;
                }

                delete tab[i];
                tab[i] = nouvellePersonne;

                CopierVectorVersFichier(nomFichier);
                cout << "\nModification effectuee avec succes et sauvegardee!" << endl;
            } break;
        }

    }

    if (!found) {
        cout << "Aucune personne trouvee avec le nom: " << nom << endl;
    }
}

