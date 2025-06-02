#ifndef PROCESSOR_H
#define PROCESSOR_H

#define MAX_CIUDADES 100

typedef struct Nodo {
    int destino;
    int peso;
    struct Nodo* sig;
} Nodo;

typedef struct Grafo {
    int numVertices;
    char* nombres[MAX_CIUDADES];
    Nodo* adyacentes[MAX_CIUDADES];
} Grafo;

Grafo* crearGrafoDesdeArchivo(const char* filename);
void encontrarRutaMinima(Grafo* grafo, const char* origen, const char* destino);
void liberarGrafo(Grafo* grafo);
int obtenerIndice(Grafo* grafo, const char* ciudad);

#endif
