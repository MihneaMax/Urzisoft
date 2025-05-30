#include "FabricaUtilizator.h"
#include "Manager.h"

std::unique_ptr<Utilizator> FabricaUtilizator::creeazaUtilizator(
    const std::string& tip,
    const std::string& numeUtilizator,
    const std::string& parola
) {
    if (tip == "manager") {
        return std::make_unique<Manager>(numeUtilizator, parola);
    } else {
        return std::make_unique<Utilizator>(numeUtilizator, parola);
    }
}