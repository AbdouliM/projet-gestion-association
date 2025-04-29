#pragma once
#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Ressource.h"

class ConteneurRessources {
private:
    vector<Ressource*> ressources;

public:
    ConteneurRessources() = default;
    ~ConteneurRessources();

   void ouvrirFichier(const string& nomFichier);
   void copierFichierVersVector(const string& nomFichier);
   void CopierVectorVersFichier(const string& nomFichier);
   void modifierdansFichier(const string& date, const string& nomFichier);
   void supprimerPardate(const string& nom, const string& nomFichier);


    friend ostream& operator<<(ostream&, ConteneurRessources&);
    friend ostream& operator<<(ostream&, ConteneurRessources*);
    friend istream& operator>>(istream&, ConteneurRessources&);
    friend istream& operator>>(istream&, ConteneurRessources*);

    ConteneurRessources(const ConteneurRessources&);
};
