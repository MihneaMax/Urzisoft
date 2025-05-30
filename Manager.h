#ifndef MANAGER_H
#define MANAGER_H

#include "Utilizator.h"

class Manager : public Utilizator {
public:
    Manager(const std::string& numeUtilizator, const std::string& parola);
    bool esteManager() const override;
};

#endif // MANAGER_H