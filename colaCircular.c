#include "colaCircular.h"

ColaCircular *crearColaCircular()
{
    ColaCircular *nuevaCola;
    nuevaCola = (ColaCircular *)malloc(sizeof(ColaCircular));
    nuevaCola->max = Max_ColaC;
    nuevaCola->h = nuevaCola->t = -1;
    return nuevaCola;
}

int validarEspacioCC(ColaCircular colaC)
{
    if ((colaC.h == 0 && colaC.t == colaC.max - 1) || (colaC.t == colaC.h - 1))
        return 0;
    return 1;
}

void insertar(ColaCircular *colaC, Cliente *dato)
{
    if (colaC->h == -1)
        colaC->h = 0; // INICIO DE LA FILA
    if (colaC->t == colaC->max)
        colaC->t = -1;

    colaC->t++;

    // INSERTA EL DATO EN LA FILA
    colaC->arrCola[colaC->t] = dato;
    printf("\nPedido agregado a la cola");
}

void listarCC(ColaCircular colaC)
{
    if (!validarVacioCC(colaC))
    {
        int i;
        if (colaC.h <= colaC.t)
            for (i = colaC.h; i <= colaC.t; i++)
                printf(" \nNo. orden: %i\t Pizzas pendientes: %i\n", colaC.arrCola[i]->orden, colaC.arrCola[i]->cantidad);
        else
        {
            for (i = colaC.h; i < colaC.max; i++)
                printf(" \nNo. orden: %i\t Pizzas pendientes: %i\n", colaC.arrCola[i]->orden, colaC.arrCola[i]->cantidad);
            for (i = 0; i <= colaC.t; i++)
                printf(" \nNo. orden: %i\t Pizzas pendientes: %i\n", colaC.arrCola[i]->orden, colaC.arrCola[i]->cantidad);
        }
    }
}

int validarVacioCC(ColaCircular colaC)
{
    return colaC.h == -1;
}

Cliente *borrar(ColaCircular *colaC)
{
    Cliente *aux = colaC->arrCola[colaC->h];
    if (aux==NULL)
    {
        return NULL;
    }
    else if (colaC->h == colaC->t)
        colaC->h = colaC->t = -1;
    else if (colaC->h == colaC->max-1)
        colaC->h = 0;
    else
        colaC->h++;
    return aux;
}
