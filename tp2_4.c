#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int velocidad;        // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio;             // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu;       // Tipo de procesador (apuntador a cadena de caracteres)
} compu;

int generar_valores_aleatorios(int limite_inferior, int limite_superior){
    int numero = 
}