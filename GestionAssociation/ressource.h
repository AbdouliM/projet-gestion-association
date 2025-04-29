# pragma once
#include<vector>
#include<string>
#include<iostream>
using namespace std;
#include "projet.h"
class Ressource {
protected:
    string date;
    string type;
    vector<Projet*>projets;

public:

    Ressource(){
    date="";
    type="";
    Projet p;
    projets.push_back(new Projet());}


    Ressource(const string& d, const string& t) {
    int nbProjets;
    cout << "Combien de projets voulez-vous ajouter ? ";
    cin >> nbProjets;

    for (int i = 0; i < nbProjets; ++i) {
        Projet* p = new Projet();
        cout << "Saisie du projet " << i + 1 << " :" << endl;
        cin >> *p;
        projets.push_back(p);  }
      date=d;
       type=t;
}


 virtual void afficher() const =0;




  friend istream& operator>(istream& in, Ressource& r) ;

    Ressource(const Ressource& r){ date=r.date;type=r.type;
     for (Projet* p : r.projets) {
        projets.push_back(new Projet(*p));
    }
    }
    friend istream& operator>>(istream& in, Ressource& r);
    friend ostream& operator<<(ostream& out, const Ressource& r);



    virtual ~Ressource() { {
    for (Projet* p : projets) {
        delete p;
    }
    projets.clear();
}};


    friend istream& operator>>(istream& in, Ressource*r);
    friend ostream& operator<<(ostream& out, const Ressource* r);




    void supprimerProjetParNom(const string& );

    void setDate(const string& d) { date = d; }
    string getDate() { return date; }

    void setType(const string& t) { type = t; }
    string getType(){ return type; }

    vector<Projet*> getprojets()  { return projets; }
    void setprojets (const vector<Projet*>& newP) { projets = newP; }





};

