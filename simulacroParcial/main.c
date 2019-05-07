#include <stdio.h>
#include <stdlib.h>
#include "asociado.h"
#define CANTIDAD_ASOCIADOS 3

int main()
{

    Asociado asociados[CANTIDAD_ASOCIADOS];
    asoc_inicializar(asociados, CANTIDAD_ASOCIADOS);
    int opcionSeleccionada;
    int idBuscado;
    int posicionLibre;
    do
    {
        getIntInRange(&opcionSeleccionada, "Menu\n\n1-Alta asociado\n2-Modificar datos asociado\n3-Baja asociado"
                        "\n4-Mostrar datos\n5-Salir\nOpcion elegida:", "opcion invalida", 1, 5, 2);
        if (opcionSeleccionada==1)
        {
            posicionLibre=asoc_buscarLibre(asociados, CANTIDAD_ASOCIADOS);
            if(posicionLibre>=0)
            {
                printf("Se encontro posicion\n");
                asoc_alta(asociados, CANTIDAD_ASOCIADOS, posicionLibre);
                /// aaaaaaaalta
            }
            else
            {
                printf("No hay posicion libre");
            }
        }

        if(opcionSeleccionada==2)
        {
            idBuscado=asoc_buscarPorId(asociados, CANTIDAD_ASOCIADOS);
            if(idBuscado>=0)
            {
                ///modif
                asoc_modificar(asociados, CANTIDAD_ASOCIADOS, idBuscado);
            }
            else
            {
                printf("ID no se encuentra");
            }
        }

        if(opcionSeleccionada==3)
        {
            idBuscado=asoc_buscarPorId(asociados, CANTIDAD_ASOCIADOS);
            if(idBuscado>=0)
            {
                ///eliminar
                asoc_baja(asociados, CANTIDAD_ASOCIADOS, idBuscado);
                printf("ID eliminado exitosamente\n");

            }
            else
            {
                printf("ID no se encuentra\n");
            }


        }
        if(opcionSeleccionada==4)
        {
            asoc_mostrar(asociados, CANTIDAD_ASOCIADOS);
        }

    }while(opcionSeleccionada!=5);



    return 0;
}
/**********
Asociado:
-estado(en lugar de isempty)
-id
-nombre
-apellido
-edad
-dni

Llamada:
-Motivo
-idasociado
-idllamada
-estado
-tiempo
-idAmbulancia
Alta-Mod-Baja
***********/
