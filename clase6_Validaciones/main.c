#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getString(char* mensaje, char* Error,int minimo, int maximo, int reintentos, char* resultado);
int utn_isValidNumber(char *str);
int utn_getNumber(char* mensaje, char* Error,int minimo, int maximo, int reintentos, int resultado);

int main()
{

    return 0;
}

int utn_getNumber(char* mensaje, char* Error,int minimo, int maximo, int reintentos, int resultado)
{
    int retorno=-1;
    char buffer[18]; /// podria pasar 16 (la misma cantidad
    int bufferInt;
    if (mensaje!=NULL && error!=NULL && maximo>minimo)
    {
        if(utn_getString(mensaje, error, 1, 16 , reintentos, buffer))==0)
        {
            if(utn_isValidNumber(buffer))
            {
                bufferInt= atoi(buffer); /// convierte el string a int
                if(bufferInt >= minimo && bufferInt <= maximo)
                {
                    *resultado=bufferInt;
                    retorno=0;
                }
            }
        }
    }

    return retorno;
}

int utn_isValidNumber(char *str)
{
    return 1;
}

int utn_getString(char* mensaje, char* Error,int minimo, int maximo, int reintentos, char* resultado)
{
    strncpy(resultado, "1234", 5);
    return 0;
}
