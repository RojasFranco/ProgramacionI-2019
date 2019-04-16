#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validarApellido.h"

int getApellido(char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos, char* resultado)
{
    char bufferStr[20];
    int retorno=-1;
    if (mensaje!=NULL && mensajeError!=NULL && resultado!=NULL && minimo<=maximo && reintentos >=0)
    {
        if (!getString(mensaje, mensajeError, minimo, maximo, reintentos, bufferStr))
        {

            if (!esValidoApellido(bufferStr))
            {
                strncpy(resultado, bufferStr, sizeof(bufferStr));
                retorno=0;
            }
        }
    }
    return retorno;
}

int esValidoApellido(char* resultado)
{
    int i;
    int retorno=0;
    for(i=0; i<strlen(resultado); i++)
    {
        if (!(resultado[i]>='a'&&resultado[i]<='z') && !(resultado[i]>='A' && resultado[i]<='Z'))
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}
