#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>
#define QTY_EMPLEADOS 10

int main()
{
    char auxName[500] = "test";

    char arrayNombres [QTY_EMPLEADOS][50];

    /*strncpy (arrayNombres[0],"JUAN",50);
    strncpy (arrayNombres[1],"ANA",50);
    strncpy (arrayNombres[2],"SOL",50);

    int i;
    for (i=0;i<QTY_EMPLEADOS; i++)
    {
        printf ("%s:",arrayNombres[i]);
    }*/

    int mostrar (char* nombre, char* maximo)
    {
       int i;
       for (i=0;i<maximo;i++)
       {
            printf ("%s:",nombre[i]);
       }
    }



    if(getName( "Nombre?: ",
                "Error",
                2,
                5,
                2,
                auxName) == 0)
    {
        printf("OK: %s",auxName);
    }
    else
    {
        printf("ER: %s",auxName);
    }
    return 0;
}







/*Hacer un programa con el siguiente menu:
   1) ingresar nuevo nombre (no acepta nombres repetidos)
   2) listar todo
   3) ordenar por nombre
   4) Borrar nombre. Se ingresa el nombre y si se encuentra se elimina de la lista

El programa permitira ingresar hasta 100 nombres.

4) Modificar el programa para que ademas del nombre se ingrese y guarde el DNI.*/
