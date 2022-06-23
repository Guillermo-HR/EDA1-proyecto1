#ifndef pila_h
#define pila_h

#include "basico.h"

// PROTOTIPOS
// Principales
Pila *crearPila(int max);
void push(Pila *pila, int aux);
void listar(Pila pila, int max, Pizza arreglo_pizzas[max]);
int pop(Pila *pila);
// Auxileares
int verificar(int max);
int validarEspacio(Pila pila);
int validarVacio(Pila pila);

void liberar(Pila *pila);

#endif
