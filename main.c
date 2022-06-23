// Directivas
#include "funciones.h"
#include "colaCircular.h"
#include "pila.h"

int main()
{
    int N_menu, i;
    char catalogoIngredientes[12][Max_len_str] = {"Masa", "Tomate", "Queso", "Peperoni", "Aceitunas", "Cebolla", "Pimiento", "Jamon", "Salami", "Chorizo", "Tocino", "Pinia"};
    system("clear");
    do
    {
        printf("Cuantas pizzas quiere guardar? ");
        scanf("%i", &N_menu);
    } while (N_menu < 1);
    Pizza arreglo_pizzas[N_menu];
    crear_menu(N_menu, arreglo_pizzas, catalogoIngredientes);
    system("clear");
    ColaCircular *colaC;
    Cliente *temporal = NULL;
    colaC = crearColaCircular();
    int n_orden = 0, ciclo = 1;
    while (!validarVacioCC(*colaC) || temporal != NULL || ciclo)
    {
        system("clear");
        sleep(1);
        srand(time(0));
        if (rand() % 3 != 0 && validarEspacioCC(*colaC) && ciclo)
        { // Registrar cliente
            menu(N_menu, arreglo_pizzas, catalogoIngredientes);
            llenar_cliente(colaC, N_menu, arreglo_pizzas, n_orden);
            if (!validarVacioCC(*colaC) || temporal != NULL)
            {
                printf("\n\n---------------------------------------------\n");
                printf("Pendientes: \n");
                if (temporal != NULL)
                    printf("\nNo. orden: %i\tPizzas pendientes: %i\n", temporal->orden, temporal->cantidad);
                listarCC(*colaC);
                printf("---------------------------------------------\n");
                sleep(3);
            }
            else
                printf("\nNo hay pendientes\n");
            printf("\n");
            n_orden++; 
        }
        if (!validarVacioCC(*colaC) || temporal != NULL)
        { // preparar pizza
            printf("Cocina\n");
            if (temporal == NULL)
                temporal = borrar(colaC);
            if (temporal != NULL)
            {
                printf("\nOrden: %i", temporal->orden);
                printf("\nPreparando pizza: %s", arreglo_pizzas[pop(temporal->pila) - 1].nombrePizza);
                temporal->cantidad--;
            }
            if (temporal->cantidad == 0)
            {
                printf("\nPedido: %i terminado y entregado", temporal->orden);
                temporal = NULL;
                if (!validarVacioCC(*colaC))
                {
                    temporal = borrar(colaC);
                    printf("\nOrden: %i", temporal->orden);
                }
            }
            if (temporal != NULL)
            {
                printf("\nPreparando pizza: %s", arreglo_pizzas[pop(temporal->pila) - 1].nombrePizza);
                temporal->cantidad--;
                if (temporal->cantidad == 0)
                {
                    printf("\nPedido: %i terminado y entregado", temporal->orden);
                    temporal = NULL;
                }
            }
            printf("\n\n---------------------------------------------");
            if (!validarVacioCC(*colaC) || temporal != NULL)
            {
                printf("\nPendientes:\n");
                if (temporal != NULL)
                    printf("\nNo. orden: %i\tPizzas pendientes: %i\n", temporal->orden, temporal->cantidad);
                listarCC(*colaC);
                printf("---------------------------------------------\n");
                sleep(3);
            }
            else
                printf("\nNo hay pendientes\n");
        }
        if (ciclo == 1)
        {
            do
            {
                printf("\nQuiere aceptar mas clientes? (1/0)");
                scanf("%i", &ciclo);
            } while (ciclo != 0 && ciclo != 1);
        }
    }
    sleep(3);
    system("clear");
    printf("Se termino el sevicio");
    return 0;
}
