#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY_EMPLEADOS 10

int inicializarArray(char arrayStr[][50], int limite);
int printArray(char arrayStr[][50], int limite) ///no recibe puntero porque recibe una matriz de esta manera
{
    int i;
    for(i=0; i<limite ; i++)
    {
        printf("%s", arrayStr[i]);
    }
    return 0;
}

int main()
{
    ///char auxName[500] ="test";

    char arrayNombres[QTY_EMPLEADOS][50];
    inicializarArray(arrayNombres, QTY_EMPLEADOS);
    printArray(arrayNombres, QTY_EMPLEADOS);
    int opcionSeleccionada;
    ///int i;
    /*
    strncpy(arrayNombres[0], "JUAN0", 50);
    strncpy(arrayNombres[1], "JUAN1", 50);
    strncpy(arrayNombres[2], "JUAN2", 50);
    */
    do
    {
        printf("Seleccione opcion:\n1-Agregar\n2-Modificar\n3-Eliminar\n4-ordenar\n5-salir");
        scanf("%d",&opcionSeleccionada);
        if(opcionSeleccionada==1)
        {
            int posicion=encontrarPosicionVacia(arrayNombres, QTY_EMPLEADOS);
            if (posicion>=0)
            {
                escribirNombre(arrayNombres, posicion);
            }
            else
            {
                printf("no hay posicion vacia");
            }
        }
        if(opcionSeleccionada==2)
        {
            if(esNombreRepetido(char arrayStr[][50], int limite, char* nuevoNombre))
            {

            }
        }
        if(opcionSeleccionada==3)
        {
        }
        printArray(arrayNombres, QTY_EMPLEADOS);
    } while(opcionSeleccionada!=4);
    return 0;
}

int inicializarArray(char arrayStr[][50], int limite)
{
    int i;
    for(i=0; i<limite; i++)
    {
        strncpy(arrayStr[i],"\0", 50);
    }
    return 0;
}

int escribirNombre(char arrayStr[][50], int posicionLibre)
{
    char bufferStr[QTY_EMPLEADOS];
    getName("Ingrese nombre", "nombre invalido", 2, QTY_EMPLEADOS, 2 , bufferStr);
    strncpy(arrayStr[posicionLibre], bufferStr, 50);
}
///inicializo , creo vacio, luego escribo.
int encontrarPosicionVacia(char arrayStr[][50], int limite)
{
    int i;
    int retorno=-1;
    for(i=0; i<limite; i++)
    {
        if(!strcmp(arrayStr[i], "\0"))
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int esNombreRepetido(char arrayStr[][50], int limite, char* nuevoNombre)
{
    int i;
    int retorno=0;
    for(i=0; i<limite; i++)
    {
        if(strcmp(nuevoNombre, arrayStr[i]))
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}
