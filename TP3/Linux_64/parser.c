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
                }
            }
        } while(!feof(pFile));

        fclose(pFile);
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
