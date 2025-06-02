#include <string.h>
#include "validator.h"

// Función que verifica la ciudad indicada existe en el grafo entregado
// Si existe devuelve 1, en caso contrario 0
int ciudadExiste(Grafo* g, const char* ciudad) {
    // Se recorren todas las ciudades que hay para ver si existe
    for (int i = 0; i < g->numVertices; i++) {
        if (strcmp(g->nombres[i], ciudad) == 0) {
            return 1;
        }
    }
    return 0;
}
