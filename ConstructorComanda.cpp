#include "ConstructorComanda.h"

ConstructorComanda::ConstructorComanda(int idComanda, const std::string& numeClient)
    : comanda(idComanda, numeClient) {}

ConstructorComanda& ConstructorComanda::adaugaArticol(const ArticolComanda& articol) {
    comanda.adaugaArticol(articol);
    return *this;
}

Comanda ConstructorComanda::construieste() const {
    return comanda;
}