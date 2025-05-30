#ifndef COMANDA_H
#define COMANDA_H

#include <vector>
#include <string>
#include "ArticolComanda.h"

class Comanda {
private:
    int idComanda;
    std::string numeClient;
    std::vector<ArticolComanda> articole;
    std::string status;

public:
    Comanda(int idComanda, const std::string& numeClient);
    
    void adaugaArticol(const ArticolComanda& articol);
    void seteazaStatus(const std::string& status);
    
    int getIdComanda() const;
    std::string getNumeClient() const;
    std::string getStatus() const;
    const std::vector<ArticolComanda>& getArticole() const;
    double getTotal() const;
    std::string descriere() const;
};

#endif // COMANDA_H