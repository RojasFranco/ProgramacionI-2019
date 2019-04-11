#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int isValidChar(letra,minimo,maximo)
{
    if (letra >= minimo && letra <= maximo)
    {
        return 1;
    }
    return 0;
}

int getChar(char *mensaje, char *mensajeError, int reintentos, int minimo, int maximo, char *resultado)
{
    char buffer;
    int i=0;
    int retorno=-1;
    printf("%s", mensaje);
    scanf("%c",&buffer);
    if (mensaje!=NULL && mensajeError!=NULL && resultado!=NULL && reintentos>=0 && minimo<=maximo)
    {
        for(i=0; i <=reintentos; i+=1)
        {
            if(isValidChar(buffer, minimo, maximo))
            {
                *resultado=buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }

    }
    return retorno;
}
