#ifndef MAGAZIN_H
#define MAGAZIN_H

#include <vector>
#include <memory>
#include "Utilizator.h"
#include "Comanda.h"
#include "ContainerComanda.h"

class Magazin {
private:
    static Magazin* instanta;
    ContainerComanda<Comanda> comenzi;
    std::vector<std::unique_ptr<Utilizator>> utilizatori;
    Utilizator* utilizatorCurent = nullptr;

    Magazin(); // Constructor privat

public:
    static Magazin* getInstanta();
    Magazin(const Magazin&) = delete;
    Magazin& operator=(const Magazin&) = delete;
    
    bool autentificareUtilizator(const std::string& numeUtilizator, const std::string& parola);
    void deautentificareUtilizator();
    Utilizator* getUtilizatorCurent() const;
    
    void adaugaComanda(const Comanda& comanda);
    Comanda* getComanda(int index);
    const ContainerComanda<Comanda>& getToateComenzile() const;
    
    void adaugaUtilizator(std::unique_ptr<Utilizator> utilizator);
    
    // Pentru demonstrație
    void initializeazaDateExemplu();
};

#endif // MAGAZIN_H