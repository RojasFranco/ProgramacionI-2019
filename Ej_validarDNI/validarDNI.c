#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validarDNI.h"

int getDNI(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, int* resultado)
{
    char bufferStr[14];
    int retorno=-1;
    if(mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0 && resultado!=NULL)
    {
        if (!getString(mensaje, mensajeError, 7, 10, reintentos, bufferStr))
        {
            if (!esValidoDNI(bufferStr))
            {
                *resultado = atoi(bufferStr);
                retorno=0;
            }
        }
    }
    return retorno;
}



int esValidoDNI(char* cadena)
{
    int i;
    int retorno=0;
    for (i=0; cadena[i]!='\0'; i++)
    {
        if(!(cadena[i]>='0' && cadena[i]<='9'))
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}
