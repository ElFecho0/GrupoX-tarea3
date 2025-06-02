// modules/sorter.c
#include <stdio.h>
#include <string.h>
#include "sorter.h"

void imprimirCiudadesOrdenadas(char** nombres, int cantidad) {
    // Copia para no modificar el arreglo original
    char* copia[cantidad];
    for (int i = 0; i < cantidad; i++) {
        copia[i] = nombres[i];
    }

    // Ordenar alfabéticamente (burbuja por simplicidad)
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (strcmp(copia[j], copia[j + 1]) > 0) {
                char* temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    printf("Ciudades ordenadas:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%s\n", copia[i]);
    }
}
