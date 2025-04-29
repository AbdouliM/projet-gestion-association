
# pragma once
#include<map>
#include<string>
#include"fondDediee.h"
using namespace std;

class RapportFinancier {
private:
    int annee;
    double totalDepenses;
    double totalRevenus;
    map<string, FondsDedies*> fondsDediesMap;

public:
    RapportFinancier();
    RapportFinancier(int a, double td, double tr);
    RapportFinancier(const RapportFinancier& autre);


    int getAnnee() ;
    void setAnnee(int a);

    double getTotalDepenses() ;
    void setTotalDepenses(double td);

    double getTotalRevenus() ;
    void setTotalRevenus(double tr);

    map<string, FondsDedies*> getFondsDediesMap() ;
    void setFondsDediesMap(const map<string, FondsDedies*>& fdMap);

    friend ostream& operator<<(ostream& os, const RapportFinancier& rf);
    friend istream& operator>>(istream& is, RapportFinancier& rf);


};

