#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 20
#define MAX_NOMBRE 15

char nombresProductos[MAX_PRODUCTOS][MAX_NOMBRE];
int tiemposProduccion[MAX_PRODUCTOS];
int recursosRequeridos[MAX_PRODUCTOS];
int demandasProductos[MAX_PRODUCTOS];
int totalProductos = 0;

void agregarProducto();
void editarProducto();
void eliminarProducto();
void calcularProduccion();
void listarProductos();

int main() {
    int op;

    printf("Optimización de Producción en Fábrica\n");
    
    do {
        printf("Menú de Opciones:\n");
        printf("1. Agregar Producto\n");
        printf("2. Editar Producto\n");
        printf("3. Eliminar Producto\n");
        printf("4. Calcular Producción\n");
        printf("5. Listar Productos\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                agregarProducto();
                break;
            case 2:
                editarProducto();
                break;
            case 3:
                eliminarProducto();
                break;
            case 4:
                calcularProduccion();
                break;
            case 5:
                listarProductos();
                break;
            case 6:
                printf("Saliendo\n");
                break;
            default:
                printf("Intente nuevamente.\n");
        }
    } while (op != 6);

    return 0;
}

void agregarProducto() {
    if (totalProductos >= MAX_PRODUCTOS) {
        printf("Error: No se pueden agregar más productos.\n");
        return;
    }

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombresProductos[totalProductos]);

    printf("Ingrese el tiempo de fabricación del producto: ");
    scanf("%d", &tiemposProduccion[totalProductos]);

    printf("Ingrese los recursos necesarios para el producto: ");
    scanf("%d", &recursosRequeridos[totalProductos]);

    printf("Ingrese la cantidad demandada del producto: ");
    scanf("%d", &demandasProductos[totalProductos]);

    totalProductos++;
    printf("Producto agregado exitosamente.\n");
}

void editarProducto() {
    char nombre[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", nombre);

    for (int i = 0; i < totalProductos; i++) {
        if (strcmp(nombresProductos[i], nombre) == 0) {
            printf("Producto encontrado. Ingrese los nuevos valores.\n");

            printf("Nuevo tiempo de fabricación: ");
            scanf("%d", &tiemposProduccion[i]);

            printf("Nuevos recursos necesarios: ");
            scanf("%d", &recursosRequeridos[i]);

            printf("Nueva cantidad demandada: ");
            scanf("%d", &demandasProductos[i]);

            printf("Producto editado exitosamente.\n");
            return;
        }
    }

    printf("Error: Producto no encontrado.\n");
}

void eliminarProducto() {
    char nombre[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", nombre);

    for (int i = 0; i < totalProductos; i++) {
        if (strcmp(nombresProductos[i], nombre) == 0) {
            for (int j = i; j < totalProductos - 1; j++) {
                strcpy(nombresProductos[j], nombresProductos[j + 1]);
                tiemposProduccion[j] = tiemposProduccion[j + 1];
                recursosRequeridos[j] = recursosRequeridos[j + 1];
                demandasProductos[j] = demandasProductos[j + 1];
            }
            totalProductos--;
            printf("Producto eliminado exitosamente.\n");
            return;
        }
    }

    printf("Error: Producto no encontrado.\n");
}

void calcularProduccion() {
    int tiempoTotal = 0, recursosTotales = 0;
    int tiempoDisponible, recursosDisponibles;

    printf("Ingrese el tiempo máximo de producción disponible (en minutos): ");
    scanf("%d", &tiempoDisponible);

    printf("Ingrese la cantidad máxima de recursos disponibles: ");
    scanf("%d", &recursosDisponibles);

    for (int i = 0; i < totalProductos; i++) {
        tiempoTotal += tiemposProduccion[i] * demandasProductos[i];
        recursosTotales += recursosRequeridos[i] * demandasProductos[i];
    }

    printf("\nCálculo de Producción:\n");
    printf("Tiempo total requerido: %d minutos\n", tiempoTotal);
    printf("Recursos totales requeridos: %d\n", recursosTotales);

    if (tiempoTotal <= tiempoDisponible && recursosTotales <= recursosDisponibles) {
        printf("La fábrica puede cumplir con la demanda.\n");
    } else {
        printf("La fábrica NO puede cumplir con la demanda.\n");
    }
}

void listarProductos() {
    printf("\nLista de Productos:\n");
    for (int i = 0; i < totalProductos; i++) {
        printf("Producto %d:\n", i + 1);
        printf("  Nombre: %s\n", nombresProductos[i]);
        printf("  Tiempo de fabricación: %d\n", tiemposProduccion[i]);
        printf("  Recursos necesarios: %d\n", recursosRequeridos[i]);
        printf("  Cantidad demandada: %d\n", demandasProductos[i]);
    }
}
