#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_AUTORES 4
#include "utn_strings.h"
#include "autores.h"

int autores_inicializar(Autor* autores, int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        autores[i].isEmpty=1;
        autores[i].idAutor=-1;
    }
    return 0;
}

int autores_encontrarLibre(Autor* autores, int len)
{
    int i;
    int retorno=-1;
    for(i=0; i<len; i++)
    {
        if(autores[i].isEmpty==1)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int autores_alta(Autor* autores, int posicion)
{
    int retorno=-1;
    if(!getStringLetras(autores[posicion].nombre, "Ingrese su nombre: ", "nombre invalido\n", 2))
    {
        if(!getStringLetras(autores[posicion].apellido, "Ingrese su apellido: ", "apellido invalido\n",2))
        {
            autores[posicion].isEmpty=0;
            autores[posicion].idAutor=autores_generarId();
            retorno=0;
        }
    }
    return retorno;
}

int autores_mostrarAutores(Autor* autores, int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(autores[i].isEmpty==0)
        {
            printf("\nNombre: %s\n", autores[i].nombre);
            printf("Apellido: %s\n", autores[i].apellido);
            printf("ID Autor: %d\n", autores[i].idAutor);
        }

    }
    return 0;
}


int autores_getById(Autor* autores, int len)
{
    char bufferId[10];
    int idBuscado;
    int i;
    int retorno=-1;
    if(getStringNumeros(bufferId, "Ingrese ID buscado:", "ID invalido \n", 2)==0)
    {
        idBuscado=atoi(bufferId);
        //retorno=-1;
        printf("\n\nRETORNO: %d\n\n", retorno);
        for(i=0; i<len; i++)
        {
            if(autores[i].idAutor==idBuscado)
            {
                retorno=i;
                break;
            }
        }
//        printf("\n\nRETORNO: %d\n\n", retorno);
        printf("ID no encontrado\n");
    }
    /*else
    {
        retorno=-1;
    }*/
    //printf("\n\nRETORNO: %d\n\n", retorno);
    return retorno;
}

int autores_modificar(Autor* autores, int posicionID)
{
   int opcionSeleccionada;
   int retorno=-1;

    getIntInRange(&opcionSeleccionada, "\nOpciones\n1-Modificar Nombre\n2-Modificar Apellido\n3-Salir\nopcion:", "opcion invalida\n",1,3,2);
    switch(opcionSeleccionada)
    {
        case 1:
        {
            if(!getStringLetras(autores[posicionID].nombre,"Ingrese nuevo nombre: ", "nombre invalido\n", 2))
            {
                printf("Nombre modificado\n");
            }
            break;
        }
        case 2:
        {
            if(!getStringLetras(autores[posicionID].apellido,"Ingrese nuevo apellido:", "apellido invalido\n", 2))
            {
                printf("Apellido modificado\n");
            }
            break;
        }
    }

}

int autores_baja(Autor* autores, int posicionEliminar)
{
    autores[posicionEliminar].isEmpty=1;
    return 0;
}

static int autores_generarId(void)
{
    static int primerId=0;
    return primerId++;
}
