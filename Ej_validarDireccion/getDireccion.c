#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "getDireccion.h"

int getString ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {

        do
        {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>minimo && strlen(bufferStr) <maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }while(reintentos>=0);
    }
    return retorno;
}

int getDireccion(char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado)
{
    char buffer[4096];
    int retorno=-1;
    if(msg!=NULL && msgError!=NULL && resultado!=NULL && minimo<maximo && reintentos>=0)
    {
        if(!getString(msg, msgError, minimo, maximo, reintentos, buffer))
        {
            if(!isValidDireccion(buffer))
            {
                strncpy(resultado, buffer, maximo);
                retorno=0;
            }
        }
    }
    return retorno;
}

int isValidDireccion(char* resultado)
{
    int i;
    int retorno=0;
    for(i=0;resultado[i]!='\0';i++)
    {
        if( !(resultado[i]>='a'&&resultado[i]<='z' || resultado[i]<='Z'&&resultado[i]>='A' || resultado[i]>='0'&&resultado[i]<='9'|| resultado[i]==' ') )
        {
            retorno=-1;
            break;
        }

    }
    return retorno;
}
