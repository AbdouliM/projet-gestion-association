# pragma once
#include<string>
#include<iostream>
using namespace std;
class Dons{
double montant;
string date;
string type;
public:
    friend ostream& operator<< (ostream&, Dons*);
friend istream& operator>> (istream&, Dons*);

    friend istream& operator>>(istream& in, Dons& d);
    friend ostream& operator<<(ostream& out, const Dons& d);
    Dons() { montant=0; date=""; type=""; }
    Dons(double m, const string& d, const string& t){ montant=m; date=d; type=t; }

    ~Dons(){}

void afficher() {
    cout << "Don :"<<endl<<"Montant:"<<montant<<endl<<"date"<<date<<endl<<"Type"<<type<<endl;
}



    double getMontant() { return montant; }
    string getDate()  { return date; }
    string getType()  { return type; }

    void setMontant(double m) { montant = m; }
    void setDate(const string& d) { date = d; }
    void setType(const string& t) { type = t; }

} ;
