#include "Comanda.h"

Comanda::Comanda(int idComanda, const std::string& numeClient) 
    : idComanda(idComanda), numeClient(numeClient), status("In asteptare") {}

void Comanda::adaugaArticol(const ArticolComanda& articol) {
    articole.push_back(articol);
}

void Comanda::seteazaStatus(const std::string& status) {
    this->status = status;
}

int Comanda::getIdComanda() const { return idComanda; }
std::string Comanda::getNumeClient() const { return numeClient; }
std::string Comanda::getStatus() const { return status; }
const std::vector<ArticolComanda>& Comanda::getArticole() const { return articole; }

double Comanda::getTotal() const {
    double total = 0.0;
    for (const auto& articol : articole) {
        total += articol.getTotal();
    }
    return total;
}

#include <sstream>

std::string Comanda::descriere() const {
    std::ostringstream oss;
    oss << "Comanda #" << idComanda << " - Status: " << status;
    return oss.str();
}
