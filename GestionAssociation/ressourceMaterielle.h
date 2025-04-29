# pragma once
#include"ressource.h"
#include<vector>
#include"stock.h"
#include<string>
#include<iostream>
using namespace std;


class RessourceMaterielle : virtual public Ressource {
protected:
    string nom;
    int quantite;
    string etat;
    static int qtttotale;
    vector<Stock*>vstock;

public:
    friend ostream& operator<<(ostream& os, const RessourceMaterielle& rm);
    friend istream& operator>>(istream& is, RessourceMaterielle& rm);
    friend ostream& operator<<(ostream& os, const RessourceMaterielle* rm);
    friend istream& operator>>(istream& is, RessourceMaterielle* rm);
    RessourceMaterielle& operator=(const RessourceMaterielle& autre) {

            nom = autre.nom;
            quantite = autre.quantite;
            etat = autre.etat;

            qtttotale -= this->quantite;
            qtttotale += autre.quantite;

            for (Stock* s : vstock) {
                delete s;
            }
            vstock.clear();

            for (Stock* s : autre.vstock) {
                vstock.push_back(new Stock(*s));
            }

        return *this;
    }




   RessourceMaterielle(): Ressource() {nom="";
    quantite=0;
    etat="";}
   RessourceMaterielle(const string& d, const string& t, const string& n, int q, const string& e):Ressource(d, t){ nom=n;
    quantite=q;
    etat=e;
    qtttotale+=q;
    int nbstock=0;
    cout << "Combien de stocks voulez-vous creer ? ";
    cin >> nbstock;

    for (int i = 0; i < nbstock; ++i) {

    Stock* s = new Stock();
        cout << "Stock " << i + 1 << " :" << endl;
        cin >> *s;
        vstock.push_back(s);
}
    }
RessourceMaterielle(const RessourceMaterielle& autre)
        {
            nom=autre.nom;quantite=autre.quantite; etat=autre.etat;
        for (Stock* s : autre.vstock) {
        vstock.push_back(new Stock(*s));}
        qtttotale += quantite;
}

   void afficher() const override{
   cout << "Nom : " << nom << endl;
    cout<< "Quantite : " << quantite << endl;
    cout << "etat : " <<etat << endl;
    cout << "Stocks :\n";}


    void ajouterStock( Stock* );


    RessourceMaterielle&operator+=(Stock* s) {
    vstock.push_back(s);
    return *this;
}

    void viderStock();

    static int getqtttotale(){return qtttotale;}
    void setNom(const string& n) { nom = n; }
    string getNom()  { return nom; }

    void setQuantite(int q) { quantite = q; }
    int getQuantite() { return quantite; }

    void setEtat(const string& e) { etat = e; }
    string getEtat() { return etat; }

    vector<Stock*> getstock() { return vstock; }
    void setstock(const vector<Stock*>& st) { vstock = st; }

    ~RessourceMaterielle();

    };


