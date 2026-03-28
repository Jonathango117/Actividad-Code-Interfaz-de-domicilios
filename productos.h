#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#define MAX_PRODUCTOS 6
#define MAX_CARRITO   10

typedef struct {
    int   id;
    char  nombre[50];
    float precio;
} Producto;

typedef struct {
    Producto producto;
    int      cantidad;
} ItemCarrito;

void mostrarProductos(Producto catalogo[], int total);
void agregarAlCarrito(Producto catalogo[], int totalProductos,
                      ItemCarrito carrito[], int *totalItems);
void verCarrito(ItemCarrito carrito[], int totalItems);
void confirmarPedido(ItemCarrito carrito[], int totalItems);

#endif