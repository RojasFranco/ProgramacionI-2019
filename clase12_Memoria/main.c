#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

int main()
{
    Empleado *pArrayEmpleado[1000];
    int ultimoElementoArrayEmpleado = 0;
    int indiceActual;
    int auxInt;
    float auxPeso;
    char auxNombre[50];
    int auxEstado;

    indiceActual = ultimoElementoArrayEmpleado;
    pArrayEmpleado[indiceActual] =  Emp_new();


    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("OK");
        if(!Emp_setId(pArrayEmpleado[indiceActual],14))
        {
            Emp_getId(pArrayEmpleado[indiceActual], &auxInt);
            printf("\nEl id es %d",auxInt);

        }

        if(!Emp_setPeso(pArrayEmpleado[indiceActual], 70.5))
        {
            Emp_getPeso(pArrayEmpleado[indiceActual], &auxPeso);
            printf("\nPeso: %.2f", auxPeso);
        }

        if(!Emp_setNombre(pArrayEmpleado[indiceActual], "pepe"))
        {
            Emp_getNombre(pArrayEmpleado[indiceActual], auxNombre);
            printf("\nNombre: %s", auxNombre);
        }

        if(!Emp_setEstado(pArrayEmpleado[indiceActual], 1))
        {
            Emp_getEstado(pArrayEmpleado[indiceActual], &auxEstado);
            printf("\nEstado: %d", auxEstado);

        }
    }
    Empleado auxEmp;
    Empleado *paraComparar;
    paraComparar = &auxEmp;
    strcpy(auxEmp.nombre,"zz");
    Emp_compararNombres(pArrayEmpleado[0], paraComparar);



    return 0;
}
