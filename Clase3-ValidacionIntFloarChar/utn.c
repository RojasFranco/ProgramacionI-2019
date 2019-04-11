#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int isValidInt(int numero, int minimo, int maximo)
{
    if (numero<=maximo && numero>=minimo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int getInt(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, int *resultado)
{
    int buffer; // aca guardo lo que ingresa user
    int i=0;
    int retorno=-1;
    printf("%s", mensaje);
    scanf("%d", &buffer);
    if(mensaje != NULL && mensajeError != NULL && resultado!= NULL && reintentos>=0 && maximo>=minimo)
    {
        for (i=0; i <= reintentos; i+=1)
        {
            if(isValidInt(buffer, minimo, maximo))
            {
                *resultado=buffer;
                retorno = 0;
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

