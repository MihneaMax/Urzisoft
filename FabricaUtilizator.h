#ifndef FABRICA_UTILIZATOR_H
#define FABRICA_UTILIZATOR_H

#include "Utilizator.h"
#include <memory>

class FabricaUtilizator {
public:
    static std::unique_ptr<Utilizator> creeazaUtilizator(
        const std::string& tip,
        const std::string& numeUtilizator,
        const std::string& parola
    );
};

#endif // FABRICA_UTILIZATOR_H