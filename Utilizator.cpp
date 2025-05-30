#include "Utilizator.h"

Utilizator::Utilizator(const std::string& numeUtilizator, const std::string& parola) 
    : numeUtilizator(numeUtilizator), parola(parola), autentificat(false) {}

bool Utilizator::autentificare(const std::string& numeUtilizator, const std::string& parola) {
    if (this->numeUtilizator == numeUtilizator && this->parola == parola) {
        autentificat = true;
        return true;
    }
    return false;
}

void Utilizator::deautentificare() {
    autentificat = false;
}

bool Utilizator::esteAutentificat() const {
    return autentificat;
}

bool Utilizator::esteManager() const {
    return false;
}