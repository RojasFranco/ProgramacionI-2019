#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"

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

int getName (   char* msg,
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
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidName(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidName (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a')  )
        {
            retorno = FALSE;
            break;
        }
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

int getNumero(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, int* resultado)
{
    char bufferInt[20];
    int retorno=-1;
    if(mensaje!=NULL && mensajeError!=NULL && resultado!=NULL && minimo<=maximo && reintentos>=0)
    {
        if(!getString(mensaje, mensajeError, minimo, maximo, reintentos, bufferInt))
        {
            if(!esValidoNumero(bufferInt))
            {
                *resultado=atoi(bufferInt);
                retorno=0;
            }
        }
    }
    return retorno;
}


int esValidoNumero(char* cadena)
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

int isValidChar(letra,minimo,maximo)
{
    int retorno=-1;
    if(letra>=minimo && letra<=maximo)
    {
        retorno=0;
    }
    return retorno;
}

int getChar(char *mensaje, char *mensajeError, int reintentos, int minimo, int maximo, char* resultado)
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
