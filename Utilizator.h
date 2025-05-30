#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <string>

class Utilizator {
protected:
    std::string numeUtilizator;
    std::string parola;
    bool autentificat;

public:
    Utilizator(const std::string& numeUtilizator, const std::string& parola);
    virtual bool autentificare(const std::string& numeUtilizator, const std::string& parola);
    void deautentificare();
    bool esteAutentificat() const;
    virtual bool esteManager() const;
    virtual ~Utilizator() = default;
};

#endif // UTILIZATOR_H