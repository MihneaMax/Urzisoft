# urzisoft - Sistem Gestionare Comenzi Magazin Online

Acest proiect este o aplicație C++ pentru gestionarea comenzilor într-un magazin online, folosind concepte moderne de programare (OOP, template-uri, design patterns).

## Funcționalități principale

- **Autentificare utilizator** (inclusiv rol de manager)
- **Vizualizare comenzi**
- **Plasare comenzi noi** cu mai multe produse
- **Modificare status comenzi** (doar manager)
- **Căutare și ștergere comenzi după ID**
- **Export comenzi** în fișier text
- **Meniu de ajutor**

## Structură proiect

- `main.cpp` — logica principală a aplicației și meniul interactiv
- [`Magazin`](urzisoft/Magazin.h) — singleton pentru gestionarea comenzilor și utilizatorilor
- [`Comanda`](urzisoft/Comanda.h), [`ArticolComanda`](urzisoft/ArticolComanda.h) — modelarea comenzilor și produselor
- [`ContainerComanda`](urzisoft/ContainerComanda.h) — clasă șablon pentru colecții de comenzi/articole
- [`ConstructorComanda`](urzisoft/ConstructorComanda.h) — builder pentru crearea comenzilor
- [`Utilizator`](urzisoft/Utilizator.h), [`Manager`](urzisoft/Manager.h) — ierarhie de utilizatori
- [`FabricaUtilizator`](urzisoft/FabricaUtilizator.h) — factory pentru crearea utilizatorilor
- [`ajutor.h`](urzisoft/ajutor.h) — funcții de utilitate și template

## Design Patterns folosite

- **Singleton**: [`Magazin`](urzisoft/Magazin.h)
- **Factory**: [`FabricaUtilizator`](urzisoft/FabricaUtilizator.h)
- **Builder**: [`ConstructorComanda`](urzisoft/ConstructorComanda.h)
- **Template class**: [`ContainerComanda`](urzisoft/ContainerComanda.h)
- **Template function**: `afiseazaContainer` în [`ajutor.h`](urzisoft/ajutor.h)

## Cum rulezi proiectul

1. **Compilare**  
   Din directorul `urzisoft/`, rulează:
   ```sh
   g++ -std=c++17 -Wall -g *.cpp -o program.exe
   ```
   sau folosește task-ul "Build C++ Project" din [`.vscode/tasks.json`](.vscode/tasks.json).

2. **Rulare**
   ```sh
   ./program.exe
   ```

## Export comenzi

Comenzile pot fi exportate în fișierul [`export_comenzi.txt`](urzisoft/export_comenzi.txt).

## Exemple de utilizare

- Autentificare ca manager:  
  Utilizator: `admin`  
  Parolă: `admin123`

- Plasare, vizualizare, modificare și export comenzi din meniul principal.

---

> Proiect realizat pentru demonstrarea conceptelor OOP și a pattern-urilor de proiectare în C++.
