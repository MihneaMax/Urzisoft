#include "ArticolComanda.h"
#include <sstream>

ArticolComanda::ArticolComanda(const std::string& idProdus, const std::string& numeProdus, 
                     double pret, int cantitate)
    : idProdus(idProdus), numeProdus(numeProdus), pret(pret), cantitate(cantitate) {}

std::string ArticolComanda::getIdProdus() const { return idProdus; }
std::string ArticolComanda::getNumeProdus() const { return numeProdus; }
double ArticolComanda::getPret() const { return pret; }
int ArticolComanda::getCantitate() const { return cantitate; }
double ArticolComanda::getTotal() const {
    return pret * cantitate;
}

std::string ArticolComanda::descriere() const {
    std::ostringstream oss;
    oss << numeProdus << " (x" << cantitate << ") - " << pret << " lei/buc, total: " << getTotal() << " lei";
    return oss.str();
}