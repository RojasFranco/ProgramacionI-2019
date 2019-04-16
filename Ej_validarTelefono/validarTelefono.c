#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validarTelefono.h"

int getTelefono(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, int* resultado)
{
    char bufferInt[20];
    int retorno=-1;
    if(mensaje!=NULL && mensajeError!=NULL && resultado!=NULL && minimo<=maximo && reintentos>=0)
    {
        if(!getString(mensaje, mensajeError, minimo, maximo, reintentos, bufferInt))
        {
            if (!esValidoTelefono(bufferInt))
            {
                ///strncpy(resultado, bufferInt, sizeof(bufferInt));
                *resultado=atoi(bufferInt);
                retorno=0;
            }
        }
    }
    return retorno;
}


int esValidoTelefono(char* cadena)
{
    int i;
    int retorno=0;
    for (i=0; i<strlen(cadena); i++)
    {
        if(!(cadena[i]>='0' && cadena[i]<='9'))
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}
