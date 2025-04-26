#pragma once
#include"personne.h"
#include "donateur.h"
#include "membre.h"
#include "admin.h"
#include <vector>

class Conteneur{
      public:
  vector<Personne*> tab;


   void supprimerParNom(const string& , const string&) ;

    Conteneur() = default;

    Conteneur(const Conteneur&);

   void ouvrirFichier(const string& nomFichier);
   void copierFichierVersVector(const string& nomFichier);
   void CopierVectorVersFichier(const string& nomFichier);
   void modifierdansFichier(const string& nom, const string& nomFichier);

    friend ostream& operator<<(ostream&, Conteneur&);
    friend ostream& operator<<(ostream&, Conteneur*);
    friend istream& operator>>(istream&, Conteneur&);
    friend istream& operator>>(istream&, Conteneur*);


  ~Conteneur();

};
