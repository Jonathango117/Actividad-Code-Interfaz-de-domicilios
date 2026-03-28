# Actividad-Code-Interfaz-de-domicilios
Actividad y realización de consola en C que simule un flujo básico de domicilios mediante un menú interactivo, aplicando condicionales (if/else, switch) y ciclos (while, do…while, for).

🍔 Sistema de Domicilios — Lenguaje C
Aplicación de consola desarrollada en C que simula un flujo básico de pedidos a domicilio. El usuario puede explorar un catálogo de productos, agregar ítems a un carrito, ver el resumen y confirmar su pedido con cálculo de IVA y domicilio.

📋 Descripción
Este proyecto fue desarrollado como actividad académica para aplicar estructuras de selección y control en C, incluyendo if/else, switch, while, do...while y for.

✅ Funcionalidades

Menú interactivo con navegación por opciones numéricas
Catálogo de 6 productos con ID, nombre y precio
Agregar productos al carrito validando:

Que el ID del producto exista
Que la cantidad sea mayor a 0


Ver carrito con subtotal por línea
Confirmar pedido con desglose de:

Subtotal
Costo de domicilio ($5.000)
IVA del 19%
Total final




🗂️ Estructura del proyecto
tienda-domicilios/
├── main.c        → Punto de entrada, menú principal (switch + do...while)
├── productos.h   → Declaración de structs y funciones (include guard)
├── productos.c   → Implementación: catálogo, carrito, pedido
└── README.md     → Este archivo

🚀 Compilar y ejecutar
Abre la terminal en la carpeta del proyecto y ejecuta:

bashgcc main.c productos.c -o tienda

Luego corre el programa:
./tienda



📦 Catálogo de productos
IDProductoPrecio1Hamburguesa Clásica$18.5002Pizza Margarita$25.0003Perro Caliente$12.0004Ensalada César$15.0005Jugo Natural 500ml$6.0006Papas Fritas Grandes$9.500