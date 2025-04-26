# pragma once
#include"personne.h"
class Membre : virtual public Personne {
protected:
    string role;
    string dateAdhesion;
    static int nbmembres;

public:
    friend ostream& operator<< (ostream&, Membre*);
    friend istream& operator>> (istream&, Membre*);

    friend istream& operator>>(istream& in, Membre& m);
    friend ostream& operator<<(ostream& out, const Membre& m);

    Membre() {role="";dateAdhesion="";}
    Membre(const string& n, const string& p, const string& d, const string& r, const string& da)
       : Personne(n, p, d){role=r;dateAdhesion=da;nbmembres++;}

    void afficher();
    void mettreAJourRole(const string& );

    string getRole() { return role; }
    void setRole(const string& r) { role = r; }

    string getDateAdhesion() { return dateAdhesion; }
    void setDateAdhesion(const string& da) { dateAdhesion = da; }
     ~Membre(){nbmembres--;}
};
