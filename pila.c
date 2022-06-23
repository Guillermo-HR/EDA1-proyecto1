#include "pila.h"

// Principales
Pila *crearPila(int max)
{
    Pila *nuevaPila;
    nuevaPila = (Pila *)calloc(1, sizeof(Pila));
    if (nuevaPila == NULL)
    {
        printf("\nNo se pudeo crear la pila");
        exit(-1);
    }
    nuevaPila->arrPila = (int *)calloc(max, sizeof(int));
    if (nuevaPila->arrPila == NULL)
    {
        printf("\nError al crear la pila");
        exit(-1);
    }
    nuevaPila->tope = -1;
    nuevaPila->max = max;

    return nuevaPila;
}

void push(Pila *pila, int aux)
{
    if (validarEspacio(*pila))
    {
        pila->tope++;
        pila->arrPila[pila->tope] = aux;

        return;
    }
    printf("\nNo hay espacio disponible en la pila");
}

void listar(Pila pila, int max, Pizza arreglo_pizzas[max])
{
    int i;
    for (i = pila.tope; i > -1; i--)
    {
        printf("%s\n", arreglo_pizzas[pila.arrPila[i]-1].nombrePizza);
    }
    return;
}

int pop(Pila *pila)
{
    if (validarVacio(*pila))
    {
        pila->tope--;
        return pila->arrPila[pila->tope + 1];
    }
    return 0;
}

// Auxileares
int verificar(int max)
{
    if (max <= 0)
    {
        system("clear");
        printf("tamaño no valido");
        return 0;
    }
    return 1;
}

int validarEspacio(Pila pila)
{
    return pila.tope < pila.max - 1;
}

int validarVacio(Pila pila)
{
    return pila.tope > -1;
}

void liberar(Pila *pila)
{
    free(pila->arrPila);
    free(pila);
}

