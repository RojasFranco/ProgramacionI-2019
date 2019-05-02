#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Empleado.h"

//int emp_initArray(Empleado array[], int limite)
int emp_initArray(Empleado* array, int limite)
{
    int i;
    for(i=0 ; i<limite; i++)
    {
        array[i].isEmpty=1;
        //strcpy(array[i].nombre,"1as");
        printf("%d", array[i].isEmpty);
    }
    return 0;
}

/*
int emp_lugarLibreArray(Empleado array[], int limite, int* indice)
{
    int i;
    for(i=0; i<limite; i++)
    {
        if(array[i])
    }
}
*/
