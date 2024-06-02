/*UNIVERSIDAD DE LAS AMERICAS
Integrantes: Josue Chiriboga
             Nicole Yepez
             Gustavo Zarate
Fecha: 02/06/2024
Semana 8
Actividad: Taller Colaborativo (Sistema de Inventario)*/
#include <stdio.h>
#include "operaciones.c"
#include "lecturas.c"

int main() {
    char nombres[MAX_CHOCOLATES][MAX_NOMBRE]; // Arreglo para almacenar los nombres de los productos
    int cantidades[MAX_CHOCOLATES]; // Arreglo para almacenar las cantidades de los productos
    float precios[MAX_CHOCOLATES]; // Arreglo para almacenar los precios de los productos
    int numProductos = 0; // Numero actual de productos
    int opcion; // Opcion seleccionada por el usuario

    do {
        printf("\n-----------------SISTEMA DE INVENTARIO-----------------\n\n");
        printf("1. Ingresar chocolate\n");
        printf("2. Imprimir chocolate\n");
        printf("3. Buscar chocolate\n");
        printf("4. Salir\n");
        printf("\nIngrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                numProductos = agregarProducto(nombres, cantidades, precios, numProductos);
                break;
            case 2:
                imprimirProductos(nombres, cantidades, precios, numProductos);
                break;
            case 3:
                buscarProducto(nombres, cantidades, precios, numProductos);
                break;
            case 4:
                printf("\nCerrando el sistema de inventario\n");
                break;
            default:
                printf("\nOpcion incorrecta. Ingresar nuevamente.\n");
        }
    } while (opcion != 4);

    return 0;
}
