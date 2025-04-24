/*
    Ejercicio Integrador: Sistema de Gestion de Inventario

    Desarrollar un programa que simule un sistema de gestion de inventario
    para una tienda de electronica. El programa debe permitir:
    1. Agregar productos al inventario
    2. Buscar productos por nombre o codigo
    3. Actualizar stock de productos
    4. Mostrar todos los productos
    5. Mostrar estadisticas (cantidad total de productos, unidades en inventario, precio promedio,
                             valor total, productos mas costosos/economicos,
                             productos sin stock o con stock bajo)
    6. Salir
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROD_MAX 50

char nombres[PROD_MAX][20]; //{"prod1", "prod2", etc...}
int codigos[PROD_MAX];      //{1,2,3,4,5,...}
float precios[PROD_MAX];    //{3.5,4.9,12.3,...}
int stock[PROD_MAX];        //{6,7,1,9,...}
int ultimoProducto = 0;

void agregarProducto();
void mostrarMenu();
void procesarOpcion(int opcion);
void mostrarProductos();

int main(){
    int opcion = 0;
    char buffer[100];
    do{
        system("cls");
        mostrarMenu();
        printf("\nIngresar opcion: ");
        if (fgets(buffer,sizeof(buffer),stdin) != NULL){
            if (sscanf(buffer, "%d", &opcion) != 1){
                printf("Entrada invalida. \n");
                printf("Presione una tecla para continuar... \n");
                getchar();
                continue;
            }
        }
        else {
            printf("Error al leer la entrada. \n");
            printf("Presione una tecla para continuar... \n");
            getchar();
            continue;
        }
        procesarOpcion(opcion);
    } while(opcion != 6);

    return 0;
}
void mostrarMenu(){
    printf("---Sistema de gestion de productos ---. \n");
    printf("1. Agregar producto al inventario. \n");
    printf("2. Buscar producto. \n");
    printf("3. Actualizar stock. \n");
    printf("4. Mostrar todos los productos. \n");
    printf("5. Mostrar estadisticas. \n");
    printf("6. Salir. \n");

}
void procesarOpcion(int opcion){
    switch(opcion){
    case 1:
        agregarProducto();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        mostrarProductos();
        break;
    case 5:
        break;
    case 6:
        printf("Hasta luego! \n");
        printf("Presione una tecla para continuar... \n");
        getchar();
        break;
    default:
        printf("Opcion invalida. \n");
        printf("Presione una tecla para continuar... \n");
        getchar();
    }
}

void agregarProducto(){
    system("cls");
    printf("--- Agregar nuevo producto --- \n");

    char buffer[100];

    printf("Ingrese el nombre del producto: ");
        if (fgets(buffer,sizeof(buffer),stdin) != NULL){
            if (sscanf(buffer, "%s", &nombres[ultimoProducto]) != 1){
                printf("Entrada invalida. \n");
                printf("Presione una tecla para continuar... \n");
                getchar();

            }
        }
        else {
            printf("Error al leer la entrada. \n");
            printf("Presione una tecla para continuar... \n");
            getchar();

        }
        printf("Ingrese el codigo del producto: ");
        if (fgets(buffer,sizeof(buffer),stdin) != NULL){
            if (sscanf(buffer, "%d", &codigos[ultimoProducto]) != 1){
                printf("Entrada invalida. \n");
                printf("Presione una tecla para continuar... \n");
                getchar();

            }
        }
        else {
            printf("Error al leer la entrada. \n");
            printf("Presione una tecla para continuar... \n");
            getchar();

        }
        printf("Ingrese el precio del producto: ");
        if (fgets(buffer,sizeof(buffer),stdin) != NULL){
            if (sscanf(buffer, "%f", &precios[ultimoProducto]) != 1){
                printf("Entrada invalida. \n");
                printf("Presione una tecla para continuar... \n");
                getchar();

            }
        }
        else {
            printf("Error al leer la entrada. \n");
            printf("Presione una tecla para continuar... \n");
            getchar();

        }
        printf("Ingrese el stock del producto: ");
        if (fgets(buffer,sizeof(buffer),stdin) != NULL){
            if (sscanf(buffer, "%d", &stock[ultimoProducto]) != 1){
                printf("Entrada invalida. \n");
                printf("Presione una tecla para continuar... \n");
                getchar();

            }
        }
        else {
            printf("Error al leer la entrada. \n");
            printf("Presione una tecla para continuar... \n");
            getchar();

        }
        ultimoProducto++;

}
void mostrarProductos(){
    system("cls");
    printf("--- Mostrar prodcutos --- \n");

    for(int i = 0; i < ultimoProducto; i++){
        printf("Producto #%d\n", i+1);
        printf("Nombre: %s\n", nombres[i]);
        printf("Codigo: %d\n", codigos[i]);
        printf("Precio: %.2f\n", precios[i]);
        printf("Stock: %d\n", stock[i]);
        printf("--- ---------------- --- \n");
    }
    printf("Presione una tecla para continuar... \n");
    getchar();
}
