#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_AUTORES 4
#define CANTIDAD_LIBROS 5
#include "utn_strings.h"
#include "autores.h"

int main()
{
    printf("Hello world!\n");
    int opcionSeleccionada;
    int posicionLibre;
    int idBuscado;
    Autor autores[CANTIDAD_AUTORES];
//    Libro libros[CANTIDAD_LIBROS];
    autores_inicializar(autores, CANTIDAD_AUTORES);
    do
    {
        getIntInRange(&opcionSeleccionada, "\nMenu\n\n1-Alta autor\n2-Modificar autor\n3-Baja autor\n4-Mostrar autores\n5-Salir\nOpcion elegida:","opcion invalida\n", 1, 5, 2);
        switch(opcionSeleccionada)
        {
            case 1:
            {
                posicionLibre=autores_encontrarLibre(autores, CANTIDAD_AUTORES);
                if(posicionLibre>=0)
                {
                ///alta
                    if(!autores_alta(autores, posicionLibre))
                    {
                        printf("\nSe agrego autor correctamente\n");
                    }
                    else
                    {
                        printf("\nError al ingresar datos\n");
                    }

                }
                else
                {
                    printf("\nNo hay posicion vacia\n");
                }
                break;
            }

            case 2:
            {
                idBuscado = autores_getById(autores, CANTIDAD_AUTORES);
                printf("HOLAAAAAAA");
                if(idBuscado>=0)
                {
                    autores_modificar(autores, idBuscado);
                }
                break;
            }
            case 3:
            {
                idBuscado=autores_getById(autores, CANTIDAD_AUTORES);
                if(idBuscado>=0)
                {
                    autores_baja(autores, idBuscado);
                }
                break;

            }

            case 4:
            {
                autores_mostrarAutores(autores, CANTIDAD_AUTORES);
                break;
            }

        }

    }while(opcionSeleccionada!=5);


    return 0;
}
