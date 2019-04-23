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

int brindarMenu(void)
{
    char arrayNombres[QTY_EMPLEADOS][50];
    inicializarArray(arrayNombres, QTY_EMPLEADOS);
    printArray(arrayNombres, QTY_EMPLEADOS);
    char nuevoNombre[50];
    int posicionBuscada;
    int opcionSeleccionada;
    ///int i;
    /*
    strncpy(arrayNombres[0], "JUAN0", 50);
    strncpy(arrayNombres[1], "JUAN1", 50);
    strncpy(arrayNombres[2], "JUAN2", 50);
    */
    do
    {
        printf("\nMenu\n1-Agregar\n2-Modificar\n3-Eliminar\n4-ordenar\n5-salir\nSeleccione opcion:");
        scanf("%d",&opcionSeleccionada);
        __fpurge(stdin);
        if(opcionSeleccionada==1)
        {
            posicionBuscada=encontrarPosicionVacia(arrayNombres, QTY_EMPLEADOS);
            ///printf("%d", posicion);
            if (posicionBuscada>=0)
            {
                escribirNombre(arrayNombres, posicionBuscada);
            }
            else
            {
                printf("no hay posicion vacia\n");
            }
        }
        if(opcionSeleccionada==2)
        {
            posicionBuscada=esUnNombreYaIngresado(arrayNombres, QTY_EMPLEADOS);
            if(posicionBuscada>=0)
            {
                getName("Ingrese nuevo nombre:", "Nombre invalido", 2, 50, 2, nuevoNombre);
                strncpy(arrayNombres[posicionBuscada], nuevoNombre, 50);
            }
            else
            {
                printf("el nombre no se encuentra\n");
            }
        }
        if(opcionSeleccionada==3)
        {
            posicionBuscada=esUnNombreYaIngresado(arrayNombres, QTY_EMPLEADOS);
            if(posicionBuscada>=0)
            {
                strncpy(arrayNombres[posicionBuscada], "\0", 50);
            }
            else
            {
                printf("el nombre no se encuentra\n");
            }
        }
        if(opcionSeleccionada==4)
        {
            ordenarArray(arrayNombres, QTY_EMPLEADOS);
        }
        printArray(arrayNombres, QTY_EMPLEADOS);
    } while(opcionSeleccionada!=5);
    return 0;
}

int main()
{
    ///char auxName[500] ="test";
    brindarMenu();
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
    char bufferStr[50];
    int retorno=-1;
    if(!getName("Ingresa tu nombre:", "nombre invalido", 2, 50, 2, bufferStr))
    {
        ///printf("el nombre es: %s", bufferStr);
        strncpy(arrayStr[posicionLibre], bufferStr, 50);
        retorno=0;
    }
    else
    {
        printf("el nombre es incorrecto\n");
    }
    return retorno;
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

int esUnNombreYaIngresado(char arrayStr[][50], int limite)
{
    int i;
    int retorno=-1;
    char nuevoNombre[50];
    getName("Ingrese nombre a modificar:", "el nombre es invalido\n", 2 , 50, 2, nuevoNombre);
    for(i=0; i<limite; i++)
    {
        if(strcmp(nuevoNombre, arrayStr[i])==0)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int ordenarArray(char arrayNombres[][50], int limite)
{
    int i;
    char nombreAuxiliar[50];
    int flagSwap;
    do
    {
        for(i=0; i<limite-1; i++)
        {
            if(strcmp(arrayNombres[i],arrayNombres[i+1])>0)
            {
                strcpy(nombreAuxiliar, arrayNombres[i]);
                strcpy(arrayNombres[i], arrayNombres[i+1]);
                strcpy(arrayNombres[i+1], nombreAuxiliar);
                flagSwap=1;
            }
            else
            {
                flagSwap=0;
            }
        }
    }while(flagSwap);
}
