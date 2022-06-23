#ifndef COLACIRCULAR_H_INCLUDED
#define COLACIRCULAR_H_INCLUDED

#include "basico.h"

// OPERACIONES DEL TAD COLA
void insertar(ColaCircular *colaC, Cliente *dato);

// OPERACIONES AUXILIARES
ColaCircular *crearColaCircular();
int validarEspacioCC(ColaCircular colaC);
int validarVacioCC(ColaCircular colaC);
void listarCC(ColaCircular colaC);
Cliente *borrar(ColaCircular *colaC);

#endif // COLACIRCULAR_H_INCLUDED
