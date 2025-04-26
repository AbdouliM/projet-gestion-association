# pragma once
#include"membre.h"
#include"donateur.h"

class MembreActif : virtual public Membre , virtual public Donateur {
private:
    int nombreHeuresBenevolat;
    string specialite;

public:
    friend ostream& operator<< (ostream&, MembreActif*);
    friend istream& operator>> (istream&, MembreActif*);


    friend istream& operator>>(istream& in, MembreActif& m);
    friend ostream& operator<<(ostream& out, const MembreActif& m);

    MembreActif(): Personne(), Membre(), Donateur() {nombreHeuresBenevolat = 0;specialite = "";}

    MembreActif(const string& n, const string& p, const string& d, const string& r, const string& da,const vector<Projet>& tab, int nhb, const string& s, double nd, const vector<Dons>& ds)
        : Membre(n, p, d, r, da), Donateur(n, p, d, nd) {nombreHeuresBenevolat=nhb; specialite=s;}
    void afficher() ;

    int getNombreHeuresBenevolat() { return nombreHeuresBenevolat; }
    void setNombreHeuresBenevolat(int nhb) { nombreHeuresBenevolat = nhb; }

    string getSpecialite() { return specialite; }
    void setSpecialite(const string& s) { specialite = s; }

};
