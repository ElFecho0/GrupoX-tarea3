# Tarea 3 EDA Grupo X 

## **Integrantes**
- **Fernando Flores Monsivais** <br>
  <fernandflores@alumnos.uai.cl>

- **Matías Silva** <br>
  <matiasasilva@alumnos.uai.cl>

- **Matías Sepulveda** <br>
  <@alumnos.uai.cl>

## **Forma de uso: Terminal**
- **Para correr el codigo escribe en la terminal:**
- **1: make (Activa el Makefile, crea un ejecutable del proyecto y compila)**
- **2: ./tarea3 rutas.txt "ARG1" "ARG2" (ejecuta main.c)**
- **3: make clean (para limpiar los archivos temporales que quitan recursos)**

## **Como funciona:**
- **El equipo optó por usar listas enlazadas para la realización de la tarea, ya que se hace más cómodo tanto para el manejo de datos, flexibilidad para añadir más nodos, y menor uso de memoria, se usa un Makefile que ejecuta todo el trabajo y este está organizado en distintos archivos para mejorar el debugging y evitar warnings. Este código se ejecuta y compila desde la terminal, donde se entrega el .txt y los argumentos (origen y destino) y entrega el camino hacia el destino, ademas de la suma de distancias hacia este. Se lee el .txt para hacer la lista y se toma en cuenta los argumentos que se ponen en la consola para el desarrollo del ejercicio, asegurando que no hayan mas argumentos. Finalmente se usa el algoritmo de 
Dijkstra para entregar la solución del ejercicio. Cada archivo tiene sus propios comentarios para una mejor comprensión del código**