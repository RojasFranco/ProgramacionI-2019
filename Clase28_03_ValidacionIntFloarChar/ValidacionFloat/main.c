#include <stdio.h>
#include <stdlib.h>

int getFloat(char *mensaje, char *mensajeError, float *resultado, float minimo, float maximo, int reintentos);
int isValidFloat(float numero, float minimo, float maximo);
int main()
{
    float numeroIngresado;
    getFloat("Ingrese un numero:", "Error", &numeroIngresado, 0.5, 10.5, 2);
    printf("El numero ingresado es: %f", numeroIngresado);
    return 0;
}

int isValidFloat(float numero, float minimo, float maximo)
{
    if (numero >= minimo && numero <= maximo)
    {
        return 1;
    }
    else
    {
        printf("el nro ing no es valido");
        return 0;
    }
}

int getFloat(char *mensaje, char *mensajeError, float *resultado, float minimo, float maximo, int reintentos)
{
    int retorno = -1;
    int i=0;
    float buffer;
    printf("%s", mensaje);
    scanf("%f", &buffer);
    if (mensaje!= NULL && mensajeError!= NULL && resultado!=NULL && minimo<=maximo && reintentos>=0)
    {
        for (i=0; i <= reintentos; i+=1)
        {
            if(isValidFloat(buffer, minimo, maximo))
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

