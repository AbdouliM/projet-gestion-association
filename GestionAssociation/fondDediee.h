
# pragma once
#include<string>
#include"revenueDonation.h"
#include"revenueEvenement.h"
#include<iostream>
 using namespace std;
class FondsDedies : public RevenueDonation , public RevenueEvenement{
private:
    string destinataire;
    int id;

public:
    FondsDedies() : RevenueDonation(), RevenueEvenement(){ destinataire=""; id=0; }

    FondsDedies(const string& d, const string& t, double m, const string& md, double n, const string& l, const string& te,const string& dest, int i):
    RevenueDonation(d,t,m,md), RevenueEvenement(d,t,n,l,te){destinataire=dest; id=i;}

    friend istream& operator>>(istream& in, FondsDedies& f);
    friend ostream& operator<<(ostream& out, const FondsDedies& f);

  void afficher() const override ;





    void setDestinataire(const string& d) { destinataire = d; }
    string getDestinataire()const { return destinataire; }

    void setId(int i) { id = i; }
    int getId() const{ return id; }
};

