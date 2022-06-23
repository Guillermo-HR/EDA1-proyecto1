#ifndef basico_h
#define basico_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define Max_len_str 30
#define Max_ColaC 10

typedef struct{
    int clave;
    char *nombrePizza;
    int *ingredientes;
    float precio;

}Pizza;

typedef struct {
    int *arrPila;
    int max;
    int tope;
} Pila;

typedef struct{
    int orden;//Se genera en orden
    char *nombreCliente;
    int cantidad;
    Pila *pila;
    float total;

}Cliente;

typedef struct
{
    int max; // tama?o de la cola
    int h;
    int t;
    Cliente *arrCola[Max_ColaC]; // arreglo cola
} ColaCircular;

typedef struct
{
    int max;      // tama�o de la cola
    int h;        // inicio
    int t;        // final
    int *arrCola; // arreglo cola
} Cola;
#endif
