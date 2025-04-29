# pragma once
#include<string>
#include<iostream>
using namespace std;
#include<iomanip>
class Stock {
private:
    string refc;
    int quantiteDisponible;
    string localisation;
public:

friend ostream& operator<<(ostream& os, const Stock& s) {
    os << "Reference : " << s.refc << "\n";
    os << "Quantite disponible : " << s.quantiteDisponible << "\n";
    os << "Localisation : " << s.localisation << "\n";
    return os;
}
friend istream& operator>>(istream& is, Stock& s) {
    cout << "Reference : ";
     is>> s.refc;
    cout << "Quantite disponible : ";
    is >> s.quantiteDisponible;

    cout << "Localisation : ";
    is>>s.localisation;
    return is;
}
/////
friend ostream& operator<<(ostream& os, const Stock* s) {
    os <<setw (10)<< s->refc;
    os << " " <<setw (10)<< s->quantiteDisponible ;
    os <<  " "<<setw (10)<< s->localisation ;
    return os;
}
friend istream& operator>>(istream& is, Stock* s) {
     is>> s->refc;
    is >> s->quantiteDisponible;
    is>>s->localisation;
    return is;
}

     void ajusterQuantite(int nouvelleQuantite ) {
        quantiteDisponible=nouvelleQuantite;
        cout << "Quantite ajustee : " << nouvelleQuantite << " pour le stock: " << refc << endl;
    }



   Stock(const string& r="", int q=0, const string& l="")
    {refc=r; quantiteDisponible=q; localisation=l;}


    void setReference(const string& r) { refc = r; }
    string getReference() { return refc; }

    void setQuantiteDisponible(int q) { quantiteDisponible = q; }
    int getQuantiteDisponible() const{ return quantiteDisponible; }

    void setLocalisation(const string& l) { localisation = l; }
    string getLocalisation()const { return localisation; }


    ~Stock() {}
};

