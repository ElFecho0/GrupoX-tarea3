// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/processor.h"
#include "modules/validator.h"
#include "modules/sorter.h"

int main(int argc, char* argv[]) {
    if (argc != 4 && argc != 2) {
        fprintf(stderr, "Uso: %s rutas.txt ORIGEN DESTINO\n", argv[0]);
        fprintf(stderr, "O bien: %s rutas.txt --listar\n", argv[0]);
        return 1;
    }

    const char* archivo = argv[1];
    Grafo* grafo = crearGrafoDesdeArchivo(archivo);
    if (!grafo) {
        fprintf(stderr, "Error al cargar el archivo.\n");
        return 1;
    }

    if (argc == 2 && strcmp(argv[1], "--listar") == 0) {
        imprimirCiudadesOrdenadas(grafo->nombres, grafo->numVertices);
        liberarGrafo(grafo);
        return 0;
    }

    if (argc == 4) {
        const char* origen = argv[2];
        const char* destino = argv[3];

        if (!ciudadExiste(grafo, origen) || !ciudadExiste(grafo, destino)) {
            fprintf(stderr, "Una o ambas ciudades no existen en el archivo.\n");
            liberarGrafo(grafo);
            return 1;
        }
        
        encontrarRutaMinima(grafo, origen, destino);
    }

    liberarGrafo(grafo);
    return 0;
}
