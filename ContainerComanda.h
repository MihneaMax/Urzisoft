#pragma once
#include <vector>
#include <iostream>

template <typename T>
class ContainerComanda {
    std::vector<T> elemente;
public:
    void adaugaElement(const T& element);
    void eliminaElement(int index);
    T* getElement(int index);
    const T* getElement(int index) const;
    size_t dimensiune() const;
    bool esteGol() const;
    void afiseazaElemente() const;
};

// Implementări funcții template
template <typename T>
void ContainerComanda<T>::adaugaElement(const T& element) {
    elemente.push_back(element);
}

template <typename T>
void ContainerComanda<T>::eliminaElement(int index) {
    if (index >= 0 && static_cast<size_t>(index) < elemente.size()) {
        elemente.erase(elemente.begin() + index);
    }
}

template <typename T>
T* ContainerComanda<T>::getElement(int index) {
    if (index >= 0 && static_cast<size_t>(index) < elemente.size()) {
        return &elemente[index];
    }
    return nullptr;
}

template <typename T>
const T* ContainerComanda<T>::getElement(int index) const {
    if (index >= 0 && static_cast<size_t>(index) < elemente.size()) {
        return &elemente[index];
    }
    return nullptr;
}

template <typename T>
size_t ContainerComanda<T>::dimensiune() const {
    return elemente.size();
}

template <typename T>
bool ContainerComanda<T>::esteGol() const {
    return elemente.empty();
}

template <typename T>
void ContainerComanda<T>::afiseazaElemente() const {
    for (const auto& elem : elemente) {
        std::cout << elem.descriere() << "\n";
    }
}
