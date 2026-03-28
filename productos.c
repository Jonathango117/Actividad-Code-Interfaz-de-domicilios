#include <stdio.h>
#include <string.h>
#include "productos.h"

void mostrarProductos(Producto catalogo[], int total) {
    printf("\n========== MENU DE PRODUCTOS ==========\n");
    printf("%-5s %-25s %s\n", "ID", "Producto", "Precio");
    printf("----------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("%-5d %-25s $%.2f\n",
               catalogo[i].id,
               catalogo[i].nombre,
               catalogo[i].precio);
    }
    printf("========================================\n");
}

void agregarAlCarrito(Producto catalogo[], int totalProductos,
                      ItemCarrito carrito[], int *totalItems) {
    int idBuscado, cantidad;

    printf("\nIngresa el ID del producto: ");
    scanf("%d", &idBuscado);

    int encontrado = 0, i = 0;
    while (i < totalProductos && !encontrado) {
        if (catalogo[i].id == idBuscado)
            encontrado = 1;
        else
            i++;
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
        return;
    }

    do {
        printf("Cantidad (debe ser > 0): ");
        scanf("%d", &cantidad);
        if (cantidad <= 0)
            printf("Cantidad invalida. Intenta de nuevo.\n");
    } while (cantidad <= 0);

    carrito[*totalItems].producto = catalogo[i];
    carrito[*totalItems].cantidad = cantidad;
    (*totalItems)++;

    printf("'%s' x%d agregado al carrito.\n", catalogo[i].nombre, cantidad);
}

void verCarrito(ItemCarrito carrito[], int totalItems) {
    if (totalItems == 0) {
        printf("\nEl carrito esta vacio.\n");
        return;
    }
    printf("\n============= TU CARRITO ==============\n");
    printf("%-25s %-8s %-10s\n", "Producto", "Cant.", "Subtotal");
    printf("---------------------------------------\n");
    float subtotal = 0;
    for (int i = 0; i < totalItems; i++) {
        float linea = carrito[i].producto.precio * carrito[i].cantidad;
        subtotal += linea;
        printf("%-25s %-8d $%.2f\n",
               carrito[i].producto.nombre,
               carrito[i].cantidad,
               linea);
    }
    printf("---------------------------------------\n");
    printf("Subtotal: $%.2f\n", subtotal);
}

void confirmarPedido(ItemCarrito carrito[], int totalItems) {
    if (totalItems == 0) {
        printf("\nNo puedes confirmar un pedido vacio.\n");
        return;
    }
    float subtotal = 0;
    for (int i = 0; i < totalItems; i++)
        subtotal += carrito[i].producto.precio * carrito[i].cantidad;

    float domicilio = 5000.0;
    float impuesto  = subtotal * 0.19;
    float total     = subtotal + domicilio + impuesto;

    printf("\n======== RESUMEN DEL PEDIDO ========\n");
    printf("Subtotal:  $%.2f\n", subtotal);
    printf("Domicilio: $%.2f\n", domicilio);
    printf("IVA (19%%): $%.2f\n", impuesto);
    printf("------------------------------------\n");
    printf("TOTAL:     $%.2f\n", total);
    printf("Pedido confirmado! En camino...\n");
}