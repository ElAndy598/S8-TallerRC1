#include <stdio.h>
#include "HEADERS_FUNCIONES.h"

int main() {
    struct info_prod productos[5];
    int max_productos = 5;
    int opc;
    
    do {
        printf("BIENVENIDO AL SISTEMA DE LA FABRICA\n");
        printf("MENU\n");
        printf("1. Ingresar datos de los productos\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Calcular produccion (tiempo y recursos)\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                ingresar_datos(productos, max_productos);
                break;
            case 2:
                editar_producto(productos, max_productos);
                break;
            case 3:
                eliminar_producto(productos, &max_productos);
                break;
            case 4:
                calculo_prod_recursos(productos, max_productos);
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Usted ha ingresado una opcion no valida\n");
                break;
        }
    } while (opc != 5);
    
    return 0;
}

