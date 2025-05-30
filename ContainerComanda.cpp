#include "ContainerComanda.h"
#include "Comanda.h"
#include "ArticolComanda.h"

// Instanțieri explicite (opțional, dar nu obligatoriu dacă nu folosești DLL)
template class ContainerComanda<Comanda>;
template class ContainerComanda<ArticolComanda>;
