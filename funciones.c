#include "basico.h"
#include "funciones.h"
#include "pila.h"
#include "colaCircular.h"

void crear_menu(int N_menu, Pizza *arreglo_pizzas, char catalogoIngredientes[12][Max_len_str])
{
    int indice = 0, j, ingrediente, corregir, bandera;
    do
    {
        bandera = 0;
        system("clear");
        arreglo_pizzas->clave = indice + 1;
        printf("Pizza clave: %i", arreglo_pizzas->clave);
        arreglo_pizzas->nombrePizza = (char *)malloc(Max_len_str * sizeof(char));
        arreglo_pizzas->ingredientes = (int *)calloc(12, sizeof(int));
        printf("\nNombre de la pizza: ");
        fflush(stdin);
        fgets(arreglo_pizzas->nombrePizza, Max_len_str, stdin);
        printf("\nIngredientes (masa ya incluida): ");
        for (j = 1; j < 12; j++)
            printf("\n%i.-%s", j, catalogoIngredientes[j]);
        printf("\nPara guardar los ingredientes ingrese 12");
        arreglo_pizzas->ingredientes[0] = 1;
        do
        {
            printf("\nIngrediente: ");
            scanf("%i", &ingrediente);
            if (ingrediente > 0 && ingrediente < 12)
            {
                arreglo_pizzas->ingredientes[ingrediente]++;
                bandera++;
            }
            else if (ingrediente != 12)
                printf("\tIngrediente no valido");
        } while (bandera == 0 || (ingrediente != 12 && bandera < 11));
        do
        {
            printf("\n\nPrecio: ");
            scanf("%f", &arreglo_pizzas->precio);
        } while (arreglo_pizzas->precio <= 0);
        system("clear");
        listar_pizza(*arreglo_pizzas, catalogoIngredientes);
        printf("\nPara guardar la pizza ingrese 0, para corregir cualquier otro numero\t");
        scanf("%i", &corregir);
        if (!corregir)
        {
            indice++;
            arreglo_pizzas++;
        }
    } while (indice < N_menu);
}

void listar_pizza(Pizza arreglo_pizzas, char catalogoIngredientes[12][Max_len_str])
{
    int i;
    printf("\nNombre de la pizza: %s", arreglo_pizzas.nombrePizza);
    printf("Clave: %i", arreglo_pizzas.clave);
    printf("\nIngrediente(s): ");

    for (i = 0; i < 12; i++)
    {
        switch (arreglo_pizzas.ingredientes[i])
        {
        case 0:
            break;
        case 1:
            printf("\n\t%s", catalogoIngredientes[i]);
            break;
        case 2:
            printf("\n\tDoble %s", catalogoIngredientes[i]);
            break;
        case 3:
            printf("\n\tTriple %s", catalogoIngredientes[i]);
            break;
        default:
            printf("\n\t%i porciones de %s", arreglo_pizzas.ingredientes[i], catalogoIngredientes[i]);
            break;
        }
    }
    printf("\nPrecio: $%0.2f\n", arreglo_pizzas.precio);
}

void llenar_cliente(ColaCircular *colaC, int max, Pizza arreglo_pizzas[max], int i)
{
    Cliente *nuevoCliente;
    int j, aux;
    nuevoCliente = (Cliente *)malloc(sizeof(Cliente));
    if (nuevoCliente == NULL)
    {
        printf("Error interno");
        exit(0);
    }
    nuevoCliente->nombreCliente = (char *)malloc(Max_len_str * sizeof(char));
    if (nuevoCliente->nombreCliente == NULL)
    {
        printf("Error interno");
        exit(0);
    }
    nuevoCliente->orden = i + 1;
    printf("\nDame tu nombre: ");
    fflush(stdin);
    fgets(nuevoCliente->nombreCliente, Max_len_str, stdin);
    do
    {
        printf("\nCuantas pizzas vas a pedir: ");
        scanf("%i", &nuevoCliente->cantidad);
    } while (nuevoCliente->cantidad < 1);
    nuevoCliente->pila = crearPila(nuevoCliente->cantidad);
    nuevoCliente->total = 0;
    for (j = 0; j < nuevoCliente->cantidad; j++)
    {
        do
        {
            printf("\nIngrese la clave de la pizza que quieres: ");
            scanf("%i", &aux);
        } while (aux < 1 || aux > max);
        push(nuevoCliente->pila, aux);
        nuevoCliente->total += arreglo_pizzas[aux - 1].precio;
    }
    system("clear");
    printf("\n----------------------\nNota\n");
    printf("Nombre: %s", nuevoCliente->nombreCliente);
    printf("No. orden: %i", nuevoCliente->orden);
    printf("\nCantidad de pizzas: %i", nuevoCliente->cantidad);
    printf("\nPizzas pedidas:\n");
    listar(*nuevoCliente->pila, max, arreglo_pizzas);
    printf("Total a pagar: $%0.2f\n", nuevoCliente->total);
    printf("----------------------\n");
    insertar(colaC, nuevoCliente);
    sleep(5);
}

void menu(int max, Pizza arreglo_pizzas[max], char catalogoIngredientes[12][30])
{
    printf("******************");
    printf("\n*     Menu       *");
    printf("\n******************\n");
    int i;
    for (i = 0; i < max; i++)
        listar_pizza(arreglo_pizzas[i], catalogoIngredientes);
}
