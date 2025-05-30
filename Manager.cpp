#include "Manager.h"

Manager::Manager(const std::string& numeUtilizator, const std::string& parola)
    : Utilizator(numeUtilizator, parola) {}

bool Manager::esteManager() const {
    return true;
}