#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_ALUMNOS 5

    /*
    Clase

    int* pEdades;
    int aEdades[CANTIDAD_ALUMNOS]; // El puntero y el array tienen que ser del mismo tipo (xq luego se mueve por bytes)
    float aPesos[CANTIDAD_ALUMNOS];
    char aLetraNombre[CANTIDAD_ALUMNOS];

    aEdades[100]=22;
    bufferEdad= aEdades[10];

    pEdades = &aEdades[0]; //pEdades=aEdades(aEdades==1er pos del array - Paso al puntero edades , la 1er posicion del array
    pEdades[88]=11;
    *(pEdades+88) = 11; //Igual al de arriba. Al puntero le sumo 88 posiciones y ahi escribo el 11.
    bufferEdad = *(pEdades+188); // guardo lo que este en esa posicion (0+188)
    */

int main()
{
    int aEdades[CANTIDAD_ALUMNOS];
    getArrayInt("ingrese edad:", "Edad invalida", 100, 0, 3, aEdades, CANTIDAD_ALUMNOS);
    printArrayInt(aEdades, CANTIDAD_ALUMNOS);
    return 0;
}

int getArrayInt(char* msg, char* msjErr, int maximo, int minimo, int reintentos, int* arrayResultado, int limite)
    /* limite es para poner el limite al array-int* arrayResultado crea un puntero a la 1er posicion del array*/
{
    int retorno=-1;
    int i=0;
    int buffer;
    if(msg != NULL && msjErr != NULL && arrayResultado!= NULL, reintentos>=0 && maximo>=minimo, limite>0)
    {
        retorno=0;
        for(i=0; i<limite ;i++)
        {
            if (getInt(msg, msjErr, minimo, maximo, reintentos, &buffer)==0 )
            {
                arrayResultado[i]=buffer;
            }
            else
            {
                retorno=-1;
                break;
            }
        }

    }
    return retorno;
}

void printArrayInt(int* arrayResultado, int limite)
{
    int i;
    for(i=0; i<limite; i++)
    {
        printf("%d\n", arrayResultado[i]);
    }
}

