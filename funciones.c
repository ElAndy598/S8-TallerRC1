#include <stdio.h>
#include <string.h>

struct info_prod {
    char nombre[65];
    int cantidad;
    float tiempo_fab;
};

void ingresar_datos(struct info_prod productos[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        fflush(stdin);
        printf("\nProducto %d\n", i + 1);

        printf("Ingrese el nombre del producto: ");
        fgets(productos[i].nombre, sizeof(productos[i].nombre), stdin);

        printf("Ingrese la cantidad del producto: ");
        scanf("%d", &productos[i].cantidad);
        while (productos[i].cantidad <= 0) {
            printf("Ingrese un valor mayor a 0: ");
            scanf("%d", &productos[i].cantidad);
        }

        printf("Ingrese el tiempo de produccion del producto en horas: ");
        scanf("%f", &productos[i].tiempo_fab);
        while (productos[i].tiempo_fab <= 0) {
            printf("Ingrese un valor mayor a 0: ");
            scanf("%f", &productos[i].tiempo_fab);
        }
        getchar();
    }
}

void calculo_prod_recursos(struct info_prod productos[], int cantidad_prod) {
    float tiempo_total_prod = 0.0;
    int recursos_total = 0;

    for (int i = 0; i < cantidad_prod; i++) {
        tiempo_total_prod += productos[i].tiempo_fab * productos[i].cantidad;
        recursos_total += productos[i].cantidad;
    }

    printf("Tiempo total requerido para fabricar los productos: %.2f horas\n", tiempo_total_prod);
    printf("Total de recursos requeridos: %d\n", recursos_total);

    float tiempo_disponible;
    int recursos_disponibles;
    printf("\nIngrese el tiempo total de produccion disponible (en horas): ");
    scanf("%f", &tiempo_disponible);
    printf("Ingrese la cantidad total de recursos disponibles: ");
    scanf("%d", &recursos_disponibles);

    if (tiempo_total_prod <= tiempo_disponible && recursos_total <= recursos_disponibles) {
        printf("\nExisten recursos y tiempo disponible para producir los productos.\n");
    } else {
        printf("\nNO existen recursos y tiempo suficiente para producir los productos. No se puede cumplir con la demanda.\n");
        if (tiempo_total_prod > tiempo_disponible)
            printf("Son necesarias %.2f horas mas.\n", tiempo_total_prod - tiempo_disponible);
        if (recursos_total > recursos_disponibles)
            printf("Son necesarios %d recursos mas.\n", recursos_total - recursos_disponibles);
    }
}

void editar_producto(struct info_prod productos[], int cantidad) {
    char nombre_busqueda[65];
    int encontrado = 0;
    
    printf("Ingrese el nombre del producto a editar: ");
    getchar(); 
    fgets(nombre_busqueda, sizeof(nombre_busqueda), stdin);

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(productos[i].nombre, nombre_busqueda) == 0) {
            encontrado = 1;
            printf("Producto encontrado. Ingrese los nuevos datos:\n");

            printf("Nuevo nombre: ");
            fgets(productos[i].nombre, sizeof(productos[i].nombre), stdin);

            printf("Nueva cantidad: ");
            scanf("%d", &productos[i].cantidad);

            printf("Nuevo tiempo de produccion: ");
            scanf("%f", &productos[i].tiempo_fab);

            printf("Producto actualizado correctamente.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void eliminar_producto(struct info_prod productos[], int *cantidad) {
    char nombre_busqueda[65];
    int encontrado = -1;

    printf("Ingrese el nombre del producto a eliminar: ");
    getchar();
    fgets(nombre_busqueda, sizeof(nombre_busqueda), stdin);

    for (int i = 0; i < *cantidad; i++) {
        if (strcmp(productos[i].nombre, nombre_busqueda) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        for (int i = encontrado; i < *cantidad - 1; i++) {
            productos[i] = productos[i + 1];
        }
        (*cantidad)--;
        printf("Producto eliminado correctamente.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}
