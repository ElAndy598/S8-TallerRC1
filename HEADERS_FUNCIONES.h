struct info_prod {
    char nombre[65];
    int cantidad;
    float tiempo_fab;
};

void ingresar_datos(struct info_prod productos[], int cantidad);
void calculo_prod_recursos(struct info_prod productos[], int cantidad);
void editar_producto(struct info_prod productos[], int cantidad);
void eliminar_producto(struct info_prod productos[], int *cantidad);
