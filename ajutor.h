#pragma once
#include <iostream>
#include <type_traits>
#include "ContainerComanda.h"
#include "Comanda.h"

// Funcție șablon liberă
template <typename T>
void afiseazaContainer(const ContainerComanda<T>& container) {
    std::cout << "\n[Container cu " << container.dimensiune() << " elemente]\n";
    container.afiseazaElemente();
    std::cout << "--------------------------\n";
}