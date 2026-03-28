#include <stdio.h>
#include "productos.h"

int main() {
    Producto catalogo[MAX_PRODUCTOS] = {
        {1, "Hamburguesa Clasica",  18500.0},
        {2, "Pizza Margarita",      25000.0},
        {3, "Perro Caliente",       12000.0},
        {4, "Ensalada Cesar",       15000.0},
        {5, "Jugo Natural 500ml",    6000.0},
        {6, "Papas Fritas Grandes",  9500.0}
    };

    ItemCarrito carrito[MAX_CARRITO];
    int totalItems = 0;
    int opcion;

    printf("Bienvenido al Sistema de Domicilios\n");

    do {
        printf("\n|========= MENU PRINCIPAL =========|\n");
        printf("|1. Ver menu de productos|\n");
        printf("|2. Agregar producto al carrito|\n");
        printf("|3. Ver carrito y total|\n");
        printf("|4. Confirmar pedido|\n");
        printf("|5. Salir|\n");
        printf("|===================================|\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: mostrarProductos(catalogo, MAX_PRODUCTOS); break;
            case 2: agregarAlCarrito(catalogo, MAX_PRODUCTOS, carrito, &totalItems); break;
            case 3: verCarrito(carrito, totalItems); break;
            case 4: confirmarPedido(carrito, totalItems); break;
            case 5: printf("Hasta luego!\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 5);

    return 0;
}