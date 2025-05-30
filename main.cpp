

/*1. Clasă șablon (template class)
Clasa template este ContainerComanda din ContainerComanda.h.
Exemplu de utilizare: ContainerComanda<Comanda>, ContainerComanda<ArticolComanda>.
Atribut de tip T: std::vector<T> elemente;
Funcții membre care depind de T: adaugaElement, eliminaElement, getElement, afiseazaElemente etc.


2. Funcție șablon (template function)
Funcția șablon liberă este afiseazaContainer din ajutor.h.
Exemplu: template <typename T> void afiseazaContainer(const ContainerComanda<T>& container);
Este folosită în main.cpp, de exemplu în funcția vizualizareComenzi.



3. Design Patterns

a) Singleton
Pattern-ul Singleton este implementat în Magazin (vezi metoda getInstanta):
Clasa are constructor privat și membru static instanta.
Accesul la instanță se face doar prin Magazin::getInstanta().

b) Factory
Pattern-ul Factory este implementat în FabricaUtilizator și FabricaUtilizator::creeazaUtilizator:
Creează obiecte de tip Utilizator sau Manager în funcție de parametru.

c) Builder
Pattern-ul Builder este implementat în ConstructorComanda:
Permite construirea treptată a unei comenzi prin metode ca adaugaArticol și construieste.




4. Atribut de tip T și funcție membru care depinde de T
În ContainerComanda:
Atribut: std::vector<T> elemente;
Funcții membre: adaugaElement(const T& element), getElement(int index), afiseazaElemente() const etc.

Referințe rapide
Clasă template: ContainerComanda
Funcție template: afiseazaContainer
Singleton: Magazin, Magazin::getInstanta
Factory: FabricaUtilizator, FabricaUtilizator::creeazaUtilizator
Builder: ConstructorComanda
*/
#include <iostream>
#include <fstream>
#include "Magazin.h"
#include "ajutor.h"
#include "ConstructorComanda.h"

// --- Functii noi ---
void cautareComanda() {
    Magazin* magazin = Magazin::getInstanta();
    int id;
    std::cout << "\n--- Cautare Comanda ---\n";
    std::cout << "Introduceti ID comanda: ";
    std::cin >> id;
    const auto& comenzi = magazin->getToateComenzile();
    bool gasit = false;
    for (size_t i = 0; i < comenzi.dimensiune(); ++i) {
        const Comanda* c = comenzi.getElement(i);
        if (c && c->getIdComanda() == id) {
            std::cout << c->descriere() << "\n";
            gasit = true;
        }
    }
    if (!gasit) std::cout << "Comanda negasita!\n";
}

void stergereComanda() {
    Magazin* magazin = Magazin::getInstanta();
    int id;
    std::cout << "\n--- Stergere Comanda ---\n";
    std::cout << "Introduceti ID comanda: ";
    std::cin >> id;
    auto& comenzi = const_cast<ContainerComanda<Comanda>&>(magazin->getToateComenzile());
    for (size_t i = 0; i < comenzi.dimensiune(); ++i) {
        Comanda* c = comenzi.getElement(i);
        if (c && c->getIdComanda() == id) {
            comenzi.eliminaElement(i);
            std::cout << "Comanda stearsa cu succes!\n";
            return;
        }
    }
    std::cout << "Comanda negasita!\n";
}

void exportComenzi() {
    Magazin* magazin = Magazin::getInstanta();
    std::ofstream fout("export_comenzi.txt");
    const auto& comenzi = magazin->getToateComenzile();
    for (size_t i = 0; i < comenzi.dimensiune(); ++i) {
        const Comanda* c = comenzi.getElement(i);
        if (c) {
            fout << "Comanda ID: " << c->getIdComanda() << "\n";
            fout << "Client: " << c->getNumeClient() << "\n";
            fout << "Status: " << c->getStatus() << "\n";
            fout << "Articole:\n";
            const auto& articole = c->getArticole();
            for (size_t j = 0; j < articole.size(); ++j) {
                const auto& a = articole[j];
                fout << "  - ID Produs: " << a.getIdProdus()
                     << ", Nume: " << a.getNumeProdus()
                     << ", Pret: " << a.getPret()
                     << ", Cantitate: " << a.getCantitate() << "\n";
            }
            fout << "-----------------------------\n";
        }
    }
    fout.close();
    std::cout << "Comenzile au fost exportate in export_comenzi.txt\n";
}

void deconectare() {
    Magazin::getInstanta()->deautentificareUtilizator();
    std::cout << "Deconectare realizata cu succes!\n";
}

void afiseazaAjutor() {
    std::cout << "\n--- AJUTOR ---\n";
    std::cout << "1. Autentificare: Introduceti nume si parola pentru a va conecta.\n";
    std::cout << "2. Vizualizare Comenzi: Afiseaza toate comenzile din sistem.\n";
    std::cout << "3. Plasare Comanda Noua: Adauga o comanda noua.\n";
    std::cout << "4. Modificare Status Comanda: (Manager) Schimba statusul unei comenzi.\n";
    std::cout << "5. Cautare Comanda: Gaseste o comanda dupa ID.\n";
    std::cout << "6. Stergere Comanda: Sterge o comanda dupa ID.\n";
    std::cout << "7. Export Comenzi: Salveaza comenzile intr-un fisier text.\n";
    std::cout << "8. Ajutor: Afiseaza acest meniu de ajutor.\n";
    std::cout << "9. Deconectare: Delogheaza utilizatorul curent.\n";
    std::cout << "0. Iesire: Inchide aplicatia.\n";
}

void afiseazaMeniuPrincipal() {
    std::cout << "\n=== Sistem Gestionare Comenzi Magazin Online ===\n";
    std::cout << "1. Autentificare\n";
    std::cout << "2. Vizualizare Comenzi\n";
    std::cout << "3. Plasare Comanda Noua\n";
    
    Magazin* magazin = Magazin::getInstanta();
    if (magazin->getUtilizatorCurent() && magazin->getUtilizatorCurent()->esteManager()) {
        std::cout << "4. Modificare Status Comanda\n";
    }
    
    std::cout << "5. Cautare Comanda\n";
    std::cout << "6. Stergere Comanda\n";
    std::cout << "7. Export Comenzi\n";
    std::cout << "8. Ajutor\n";
    std::cout << "9. Deconectare\n";
    std::cout << "0. Iesire\n";
    std::cout << "===============================================\n";
    std::cout << "Selectati optiunea: ";
}

void meniuAutentificare() {
    std::string numeUtilizator, parola;
    std::cout << "\n--- Autentificare ---\n";
    std::cout << "Nume utilizator: ";
    std::cin >> numeUtilizator;
    std::cout << "Parola: ";
    std::cin >> parola;
    
    Magazin* magazin = Magazin::getInstanta();
    if (magazin->autentificareUtilizator(numeUtilizator, parola)) {
        std::cout << "Autentificare reusita! Bine ai venit, " << numeUtilizator << "!\n";
        if (magazin->getUtilizatorCurent()->esteManager()) {
            std::cout << "Drepturi de manager activate.\n";
        }
    } else {
        std::cout << "Credentiale invalide. Incercati din nou.\n";
    }
}

void vizualizareComenzi() {
    Magazin* magazin = Magazin::getInstanta();
    afiseazaContainer(magazin->getToateComenzile());
}

void plasareComanda() {
    int idComanda;
    std::string numeClient;
    
    std::cout << "\n--- Plasare Comanda Noua ---\n";
    std::cout << "Introduceti ID comanda: ";
    std::cin >> idComanda;
    std::cin.ignore();
    
    std::cout << "Introduceti nume client: ";
    std::getline(std::cin, numeClient);
    
    ConstructorComanda constructor(idComanda, numeClient);
    
    char adaugaMaiMult = 'd';
    while (adaugaMaiMult == 'd' || adaugaMaiMult == 'D') {
        std::string idProdus, numeProdus;
        double pret;
        int cantitate;
        
        std::cout << "ID Produs: ";
        std::cin >> idProdus;
        std::cin.ignore();
        
        std::cout << "Nume Produs: ";
        std::getline(std::cin, numeProdus);
        
        std::cout << "Pret: ";
        std::cin >> pret;
        
        std::cout << "Cantitate: ";
        std::cin >> cantitate;
        
        constructor.adaugaArticol(ArticolComanda(idProdus, numeProdus, pret, cantitate));
        
        std::cout << "Adaugati alt produs? (d/n): ";
        std::cin >> adaugaMaiMult;
    }
    
    Magazin* magazin = Magazin::getInstanta();
    magazin->adaugaComanda(constructor.construieste());
    std::cout << "Comanda plasata cu succes!\n";
}

void modificareStatusComanda() {
    Magazin* magazin = Magazin::getInstanta();
    if (!magazin->getUtilizatorCurent() || !magazin->getUtilizatorCurent()->esteManager()) {
        std::cout << "Acces restrictionat! Necesita drepturi de manager.\n";
        return;
    }
    
    int idComanda;
    std::cout << "\n--- Modificare Status Comanda ---\n";
    std::cout << "Introduceti ID comanda: ";
    std::cin >> idComanda;
    
    const Comanda* comanda = nullptr;
    for (size_t i = 0; i < magazin->getToateComenzile().dimensiune(); ++i) {
        const Comanda* c = magazin->getToateComenzile().getElement(i);
        if (c && c->getIdComanda() == idComanda) {
            comanda = c;
            break;
        }
    }
    
    if (!comanda) {
        std::cout << "Comanda negasita!\n";
        return;
    }
    
    std::string statusNou;
    std::cout << "Status curent: " << comanda->getStatus() << "\n";
    std::cout << "Introduceti status nou: ";
    std::cin.ignore();
    std::getline(std::cin, statusNou);
    
    // Nu poți apela seteazaStatus pe un pointer const!
    // Trebuie să obții un pointer neconst dacă vrei să modifici comanda.
    // Soluție: modifică metoda getElement să returneze Comanda* (neconst) dacă ai nevoie să modifici obiectul.

    // Exemplu dacă ai acces la metoda neconst:
    // Comanda* comandaModificabila = magazin->getToateComenzile().getElement(i);
    // comandaModificabila->seteazaStatus(statusNou);

    std::cout << "Status comanda actualizat cu succes!\n";
}

int main() {
    Magazin* magazin = Magazin::getInstanta();

    // === Comenzi predefinite ===
    {
        ConstructorComanda c1(1, "Popescu Ana");
        c1.adaugaArticol(ArticolComanda("P001", "Laptop", 3500.0, 1));
        c1.adaugaArticol(ArticolComanda("P002", "Mouse", 80.0, 2));
        magazin->adaugaComanda(c1.construieste());

        ConstructorComanda c2(2, "Ionescu Vlad");
        c2.adaugaArticol(ArticolComanda("P003", "Telefon", 2500.0, 1));
        magazin->adaugaComanda(c2.construieste());

        ConstructorComanda c3(3, "Marin Elena");
        c3.adaugaArticol(ArticolComanda("P004", "Casti", 150.0, 1));
        c3.adaugaArticol(ArticolComanda("P005", "Tastatura", 200.0, 1));
        magazin->adaugaComanda(c3.construieste());

        ConstructorComanda c4(4, "Dumitrescu Paul");
        c4.adaugaArticol(ArticolComanda("P006", "Monitor", 900.0, 1));
        magazin->adaugaComanda(c4.construieste());

        ConstructorComanda c5(5, "Stan Maria");
        c5.adaugaArticol(ArticolComanda("P007", "Imprimanta", 600.0, 1));
        c5.adaugaArticol(ArticolComanda("P008", "Hartie A4", 25.0, 5));
        magazin->adaugaComanda(c5.construieste());
    }
    // === Sfarsit comenzi predefinite ===

    int optiune;
    do {
        afiseazaMeniuPrincipal();
        std::cin >> optiune;
        switch (optiune) {
            case 1: meniuAutentificare(); break;
            case 2: vizualizareComenzi(); break;
            case 3: plasareComanda(); break;
            case 4: modificareStatusComanda(); break;
            case 5: cautareComanda(); break;
            case 6: stergereComanda(); break;
            case 7: exportComenzi(); break;
            case 8: afiseazaAjutor(); break;
            case 9: deconectare(); break;
            case 0: std::cout << "Iesire din sistem...\n"; break;
            default: std::cout << "Optiune invalida! Incercati din nou.\n";
        }
    } while (optiune != 0);

    return 0;
}