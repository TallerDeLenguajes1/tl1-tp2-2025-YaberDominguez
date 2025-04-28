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
    /*Genero un numero aleatorio con rand y pongo el intervalo */
    int numero = limite_inferior + rand() % (limite_superior - limite_inferior + 1);
    return numero;
}

char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core",
    "Pentium"};

int main(){
    compu computadoras[5];
    int indice;
    for (int i = 0; i < 5; i++)
    {
        computadoras[i].velocidad = generar_valores_aleatorios(1,3);
        computadoras[i].anio = generar_valores_aleatorios(2015,2024);
        computadoras[i].cantidad_nucleos = generar_valores_aleatorios(1,8);
        indice = generar_valores_aleatorios(0,5);
        computadoras[i].tipo_cpu = tipos[indice];
    }
    
}