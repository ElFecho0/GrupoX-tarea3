#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include "processor.h"

#define MAX_LINE 100
#define MAX_CIUDADES 100

// Funciones Auxiliares

int obtenerIndice(Grafo* g, const char* ciudad) {
    for (int i = 0; i < g->numVertices; i++) {
        if (strcmp(g->nombres[i], ciudad) == 0)
            return i;
    }
    return -1;
}

int agregarCiudad(Grafo* g, const char* ciudad) {
    int idx = obtenerIndice(g, ciudad);
    if (idx != -1) return idx;
    g->nombres[g->numVertices] = malloc(strlen(ciudad) + 1);
    strcpy(g->nombres[g->numVertices], ciudad);
    g->adyacentes[g->numVertices] = NULL;
    return g->numVertices++;
}

void agregarArista(Grafo* g, const char* origen, const char* destino, int peso) {
    int i = agregarCiudad(g, origen);
    int j = agregarCiudad(g, destino);

    Nodo* nuevo1 = malloc(sizeof(Nodo));
    nuevo1->destino = j;
    nuevo1->peso = peso;
    nuevo1->sig = g->adyacentes[i];
    g->adyacentes[i] = nuevo1;

    Nodo* nuevo2 = malloc(sizeof(Nodo));
    nuevo2->destino = i;
    nuevo2->peso = peso;
    nuevo2->sig = g->adyacentes[j];
    g->adyacentes[j] = nuevo2;
}

// Lectura de archivo

Grafo* crearGrafoDesdeArchivo(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) return NULL;

    Grafo* g = malloc(sizeof(Grafo));   
    g->numVertices = 0;

    char origen[10], destino[10];
    int peso;

    while (fscanf(f, "%s %s %d", origen, destino, &peso) == 3) {
        agregarArista(g, origen, destino, peso);
    }    

    fclose(f);
    return g;
}

// Algoritmo de Dijkstra

void encontrarRutaMinima(Grafo* g, const char* origen, const char* destino) {
    int n = g->numVertices;
    int dist[n], prev[n];
    bool visitado[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
        visitado[i] = false;
    }

    int src = obtenerIndice(g, origen);
    int dst = obtenerIndice(g, destino);
    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1, minDist = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!visitado[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;
        visitado[u] = true;

        Nodo* nodo = g->adyacentes[u];
        while (nodo) {
            int v = nodo->destino;
            if (!visitado[v] && dist[u] + nodo->peso < dist[v]) {
                dist[v] = dist[u] + nodo->peso;
                prev[v] = u;
            }
            nodo = nodo->sig;
        }
    }

    // reconstruir camino
    if (dist[dst] == INT_MAX) {
        printf("No hay ruta entre %s y %s\n", origen, destino);
        return;
    }

    int ruta[n], len = 0, actual = dst;
    while (actual != -1) {
        ruta[len++] = actual;
        actual = prev[actual];
    }

    printf("Ruta óptima: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%s", g->nombres[ruta[i]]);
        if (i != 0) printf(" -> ");
    }
    printf("\nDistancia total: %d km\n", dist[dst]);
}

// Liberar memoria

void liberarGrafo(Grafo* g) {
    for (int i = 0; i < g->numVertices; i++) {
        Nodo* actual = g->adyacentes[i];
        while (actual) {
            Nodo* temp = actual;
            actual = actual->sig;
            free(temp);
        }
        free(g->nombres[i]);
    }
    free(g);
}
