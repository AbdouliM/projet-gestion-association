#include "admin.h"
#include "comite.h"
#include "membreactif.h"
#include"coneteneur.h"
#include <fstream>
using namespace std;
#include <iostream>


void afficherMenu() {
    cout << "\n===== SYSTEME DE GESTION =====" << endl;
    cout << "1. Ajouter une personne" << endl;
    cout << "2. Afficher toutes les personnes" << endl;
    cout << "3. Rechercher et modifier une personne" << endl;
    cout << "4. Sauvegarder dans un fichier" << endl;
    cout << "5. Charger depuis un fichier" << endl;
    cout << "6. Rechercher et supprimer une personne" << endl;
    cout << "7. Quitter" << endl;
    cout << "Choix : ";
}


int main() {
/*
     Membre membre1;
     cin>>membre1;

    cout << "Membre 1 avant affectation: " << endl;
    cout<<membre1;

    Membre membre2;
    membre2 = membre1;

    cout << "Membre 2 après affectation: " << endl;
    cout<<membre2;

*/
Conteneur conteneur;
const string nomFichier = "personnes.txt";
int choix;

    do {
        afficherMenu();
        cin >> choix;
        try {
            switch(choix) {
                case 1:
                    cin >> conteneur;
                    break;

                case 2:
                    cout << "\n=== LISTE DES PERSONNES ===" << endl;
                    cout<<conteneur;
                    break;

                case 3: {
                    string nom;
                    cout << "Entrez le nom a rechercher: ";
                    cin>>nom;
                    conteneur.modifierdansFichier(nom, nomFichier);
                    break;
                }

                case 4:
                    conteneur.CopierVectorVersFichier(nomFichier);
                    cout << "Donnees sauvegardees dans " << nomFichier << endl;
                    break;

                case 5:
                    conteneur.copierFichierVersVector(nomFichier);
                    cout << "Donnees chargees depuis " << nomFichier << endl;
                    break;

                case 6:{
                    string nom;
                    cout << "Entrez le nom a rechercher: ";
                    cin>>nom;
                    conteneur.supprimerParNom(nom, nomFichier);
                    break;
                }
                case 7:
                    cout <<endl<< "Au revoir!" << endl;
                    break;
                default:
                    cout << "Choix invalide!" << endl;
            }
        } catch(const exception& e) {
            cerr << "Erreur: " << e.what() << endl;
        }

    } while(choix != 7);

////////////////////////////////////////////////////////////////////////////////
/*
ComiteAdministration comite;
cin>> comite;
int choix;

    do {
        cout << "\n===== MENU COMITE D'ADMINISTRATION =====" << endl;
        cout << "1. Afficher le comite " << endl;
        cout << "2. Ajouter un administrateur" << endl;
        cout << "3. Supprimer un administrateur" << endl;
        cout << "4. Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                cout << "Contenu du comite :" << endl;
                cout<<"-----------------------------------------------"<<endl;
                cout<<comite;
                break;
            }
            case 2: {
                Administrateur *admin=new Administrateur() ;
                cin >> *admin;
                comite+=admin;
                cout << "Administrateur ajoute avec succes !" << endl;

                break;
            }
            case 3: {
                size_t index;
                cout << "Index de l'administrateur a supprimer : ";
                cin >> index;
                comite.supprimerAdministrateur(index);
                break;
            }
            case 4:
                cout << "Fermeture du programme." << endl;
                break;
            default:
                cout << "Choix invalide, veuillez reessayer." << endl;
        }
    } while (choix != 4);
*/
////////////////////////////////////////////////////////////////////////////////
/*
vector<MembreActif> membres;
int choix;

    do {
        cout << "\n===== MENU MEMBRE ACTIF =====" << endl;
        cout << "1. Ajouter un membre actif" << endl;
        cout << "2. Afficher tous les membres actifs" << endl;
        cout << "3. Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                MembreActif m;  cin>>m;
                membres.push_back(m);
                cout << "Membre actif ajouté avec succès !" << endl;
                break;
            }

            case 2: {
                if (membres.empty()) {
                    cout << "Aucun membre actif enregistré." << endl;
                } else {
                    cout << "Liste des membres actifs :" << endl;
                    for (size_t i = 0; i < membres.size(); ++i) {
                        cout << "Membre #" << i + 1 << " :" << endl;
                        cout<<membres[i];
                    }
                }
                break;
            }

            case 3:
                cout << "Fermeture du programme." << endl;
                break;

            default:
                cout << "Choix invalide. Réessaie !" << endl;
        }

    } while (choix != 3);
*/
////////////////////////////////////////////////////////////////////////////////

    return 0;
}
