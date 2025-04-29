#include "ContenaireRessource.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <stdexcept>
#include "ressource.h"
#include "ressourceMaterielle.h"
#include "revenueDonation.h"
#include "revenueEvenement.h"
using namespace std;

ConteneurRessources::~ConteneurRessources() {
    for (Ressource* res : ressources) {
        delete res;
    }
    ressources.clear();
}

ConteneurRessources::ConteneurRessources(const ConteneurRessources& other) {
    for (const Ressource* res : other.ressources) {
        if (typeid(*res) == typeid(RessourceMaterielle)) {
            ressources.push_back(new RessourceMaterielle(*dynamic_cast<const RessourceMaterielle*>(res)));
        }
        else if (typeid(*res) == typeid(RevenueDonation)) {
            ressources.push_back(new RevenueDonation(*dynamic_cast<const RevenueDonation*>(res)));
        }
        else if (typeid(*res) == typeid(RevenueEvenement)) {
            ressources.push_back(new RevenueEvenement(*dynamic_cast<const RevenueEvenement*>(res)));
        }

    }
}


void ConteneurRessources::ouvrirFichier(const string& nomFichier) {
    try {
        fstream fichier;
        fichier.open(nomFichier, ios::in | ios::out | ios::trunc);
        if (!fichier.is_open()) {
            throw runtime_error("Erreur lors de l'ouverture du fichier");
        }

        fichier.close();
        cout << "Fichier ouvert avec succès : " << nomFichier << endl;

    } catch (const runtime_error& e) {
        cerr << "Exception attrapée : " << e.what() << endl;
    }
}

void ConteneurRessources::copierFichierVersVector(const string& nomFichier) {
    fstream f;
    f.open(nomFichier, ios::in);
    if (!f.is_open()) exit(-1);

    f >> this;
    f.close();
}

void ConteneurRessources::CopierVectorVersFichier(const string& nomFichier) {
   fstream f;
    f.open(nomFichier, ios::out | ios::trunc);
    if (!f.is_open()) exit(-1);

    f << this;
    f.close();
}


ostream& operator<<(ostream& out, ConteneurRessources& cr) {
    for (size_t i = 0; i < cr.ressources.size(); i++) {
        if (typeid(*cr.ressources[i]) == typeid(RessourceMaterielle)) {
            out << "\n ***** Ressource Materielle **** \n" << *dynamic_cast<RessourceMaterielle*>(cr.ressources[i]) << endl;
        }
        else if (typeid(*cr.ressources[i]) == typeid(RevenueDonation)) {
            out << "\n **** Revenue Donation *****  \n " << *dynamic_cast<RevenueDonation*>(cr.ressources[i]) << endl;
        }
        else if (typeid(*cr.ressources[i]) == typeid(RevenueEvenement)) {
            out << "\n **** Revenue Evenement ****\n " <<*dynamic_cast<RevenueEvenement*>(cr.ressources[i]) << endl;
        }
        else if (typeid(*cr.ressources[i]) == typeid(Ressource)) {
            out << "\n **** Ressource **** \n " << *cr.ressources[i] << endl;
            cout << endl<<"--------------------------------------------------" << endl;

        }
    }
    return out;
}

ostream& operator<<(ostream& out, ConteneurRessources* cr) {
        for (size_t i = 0; i < cr->ressources .size(); i++) {
        if (typeid(*cr->ressources[i]) == typeid(RessourceMaterielle)) {
            out << "1 " << dynamic_cast<RessourceMaterielle*>(cr->ressources[i]) << endl;
        }
        else if (typeid(*cr->ressources[i]) == typeid(RevenueDonation)) {
            out << "2 " << dynamic_cast<RevenueDonation*>(cr->ressources[i]) << endl;
        }
        else if (typeid(*cr->ressources[i]) == typeid(RevenueEvenement)) {
            out << "3 " << dynamic_cast<RevenueEvenement*>(cr->ressources[i]) << endl;
        }
        else if (typeid(*cr->ressources[i]) == typeid(Ressource)) {
            out << "4 " <<cr->ressources[i] << endl;
        }
    }
    return out;

}

istream& operator>>(istream& in, ConteneurRessources& cr) {
     int choix;
    char rep;
    do {
        cout << "\nTaper 1: Ressource Materielle, 2: Revenue Donation, 3: Revenue Evenement     " ;
        in >> choix; cout<<endl;

        if (choix == 1) {
           RessourceMaterielle* q = new RessourceMaterielle();
            in >> *q;
            cr.ressources.push_back(q);
        }
        else if (choix == 2) {
            RevenueDonation* q = new RevenueDonation();
            in >> *q;
            cr.ressources.push_back(q);
        }
        else if (choix == 3) {
            RevenueEvenement* q = new RevenueEvenement();
            in >> *q;
            cr.ressources.push_back(q);
        }

        cout << "\nAjouter une autre Ressource ? (o/n)" << endl;
        in >> rep;
    } while (rep == 'o' || rep == 'O');

    return in;

}

istream& operator>>(istream& in, ConteneurRessources* cr) {
    int choix;
    in.seekg(0);
    while (1) {
        in >> choix;
        if (in.eof()) break;

        if (choix == 1) {
            RessourceMaterielle* q = new RessourceMaterielle();
            in >> q;
            cr->ressources.push_back(q);
        }
        else if (choix == 2) {
            RevenueDonation* q = new RevenueDonation();
            in >> q;
           cr->ressources.push_back(q);
        }
        else if (choix == 3) {
            RevenueEvenement* q = new RevenueEvenement();
            in >> q;
            cr->ressources.push_back(q);
        }

    }
    return in;
}



void ConteneurRessources::modifierdansFichier(const string& date, const string& nomFichier) {

     copierFichierVersVector(nomFichier);
    bool found = false;
    for (size_t i = 0; i < ressources.size(); ++i) {
        if (ressources[i]->getDate() == date) {
            found = true;
            cout << "\n=== Ressource TROUVEE ===" << endl;
            cout<<*ressources[i];

            cout << "\nVoulez-vous modifier cette Ressource? (o/n) ";
            char choix;
            cin >> choix;
            cin.ignore();

            if (tolower(choix) == 'o') {
                cout << "\n=== NOUVELLES VALEUReS ===" << endl;

                Ressource* nouvelleress = nullptr;

                if (dynamic_cast<RessourceMaterielle*>(ressources[i]) != nullptr) {
                    nouvelleress = new RessourceMaterielle();
                    cout << "Entrez les nouvelles informations du Resssource Materielle:" << endl;
                    cin >> *dynamic_cast<RessourceMaterielle*>(nouvelleress);
                }
                else if (dynamic_cast<RevenueDonation*>(ressources[i]) != nullptr) {
                    nouvelleress = new RevenueDonation();
                    cout << "Entrez les nouvelles informations du Revenue donation:" << endl;
                    cin >> *dynamic_cast<RevenueDonation*>(nouvelleress);
                }
                else if (dynamic_cast<RevenueEvenement*>(ressources[i]) != nullptr) {
                    nouvelleress = new RevenueEvenement();
                    cout << "Entrez les nouvelles informations de Revenue evenement:" << endl;
                    cin >> *dynamic_cast<RevenueEvenement*>(nouvelleress);
                }


                delete ressources[i];
                  ressources[i] = nouvelleress;

                CopierVectorVersFichier(nomFichier);
                cout << "\nModification effectuee avec succes et sauvegardee!" << endl;
            } break;
        }

    }

    if (!found) {
        cout << "Aucune Ressource trouvee avec le nom: " << date << endl;
    }
}
void ConteneurRessources::supprimerPardate(const string& date, const string& nomFichier) {
    copierFichierVersVector(nomFichier);
    bool found = false;

    for (auto it = ressources.begin(); it != ressources.end(); ++it) {
        if ((*it)->getDate() == date) {
            found = true;
            cout << "\n=== Ressource TROUVEE ET SUPPRIMEE ===" << endl;
            cout << **it << endl;
            delete *it;
            ressources.erase(it);
            CopierVectorVersFichier(nomFichier);
            cout << "\n Suppression effectuee avec succes et sauvegardee!" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Aucune Ressource trouvee avec le nom: " << date << endl;
    }
}

