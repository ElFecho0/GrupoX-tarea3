// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/processor.h"
#include "modules/validator.h"
#include "modules/sorter.h"

int main(int argc, char* argv[]) {

    // Verifica que se entreguen 4 argumentos para el correcto funcionamiento del código
    // Si no estan los argumentos indica como ejecutar
    if (argc != 4) {
        fprintf(stderr, "Uso: %s rutas.txt ORIGEN DESTINO\n", argv[0]);
        return 1;
    }

    // Clasifica el primer argumento como el archivo a leer
    const char* archivo = argv[1];
    Grafo* grafo = crearGrafoDesdeArchivo(archivo);
    // Si hay un error al leer el archivo se muestra un mensaje de error
    if (!grafo) {
        fprintf(stderr, "Error al cargar el archivo.\n");
        return 1;
    }

    // Si el numero de argumentos es 4, define el argumento 2 y 3 como el origen y destino respectivamente
    if (argc == 4) {
        const char* origen = argv[2];
        const char* destino = argv[3];

        // Revisa si los argumentos entregados existen en el grafo
        // En caso que no, termina la ejecución
        if (!ciudadExiste(grafo, origen) || !ciudadExiste(grafo, destino)) {
            fprintf(stderr, "Una o ambas ciudades no existen en el archivo.\n");
            liberarGrafo(grafo);
            return 1;
        }

        // Inicia la función que busca la ruta mínima entre ambas ciudades
        encontrarRutaMinima(grafo, origen, destino);
    }

    // Función que se encarga de liberar la memoria al terminar la ejecución
    liberarGrafo(grafo);
    return 0;
}
