/*
    Ejercicio Integrador: Sistema de Gestión de Inventario

    Desarrollar un programa que simule un sistema de gestión de inventario
    para una tienda de electrónica. El programa debe permitir:
    1. Agregar productos al inventario
    2. Buscar productos por nombre o código
    3. Actualizar stock de productos
    4. Mostrar todos los productos
    5. Mostrar estadísticas (cantidad total de productos, unidades en inventario, precio promedio, valor total, productos más costosos/económicos, productos sin stock o con stock bajo)
    6. Salir

    El programa debe implementar:
    - Arrays paralelos para almacenar la información de los productos
    - Funciones para cada operación
    - Condicionales para validar entradas
    - Bucles para recorrer colecciones y repetir operaciones
    - Uso apropiado de librerías estándar
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTOS 50
#define MAX_NOMBRE 30

// Variables globales (arrays paralelos)
char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
int codigos[MAX_PRODUCTOS];
float precios[MAX_PRODUCTOS];
int stock[MAX_PRODUCTOS];
int totalProductos = 0;

// Prototipos de funciones
void agregarProducto();
void buscarProducto();
void buscarPorNombre();
void buscarPorCodigo();
void actualizarStock();
void mostrarProductos();
void calcularEstadisticas();
void convertirMinusculas(char *str);
void pausa();

int main()
{
    int opcion;
    char buffer[100];

    do
    {
        system("cls"); // Limpia la pantalla (Windows)
        printf("===== SISTEMA DE GESTION DE INVENTARIO =====\n");
        printf("1. Agregar nuevo producto\n");
        printf("2. Buscar producto\n");
        printf("3. Actualizar stock\n");
        printf("4. Mostrar todos los productos\n");
        printf("5. Mostrar estadisticas\n");
        printf("6. Salir\n");

        printf("\nSelecciona una opcion: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (sscanf(buffer, "%d", &opcion) != 1)
            {
                printf("Entrada invalida. Por favor ingresa un numero.\n");
                pausa();
                continue;
            }
        }
        else
        {
            printf("Error al leer la entrada.\n");
            pausa();
            continue;
        }

        switch (opcion)
        {
        case 1:
            agregarProducto();
            break;
        case 2:
            buscarProducto();
            break;
        case 3:
            actualizarStock();
            break;
        case 4:
            mostrarProductos();
            break;
        case 5:
            calcularEstadisticas();
            break;
        case 6:
            printf("\nGracias por utilizar el sistema. Nos vemos!\n");
            break;
        default:
            printf("\nOpcion invalida. Intenta nuevamente.\n");
            pausa();
        }

    } while (opcion != 6);

    return 0;
}

// Función para agregar un nuevo producto
void agregarProducto()
{
    system("cls");
    printf("===== AGREGAR NUEVO PRODUCTO =====\n\n");

    if (totalProductos >= MAX_PRODUCTOS)
    {
        printf("Error: El inventario esta lleno. No se pueden agregar mas productos.\n");
        pausa();
        return;
    }

    char buffer[100];

    // Obtener nombre del producto
    printf("Ingresa el nombre del producto: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(nombres[totalProductos], buffer, MAX_NOMBRE - 1);
    }
    else
    {
        printf("Error al leer el nombre.\n");
        pausa();
        return;
    }

    // Obtener código del producto
    int codigo, existe;
    do
    {
        printf("Ingresa el codigo del producto (1-9999): ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (sscanf(buffer, "%d", &codigo) != 1)
            {
                printf("Por favor ingresa un valor numerico.\n");
                continue;
            }

            if (codigo < 1 || codigo > 9999)
            {
                printf("El codigo debe estar entre 1 y 9999.\n");
                continue;
            }

            // Verificar que el código no exista ya
            existe = 0;
            for (int i = 0; i < totalProductos; i++)
            {
                if (codigos[i] == codigo)
                {
                    existe = 1;
                    break;
                }
            }

            if (existe)
            {
                printf("Error: Ya existe un producto con ese codigo.\n");
            }
            else
            {
                break;
            }
        }
        else
        {
            printf("Error al leer la entrada.\n");
        }
    } while (1);

    codigos[totalProductos] = codigo;

    // Obtener precio del producto
    float precio;
    do
    {
        printf("Ingresa el precio del producto: $");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (sscanf(buffer, "%f", &precio) != 1)
            {
                printf("Por favor ingresa un valor numerico.\n");
                continue;
            }

            if (precio <= 0)
            {
                printf("El precio debe ser mayor a cero.\n");
                continue;
            }

            break;
        }
        else
        {
            printf("Error al leer la entrada.\n");
        }
    } while (1);

    precios[totalProductos] = precio;

    // Obtener stock inicial
    int cantidad;
    do
    {
        printf("Ingresa el stock inicial: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (sscanf(buffer, "%d", &cantidad) != 1)
            {
                printf("Por favor ingresa un valor numerico.\n");
                continue;
            }

            if (cantidad < 0)
            {
                printf("El stock no puede ser negativo.\n");
                continue;
            }

            break;
        }
        else
        {
            printf("Error al leer la entrada.\n");
        }
    } while (1);

    stock[totalProductos] = cantidad;
    totalProductos++;
    printf("\nProducto agregado exitosamente!\n");
    pausa();
}

// Función para buscar productos (submenú)
void buscarProducto()
{
    system("cls");
    printf("===== BUSCAR PRODUCTO =====\n\n");
    printf("1. Buscar por nombre\n");
    printf("2. Buscar por codigo\n");
    printf("3. Volver al menu principal\n");

    int opcion;
    char buffer[100];
    printf("\nSelecciona una opcion: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        if (sscanf(buffer, "%d", &opcion) != 1)
        {
            printf("Error al leer la entrada.\n");
            pausa();
            return;
        }
    }

    switch (opcion)
    {
    case 1:
        buscarPorNombre();
        break;
    case 2:
        buscarPorCodigo();
        break;
    case 3:
        return;
    default:
        printf("\nOpcion invalida.\n");
        pausa();
    }
}

// Función para buscar productos por nombre
void buscarPorNombre()
{
    system("cls");
    printf("===== BUSCAR POR NOMBRE =====\n\n");

    if (totalProductos == 0)
    {
        printf("No hay productos registrados en el inventario.\n");
        pausa();
        return;
    }

    char busqueda[MAX_NOMBRE];
    char buffer[100];

    printf("Ingresa el nombre a buscar: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(busqueda, buffer, MAX_NOMBRE - 1);
        busqueda[MAX_NOMBRE - 1] = '\0';
    }
    else
    {
        printf("Error al leer la busqueda.\n");
        pausa();
        return;
    }

    // Convertir búsqueda a minúsculas para comparación
    char busquedaMin[MAX_NOMBRE];
    strcpy(busquedaMin, busqueda);
    convertirMinusculas(busquedaMin);

    int encontrados = 0;
    printf("\n----- RESULTADOS DE LA BUSQUEDA -----\n\n");

    for (int i = 0; i < totalProductos; i++)
    {

        if (strstr(nombres[i], busquedaMin) != NULL)
        {
            printf("Producto #%d\n", i + 1);
            printf("Nombre: %s\n", nombres[i]);
            printf("Codigo: %d\n", codigos[i]);
            printf("Precio: $%.2f\n", precios[i]);
            printf("Stock: %d unidades\n\n", stock[i]);
            encontrados++;
        }
    }

    if (encontrados == 0)
    {
        printf("No se encontraron productos con ese nombre.\n");
    }

    pausa();
}

// Función para buscar productos por código
void buscarPorCodigo()
{
    system("cls");
    printf("===== BUSCAR POR CODIGO =====\n\n");

    if (totalProductos == 0)
    {
        printf("No hay productos registrados en el inventario.\n");
        pausa();
        return;
    }

    int codigo;
    char buffer[100];

    printf("Ingresa el codigo a buscar: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        if (sscanf(buffer, "%d", &codigo) != 1)
        {
            printf("Por favor ingresa un valor numerico valido.\n");
            pausa();
            return;
        }
    }
    else
    {
        printf("Error al leer la entrada.\n");
        pausa();
        return;
    }

    for (int i = 0; i < totalProductos; i++)
    {
        if (codigos[i] == codigo)
        {
            printf("\n----- PRODUCTO ENCONTRADO -----\n\n");
            printf("Nombre: %s\n", nombres[i]);
            printf("Codigo: %d\n", codigos[i]);
            printf("Precio: $%.2f\n", precios[i]);
            printf("Stock: %d unidades\n", stock[i]);
            break;
        }
    }
    printf("\nNo se encontro ningun producto con el codigo %d.\n", codigo);
    pausa();
}

// Función para actualizar el stock de un producto
void actualizarStock()
{
    system("cls");
    printf("===== ACTUALIZAR STOCK =====\n\n");

    if (totalProductos == 0)
    {
        printf("No hay productos registrados en el inventario.\n");
        pausa();
        return;
    }

    // Mostrar lista de productos
    printf("LISTA DE PRODUCTOS:\n");
    for (int i = 0; i < totalProductos; i++)
    {
        printf("%d. %s (Codigo: %d) - Stock actual: %d\n",
               i + 1, nombres[i], codigos[i], stock[i]);
    }

    // Seleccionar producto
    int seleccion;
    char buffer[100];
    printf("\nSelecciona el numero de producto a actualizar (1-%d): ", totalProductos);
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        if (sscanf(buffer, "%d", &seleccion) != 1 || seleccion < 1 || seleccion > totalProductos)
        {
            printf("Seleccion invalida.\n");
            pausa();
            return;
        }
    }
    else
    {
        printf("Error al leer la entrada.\n");
        pausa();
        return;
    }

    int indice = seleccion - 1;

    // Obtener la cantidad a modificar
    int cantidad;
    printf("\nStock actual de '%s': %d unidades\n", nombres[indice], stock[indice]);
    printf("Ingresa la nueva cantidad en stock: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        if (sscanf(buffer, "%d", &cantidad) != 1)
        {
            printf("Por favor ingresa un valor numerico.\n");
            pausa();
            return;
        }

        if (cantidad < 0)
        {
            printf("El stock no puede ser negativo.\n");
            pausa();
            return;
        }
    }
    else
    {
        printf("Error al leer la entrada.\n");
        pausa();
        return;
    }

    // Actualizar stock
    stock[indice] = cantidad;
    printf("\nStock actualizado exitosamente!\n");
    pausa();
}

// Función para mostrar todos los productos
void mostrarProductos()
{
    system("cls");
    printf("===== LISTADO DE PRODUCTOS =====\n\n");

    if (totalProductos == 0)
    {
        printf("No hay productos registrados en el inventario.\n");
        pausa();
        return;
    }

    float valorTotalInventario = 0;

    for (int i = 0; i < totalProductos; i++)
    {
        printf("Producto #%d\n", i + 1);
        printf("Nombre: %s\n", nombres[i]);
        printf("Codigo: %d\n", codigos[i]);
        printf("Precio: $%.2f\n", precios[i]);
        printf("Stock: %d unidades\n", stock[i]);
        printf("Valor en inventario: $%.2f\n", precios[i] * stock[i]);
        printf("-----------------------------\n");

        valorTotalInventario += precios[i] * stock[i];
    }

    printf("\nValor total del inventario: $%.2f\n", valorTotalInventario);

    pausa();
}

// Función para mostrar estadísticas del inventario
void calcularEstadisticas()
{
    system("cls");
    printf("===== ESTADISTICAS DE INVENTARIO =====\n\n");

    if (totalProductos == 0)
    {
        printf("No hay productos registrados en el inventario.\n");
        pausa();
        return;
    }

    // Calcular estadísticas
    float precioPromedio = 0;
    float valorTotalInventario = 0;
    int stockTotal = 0;
    float precioMax = precios[0];
    float precioMin = precios[0];
    int indiceMax = 0;
    int indiceMin = 0;
    int sinStock = 0;
    int stockBajo = 0; // Menos de 5 unidades

    for (int i = 0; i < totalProductos; i++)
    {
        precioPromedio += precios[i];
        valorTotalInventario += precios[i] * stock[i];
        stockTotal += stock[i];

        if (precios[i] > precioMax)
        {
            precioMax = precios[i];
            indiceMax = i;
        }

        if (precios[i] < precioMin)
        {
            precioMin = precios[i];
            indiceMin = i;
        }

        if (stock[i] == 0)
        {
            sinStock++;
        }
        else if (stock[i] < 5)
        {
            stockBajo++;
        }
    }

    precioPromedio /= totalProductos;

    // Mostrar estadísticas
    printf("Cantidad total de productos diferentes: %d\n", totalProductos);
    printf("Unidades totales en inventario: %d\n", stockTotal);
    printf("Precio promedio: $%.2f\n", precioPromedio);
    printf("Valor total del inventario: $%.2f\n\n", valorTotalInventario);

    printf("Producto más costoso: %s ($%.2f)\n", nombres[indiceMax], precios[indiceMax]);
    printf("Producto más económico: %s ($%.2f)\n\n", nombres[indiceMin], precios[indiceMin]);

    printf("Productos sin stock: %d (%.1f%%)\n",
           sinStock, (sinStock * 100.0) / totalProductos);
    printf("Productos con stock bajo (<5): %d (%.1f%%)\n",
           stockBajo, (stockBajo * 100.0) / totalProductos);

    pausa();
}

// Función para convertir una cadena a minúsculas
void convertirMinusculas(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

// Función para pausar la ejecución hasta que el usuario presione Enter
void pausa()
{
    printf("\nPresiona Enter para continuar...");
    getchar();
}
