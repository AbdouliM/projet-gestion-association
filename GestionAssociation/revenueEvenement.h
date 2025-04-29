# pragma once
#include<string>
#include"ressource.h"
using namespace std;

class RevenueEvenement : virtual public Ressource {
protected:
    double montantEv;
    string lieuEvenement;
    string typeEvenement;

public:
    friend ostream& operator<<(ostream& os, const RevenueEvenement& re);
    friend istream& operator>>(istream& is, RevenueEvenement& re);

    RevenueEvenement(){montantEv=0;lieuEvenement="";typeEvenement="";}
    RevenueEvenement(const string& d, const string& t,double m, const string& l, const string& te)
        : Ressource(d,t) {montantEv=m;lieuEvenement=l;typeEvenement=te;}

     void afficher()  const override{
    cout << "--- Revenue Evenement ---" << endl;
    cout << *this;

}

    double calculerRevenuNet(double);

    void setMontant(double m) { montantEv = m; }
    double getMontant() const { return montantEv; }

    void setLieuEvenement(const string& l) { lieuEvenement = l; }
    string getLieuEvenement() { return lieuEvenement; }

    void setTypeEvenement(const string& t) { typeEvenement = t; }
    string getTypeEvenement() { return typeEvenement; }
    ~RevenueEvenement(){}
    friend ostream& operator<<(ostream& os, const RevenueEvenement* re);
    friend istream& operator>>(istream& is, RevenueEvenement* re);
};
