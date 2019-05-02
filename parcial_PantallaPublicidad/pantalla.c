#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pantalla.h"
#include <string.h>
#define CANTIDAD_PANTALLAS 5

int pan_inicializar(Pantalla* pantallas, int cantidad)
{
    int i;
    for(i=0; i< cantidad; i++)
    {
        pantallas[i].isEmpty=1;
    }
    return 0;
}

int pan_encontrarLibre(Pantalla* pantallas, int cantidad)
{
    int i;
    int retorno=-1;
    for(i=0; i<cantidad; i++)
    {
        if(pantallas[i].isEmpty==1)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int pan_alta(Pantalla* pantallas, int cantidad, int posicion)
{
    int retorno=-1;
    printf("pos libre:%d\n", posicion);
    if (getName("Ingresa tu nombre:", "nombre invalido\n", 2, 50, 2, pantallas[posicion].nombre)==0)
    {
        if (!getDireccion("Ingrese direccion:","direccion invalida", 4, 50, 2, pantallas[posicion].direccion))
        {
            if(!getNumero("Ingrese precio:", "precio invalido", 2, 20, 2, &pantallas[posicion].precio))
            {
                if(!getChar("Ingrese tipo:\nA-Pantalla LCD\nB-Pantalla LED\nTipo:", "tipo invalido", 2, 'A', 'B', &pantallas[posicion].tipo))
                {
                    pantallas[posicion].isEmpty=0;
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}

int pan_mostrar(Pantalla* pantallas, int cantidad)
{
     int i;
     for(i=0; i< cantidad; i++)
     {
         if (pantallas[i].isEmpty==0)
         {
            printf("Estado:%d\n ID:%d\nNombre:%s\nDireccion:%s\nPrecio:%d\nTipo:%c\n", pantallas[i].isEmpty, pantallas[i].idPantalla, pantallas[i].nombre, pantallas[i].direccion, pantallas[i].precio, pantallas[i].tipo);
         }
     }
     return 0;
}

int pan_modificar(Pantalla* pantallas, int cantidad)
{
    int* bufferID;
    int i;
    int retorno=-1;
    if(!getNumero("Ingrese ID a eliminar:", "ID invalido", 1, 20, 2, &bufferID))
    {
        for(i=0; i<cantidad;i++)
        {
            if(pantallas[i].idPantalla==bufferID)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int pan_eliminar(Pantalla* pantallas, int cantidad)
{
    int i;
    int bufferID;
    int retorno=-1;
    if(!getNumero("Ingrese ID a eliminar:", "ID invalido", 1, 20, 2, &bufferID))
    {
        for(i=0; i<cantidad; i++)
        {
            if(pantallas[i].idPantalla==bufferID)
            {
                pantallas[i].isEmpty=1;
                break;
            }
        }
    }
}
