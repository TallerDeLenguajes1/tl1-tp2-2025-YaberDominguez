#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int velocidad;        // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio;             // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu;       // Tipo de procesador (apuntador a cadena de caracteres)
} compu;

int generar_valores_aleatorios(int limite_inferior, int limite_superior)
{
    /*Genero un numero aleatorio con rand y pongo el intervalo en el cual quiero el numero.
        si pongo nomas rand y lo de superior - inferior + 1 me va a generar un numero entre 0
        y superior - inferior pero estoy perdiendo numeros asi que se le suma inferior para
        que el rango arranque desde donde yo quiero. ej:
        si quisiera generar entre 1 y 3 entonces si hago rand() % (limite_superior - limite_inferior + 1);
        genero 0,1,2 pero tendria que ser 1,2,3 asi que sumo el inferior y quedaria:
        si hace 0 + 1 por inferior es 1, si hace 1 + 1 por inferior queda 2 y si hace 2 + 1 queda 3
        lo que queremos que pase.
        */
    int numero = limite_inferior + rand() % (limite_superior - limite_inferior + 1);
    return numero;
}
void listarPCs(compu pcs[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("--PC numero %d--\n", i + 1);
        printf("Caracteristicas: \n");
        printf("-Velocidad de procesamiento: %d GHz\n", pcs[i].velocidad);
        printf("-Año de fabricacion: %d \n", pcs[i].anio);
        printf("-Cantidad de nucleos: %d \n", pcs[i].cantidad_nucleos);
        printf("-Tipo de procesador: %s \n", pcs[i].tipo_cpu);
    }
}
void mostrarMasVieja(compu pcs[], int cantidad)
{
    int viejo = 2024;
    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].anio < viejo)
        {
            viejo = pcs[i].anio;
        }
    }
    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].anio == viejo)
        {
            printf("--PC mas vieja--\n");
            printf("Caracteristicas: \n");
            printf("-Velocidad de procesamiento: %d GHz\n", pcs[i].velocidad);
            printf("-Año de fabricacion: %d \n", pcs[i].anio);
            printf("-Cantidad de nucleos: %d \n", pcs[i].cantidad_nucleos);
            printf("-Tipo de procesador: %s \n", pcs[i].tipo_cpu);
        }
    }
}

void mostrarMasVeloz(compu pcs[], int cantidad){
    int veloz = 1;
    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].velocidad > veloz)
        {
            veloz = pcs[i].velocidad;
        }
    }
    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].velocidad == veloz)
        {
            printf("--PC mas veloz--\n");
            printf("Caracteristicas: \n");
            printf("-Velocidad de procesamiento: %d GHz\n", pcs[i].velocidad);
            printf("-Año de fabricacion: %d \n", pcs[i].anio);
            printf("-Cantidad de nucleos: %d \n", pcs[i].cantidad_nucleos);
            printf("-Tipo de procesador: %s \n", pcs[i].tipo_cpu);
        }
    }
}

int main()
{
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core",
                         "Pentium"};
    int tamanio = 5; // Tamaño del arreglo a generar
    compu computadoras[tamanio];
    int indice;
    for (int i = 0; i < tamanio; i++)
    {
        computadoras[i].velocidad = generar_valores_aleatorios(1, 3);        // genero velocidad aleatoria entre 1,3
        computadoras[i].anio = generar_valores_aleatorios(2015, 2024);       // genero un año aleatorio entre 2015 y 2024
        computadoras[i].cantidad_nucleos = generar_valores_aleatorios(1, 8); // genero la cantidad de nucleos entre 1 y 8
        indice = generar_valores_aleatorios(0, 5);                           // Genero un indice aleatorio para hacer referencia al tipo de procesador segun el arreglo de caracteres tipos
        computadoras[i].tipo_cpu = tipos[indice];                            // genero un tipo de procesador aleatorio entre los 6 del arreglo tipo
    }
    listarPCs(computadoras,tamanio);
    mostrarMasVieja(computadoras,tamanio);
    mostrarMasVeloz(computadoras,tamanio)

}