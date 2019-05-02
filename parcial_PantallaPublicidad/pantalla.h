#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct
{
    int idPantalla;
    int isEmpty;
    char nombre[50];
    char direccion[50];
    int precio;
    char tipo;
}Pantalla;

int pan_inicializar(Pantalla* pantallas, int cantidad);
int pan_mostrar(Pantalla* pantallas, int cantidad);
int pan_encontrarLibre(Pantalla* pantallas, int cantidad);
int pan_alta(Pantalla* pantallas, int cantidad, int posicion);
int pan_modificar(Pantalla* pantallas, int cantidad);
int pan_eliminar(Pantalla* pantallas, int cantidad);

#endif // PANTALLA_H_INCLUDED
