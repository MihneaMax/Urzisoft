#include "Magazin.h"
#include "Manager.h"
#include "Utilizator.h"
#include "ConstructorComanda.h"

Magazin* Magazin::instanta = nullptr;

Magazin::Magazin() {
    initializeazaDateExemplu();
}

Magazin* Magazin::getInstanta() {
    if (!instanta) {
        instanta = new Magazin();
    }
    return instanta;
}

bool Magazin::autentificareUtilizator(const std::string& numeUtilizator, const std::string& parola) {
    for (auto& utilizator : utilizatori) {
        if (utilizator->autentificare(numeUtilizator, parola)) {
            utilizatorCurent = utilizator.get();
            return true;
        }
    }
    return false;
}

void Magazin::deautentificareUtilizator() {
    if (utilizatorCurent) {
        utilizatorCurent->deautentificare();
        utilizatorCurent = nullptr;
    }
}

Utilizator* Magazin::getUtilizatorCurent() const {
    return utilizatorCurent;
}

void Magazin::adaugaComanda(const Comanda& comanda) {
    comenzi.adaugaElement(comanda);
}

Comanda* Magazin::getComanda(int index) {
    return comenzi.getElement(index);
}

const ContainerComanda<Comanda>& Magazin::getToateComenzile() const {
    return comenzi;
}

void Magazin::adaugaUtilizator(std::unique_ptr<Utilizator> utilizator) {
    utilizatori.push_back(std::move(utilizator));
}

void Magazin::initializeazaDateExemplu() {
    adaugaUtilizator(std::make_unique<Manager>("admin", "admin123"));
    adaugaUtilizator(std::make_unique<Utilizator>("client", "parola123"));
    
    ConstructorComanda constructor(1, "Ion Popescu");
    constructor.adaugaArticol(ArticolComanda("P001", "Laptop", 4500.0, 1));
    constructor.adaugaArticol(ArticolComanda("P002", "Mouse", 150.0, 2));
    adaugaComanda(constructor.construieste());
}