#include <stdio.h>
#include <math.h>
#include "operaciones.h"
#include "lecturas.h"

// Funcion para agregar un producto al inventario
int agregarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numChocolates) {
    if (numChocolates < MAX_CHOCOLATES) { // Verificar si hay espacio disponible en el inventario
        
        printf("Ingrese el nombre del producto: ");
        scanf("%s", nombres[numChocolates]); // Lee el nombre del producto
        
        cantidades[numChocolates]=leerEnteroPositivo("Ingrese la cantidad del chocolate: ");// Lee la cantidad del producto
        //printf("Ingrese la cantidad del producto: ");
        //scanf("%d", &cantidades[numProductos]); 
        
        precios[numChocolates]=leerFlotantePositivo("Ingrese el precio del chocolate: ");// Lee el precio del producto
        //printf("Ingrese el precio del producto: ");
        //scanf("%f", &precios[numProductos]); 
        printf("Producto registrado exitosamente\n");
        
        return numChocolates + 1; // Devuelve el numero actualizado de productos
    } else {
        printf("No se pueden agregar más productos. Se ha alcanzado el límite.\n");
        return numChocolates; // Devuelve el mismo numero de productos si no se pudo agregar mas
    }
}

// Funcion para imprimir todos los productos en el inventario
void imprimirProductos(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numChocolates) {
    printf("\nProductos registrados:\n");
    for (int i = 0; i < numChocolates; i++) {
        printf("Nombre: %s\n", nombres[i]); // Imprime el nombre del producto
        printf("Cantidad: %d\n", cantidades[i]); // Imprime la cantidad del producto
        printf("Precio: %.2f\n", precios[i]); // Imprime el precio del producto
        printf("\n");
    }
}

// Funcion para buscar un producto por su nombre
void buscarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numChocolates) {
    printf("\nIngrese el nombre del producto a buscar: ");
    char nombreBuscar[MAX_NOMBRE];
    scanf("%s", nombreBuscar); // Lee el nombre del producto a buscar
    int encontrado = 0;
    for (int i = 0; i < numChocolates ; i++) {
        int j;
        for (j = 0; nombres[i][j] != '\0' && nombreBuscar[j] != '\0'; j++) {
            if (nombres[i][j] != nombreBuscar[j]) { // Compara los nombres caracter por caracter
                break;
            }
        }
        if (nombres[i][j] == '\0' && nombreBuscar[j] == '\0') { // Si los nombres coinciden completamente
            printf("Chocolate encontrado:\n\n");
            printf("Nombre: %s\n", nombres[i]); // Imprime el nombre del producto encontrado
            printf("Cantidad: %d\n", cantidades[i]); // Imprime la cantidad del producto encontrado
            printf("Precio: %.2f\n", precios[i]); // Imprime el precio del producto encontrado
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Chocolate no encontrado.\n"); // Mensaje si el producto no fue encontrado
    }
}