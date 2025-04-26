# pragma once
using namespace std;
#include<string>

class Projet{
protected:
    string nom;
    string description;

public:

    friend ostream& operator<< (ostream&, Projet*);
    friend istream& operator>> (istream&, Projet*);

    Projet(){nom="";description="";}
    Projet(string n,string d){nom=n;description=d;
    }
    Projet(const Projet& p);

    friend istream& operator>>(istream& in, Projet& p);
    friend ostream& operator<<(ostream& out, const Projet& p);
    void afficher() ;

    string getNom() { return nom; }
    void setNom(const string& newNom) { nom = newNom; }

    string getDescription() { return description; }
    void setDescription(const string& newDescription) { description = newDescription; }

    ~Projet(){}
};
