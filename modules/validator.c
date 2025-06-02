#include <string.h>
#include "validator.h"

int ciudadExiste(Grafo* g, const char* ciudad) {
    for (int i = 0; i < g->numVertices; i++) {
        if (strcmp(g->nombres[i], ciudad) == 0) {
            return 1;
        }
    }
    return 0;
}
