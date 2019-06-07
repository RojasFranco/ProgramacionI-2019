#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    char auxPrimerLinea[512];
    char auxNombre[512];
    char auxHorasTrabajadas[512];
    char auxSueldo[512];
    char auxId[512];
    int cantidadDatosLeidos;
    int idMaximo=0;
    Employee* auxEmpleado;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        fscanf(pFile, "%[^\n]\n", auxPrimerLinea);
        do
        {
            cantidadDatosLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            if(cantidadDatosLeidos == 4)
            {
                auxEmpleado = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
                if(auxEmpleado!=NULL)
                {
                    ll_add(pArrayListEmployee, auxEmpleado);
                    if(atoi(auxId)>idMaximo)
                    {
                        idMaximo = atoi(auxId);
                    }
                }
                //printf("\n %s", auxEmpleado->nombre);
            }
        } while(!feof(pFile));
        printf("\n ASDASD:%d \n", idMaximo);
        //setIdMaximo(idMaximo);
    }


    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
///necesito primero generarlo (lo que se hace en parser texto) - Leer apunte
    return 1;
}
