#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"
#define CANTIDAD_PANTALLAS 5

int main()
{
    int opcionElegida;
    int posicionLibre;
    int posicionBuscada;
    Pantalla pantallas[CANTIDAD_PANTALLAS];
    pan_inicializar(pantallas, CANTIDAD_PANTALLAS);
    printf("Menu\n\n1-Agregar pantalla:\n2-Modificar pantalla\n3-Eliminar pantalla\n4-Mostrar pantallas\n5-Salir\n");
    do
    {
        printf("Seleccione opcion:");
        scanf("%d", &opcionElegida);
        __fpurge(stdin);
        if(opcionElegida==1)
        {
            posicionLibre=pan_encontrarLibre(pantallas, CANTIDAD_PANTALLAS);
            if(posicionLibre!=-1)
            {
                if(!pan_alta(pantallas, CANTIDAD_PANTALLAS,posicionLibre))
                {
                    pantallas[posicionLibre].idPantalla=posicionLibre;
                }
            }
            else
            {
                printf("No hay posicion libre");
            }
        }
        if(opcionElegida==2)
        {
            posicionBuscada=pan_modificar(pantallas, CANTIDAD_PANTALLAS);
            if(posicionBuscada!=-1)
            {
                pan_alta(pantallas, CANTIDAD_PANTALLAS, posicionBuscada);
            }
        }
        if(opcionElegida==3)
        {
            pan_eliminar(pantallas, CANTIDAD_PANTALLAS);
        }
        if(opcionElegida==4)
        {
            pan_mostrar(pantallas, CANTIDAD_PANTALLAS);
        }
    }while(opcionElegida!=5);
    return 0;
}
