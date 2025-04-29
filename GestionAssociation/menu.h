#pragma once
#include <iostream>
#include "Personne.h"
#include "Donateur.h"
#include "Membre.h"
#include "admin.h"
#include "Coneteneur.h"
#include"comite.h"
#include "Ressource.h"
#include "ressourceMaterielle.h"
#include "RevenueDonation.h"
#include "RevenueEvenement.h"
#include "FondDediee.h"
#include "ContenaireRessource.h"
#include "menu.h"
using namespace std;

void menuPrincipal() {
    cout << "\n========== MENU PRINCIPAL ==========" << endl;
    cout << "1. Gestion des ressources humaines" << endl;
    cout << "2. Gestion des ressources financieres" << endl;
    cout << "3. Quitter" << endl;
    cout << "====================================" << endl;
}

void afficherMenu1() {
    cout << "\n===== SYSTEME DE GESTION =====" << endl;
    cout << "1. Ajouter une personne" << endl;
    cout << "2. Afficher toutes les personnes" << endl;
    cout << "3. Gerer la comite d'administration" << endl;
    cout << "4. Rechercher et modifier une personne" << endl;
    cout << "5. Sauvegarder dans un fichier" << endl;
    cout << "6. Charger depuis un fichier" << endl;
    cout << "7. Rechercher et supprimer une personne" << endl;
    cout << "8. Quitter" << endl;
    cout << "Choix : ";
}
void afficherMenu3() {
    ComiteAdministration comite;
    const string nomFichier = "comite.txt";
    comite.chargerDepuisFichier(nomFichier);


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
                cout << "-----------------------------------------------" << endl;
                cout << comite;
                break;
            }
            case 2: {
                Administrateur* admin = new Administrateur();
                cin >> *admin;
                comite += admin;
                comite.sauvegarderDansFichier(nomFichier);
                cout << "Administrateur ajoute avec succes !" << endl;
                break;
            }
            case 3: {
                size_t index;
                cout << "Index de l'administrateur a supprimer : ";
                cin >> index;
                comite.supprimerAdministrateur(index);
                comite.sauvegarderDansFichier(nomFichier);
                break;
            }
            case 4:
                cout << "Fermeture du programme." << endl;
                break;
            default:
                cout << "Choix invalide, veuillez reessayer." << endl;
        }
    } while (choix != 4);
}
void menuRessourcesHumaines(Conteneur conteneur) {

const string nomFichier = "personnes.txt";
int choix;

    do {
        afficherMenu1();
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
                case 3:
                 afficherMenu3();
                break;

                case 4: {
                    string nom;
                    cout << "Entrez le nom a rechercher: ";
                    cin>>nom;
                    conteneur.modifierdansFichier(nom, nomFichier);
                    break;
                }

                case 5:
                    conteneur.CopierVectorVersFichier(nomFichier);
                    cout << "Donnees sauvegardees dans " << nomFichier << endl;
                    break;

                case 6:
                    conteneur.copierFichierVersVector(nomFichier);
                    cout << "Donnees chargees depuis " << nomFichier << endl;
                    break;

                case 7:{
                    string nom;
                    cout << "Entrez le nom a rechercher: ";
                    cin>>nom;
                    conteneur.supprimerParNom(nom, nomFichier);
                    break;
                }
                case 8:
                    cout <<endl<< "Au revoir!" << endl;
                    break;
                default:
                    cout << "Choix invalide!" << endl;
            }
        } catch(const exception& e) {
            cerr << "Erreur: " << e.what() << endl;
        }

    } while(choix != 8);
}

void afficherMenu2() {
    cout << "\n===== SYSTEME DE GESTION =====" << endl;
    cout << "1. Ajouter une ressource" << endl;
    cout << "2. Afficher toutes les ressources" << endl;
    cout << "3. Rechercher et modifier une ressource" << endl;
    cout << "4. Sauvegarder dans un fichier" << endl;
    cout << "5. Charger depuis un fichier" << endl;
    cout << "6. Rechercher et supprimer une ressource" << endl;
    cout << "7. Quitter" << endl;
    cout << "Choix : ";
}
void menuRessourcesFinancieres(ConteneurRessources conteneurRessources) {

const string nomFichier = "ressources.txt";
int choix;

    do {
        afficherMenu2();
        cin >> choix;
        try {
            switch(choix) {
                case 1:
                    cin >> conteneurRessources;
                    break;

                case 2:
                    cout << "\n=== LISTE DES PERSONNES ===" << endl;
                    cout<<conteneurRessources;
                    break;

                case 3: {
                    string nom;
                    cout << "Entrez le nom a rechercher: ";
                    cin>>nom;
                    conteneurRessources.modifierdansFichier(nom, nomFichier);
                    break;
                }

                case 4:
                    conteneurRessources.CopierVectorVersFichier(nomFichier);
                    cout << "Donnees sauvegardees dans " << nomFichier << endl;
                    break;

                case 5:
                    conteneurRessources.copierFichierVersVector(nomFichier);
                    cout << "Donnees chargees depuis " << nomFichier << endl;
                    break;

                case 6:{
                    string date;
                    cout << "Entrez la date de ressource  a rechercher: ";
                    cin>>date;
                    conteneurRessources.supprimerPardate(date, nomFichier);
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
}
