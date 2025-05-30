#ifndef CONSTRUCTOR_COMANDA_H
#define CONSTRUCTOR_COMANDA_H

#include "Comanda.h"

class ConstructorComanda {
private:
    Comanda comanda;

public:
    ConstructorComanda(int idComanda, const std::string& numeClient);
    ConstructorComanda& adaugaArticol(const ArticolComanda& articol);
    Comanda construieste() const;
};

#endif // CONSTRUCTOR_COMANDA_H