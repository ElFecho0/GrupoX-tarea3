#ifndef PROCESSOR_H
#define PROCESSOR_H

#define MAX_CIUDADES 100

// Se define la estructura del nodo, para poder implementar correctamente el grafo
typedef struct Nodo {
    int destino;
    int peso;
    struct Nodo* sig;
} Nodo;

// Se define la estructura del grafo, la cual posee los nodos y sus nombres, como asi tambien la cantidad de vertices
typedef struct Grafo {
    int numVertices;
    char* nombres[MAX_CIUDADES];
    Nodo* adyacentes[MAX_CIUDADES];
} Grafo;

// Se indica la creación de las siguientes funciones
// La primera se encarga de crear el grafo
Grafo* crearGrafoDesdeArchivo(const char* filename);
// La segunda se encarga de encontrar e imprimir la ruta minima buscada mediante Dijkstra
void encontrarRutaMinima(Grafo* grafo, const char* origen, const char* destino);
// La tercera se encarga de liberar la memoria en la cual esta guardado el grafo
void liberarGrafo(Grafo* grafo);
// La cuarta se encarga de obtener los diferentes indices para las ciudades en el grafo
int obtenerIndice(Grafo* grafo, const char* ciudad);

#endif
