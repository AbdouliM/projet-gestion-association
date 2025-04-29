#include <iostream>
using namespace std;

#include "Coneteneur.h"
#include "ContenaireRessource.h"

#include "menu.h"


int main() {
    Conteneur conteneur;
    ConteneurRessources conteneurRessources;

    int choix;
    do {
        menuPrincipal();
        cout << "Votre choix : ";
        cin >> choix;
        cin.ignore();

        switch (choix) {
            case 1:
                menuRessourcesHumaines(conteneur);
                break;
            case 2:
                menuRessourcesFinancieres(conteneurRessources);
                break;
            case 3:
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide." << endl;
        }
    } while (choix != 3);

    return 0;
}


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

