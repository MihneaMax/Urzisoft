#pragma once
#include <string>

class ArticolComanda {
    std::string idProdus;
    std::string numeProdus;
    double pret;
    int cantitate;
public:
    ArticolComanda(const std::string& idProdus, const std::string& numeProdus, double pret, int cantitate);

    std::string getIdProdus() const;
    std::string getNumeProdus() const;
    double getPret() const;
    int getCantitate() const;
    double getTotal() const;
    std::string descriere() const;
};