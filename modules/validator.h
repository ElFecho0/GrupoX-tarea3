#ifndef VALIDATOR_H
#define VALIDATOR_H

// En "processor.h" esta la definición de los grafos, necesaria para validar si las ciudades existen
#include "processor.h"

// Indica que hay una función que genera un valor el cual es 1 si la ciudad esta en el grafo y 0 su no existe
int ciudadExiste(Grafo* grafo, const char* ciudad);

#endif
