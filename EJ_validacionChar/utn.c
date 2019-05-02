#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>

int getString ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo <= maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <maximo)
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


int isValidChar(letra,minimo,maximo)
{
    int retorno=1;
    if(letra>=minimo && letra<=maximo)
    {
        retorno=0;
    }
    return retorno;
}

int getChar(char *mensaje, char *mensajeError, int reintentos, char minimo, char maximo, char* resultado)
{
    char buffer[4096];
    char* bufferLetra;
    int i=0;
    int retorno=-1;
    if (mensaje!=NULL && mensajeError!=NULL && resultado!=NULL && reintentos>=0 && minimo<=maximo)
    {
        if(!getString(mensaje, mensajeError, 1, 2, reintentos, buffer))
        {
            strcpy(&bufferLetra, buffer);
            if(!isValidChar(bufferLetra, minimo, maximo))
            {
                strncpy(resultado, &bufferLetra, 1);
                retorno=0;
            }
        }

    }
    return retorno;
}

        /*for(i=0; i <=reintentos; i+=1)
        {
            printf("%s", mensaje);
            fgets(buffer, sizeof(buffer), stdin);
            scanf("%c",&buffer);
            __fpurge(stdin);
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
        }*/
