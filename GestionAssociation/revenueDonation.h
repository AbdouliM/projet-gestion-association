# pragma once
#include"ressource.h"
#include<string>
class RevenueDonation : virtual public Ressource {
protected:
    double montant;
    string moyenDonation;

public:
    friend ostream& operator<<(ostream& os, const RevenueDonation& don);
friend istream& operator>>(istream& is, RevenueDonation& don);
friend ostream& operator<<(ostream& os, const RevenueDonation* don);
friend istream& operator>>(istream& is, RevenueDonation* don);


    RevenueDonation() : Ressource(){montant=0; moyenDonation="";}
    RevenueDonation(const string& d, const string& t, double m, const string& md):Ressource(d, t)
    {montant=m;moyenDonation=md;}

     void afficher() const override {
    cout << "--- Revenue Donation ---" << endl;

    cout << "Montant : " << montant << endl;
    cout << "Moyen de donation : " << moyenDonation << endl;
}

RevenueDonation& operator=(const RevenueDonation& other);
    bool estDonSignificatif(double seuil);

    void setMontant(double m) { montant = m; }
    double getMontant() { return montant; }

    void setMoyenDonation(const string& m) { moyenDonation = m; }
    string getMoyenDonation() { return moyenDonation; }
     ~RevenueDonation(){}

};

