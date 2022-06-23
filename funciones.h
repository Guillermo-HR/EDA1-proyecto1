#ifndef funciones_h
#define funciones_h

// Include
#include "basico.h"

// Prototipos
void crear_menu(int N_menu, Pizza *arreglo_pizzas, char catalogoIngredientes[12][30]);
void listar_pizza(Pizza arreglo_pizzas, char catalogoIngredientes[12][30]);
void llenar_cliente(ColaCircular *cola, int max, Pizza arrelo_pizzas[max], int i);
void menu(int max, Pizza arreglo_pizzas[max], char catalogoIngredientes[12][30]);
#endif
