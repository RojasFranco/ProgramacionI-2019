#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#define MAX_NOMBRE 20
#define MAX_HS 200
#define MAX_SUELDO 30000


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    ///llama a funcion parse y cargar el archivo.-
    int retorno=-1;
    FILE* pFile=NULL;
    pFile = fopen(path, "r");
    if(path!=NULL && pArrayListEmployee!=NULL && pFile!=NULL)
    {
        parser_EmployeeFromText(pFile, pArrayListEmployee);
        retorno=0;
        fclose(pFile);
    }
    //ll_sort(pArrayListEmployee, employee_compararPorNombre, 0);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    /*
    Employee auxEmp; es aux, no puntero
    Employee* pEmpleado;
    if(path!=NULL parray!=NULL)
    {
        pFile = fopen("data.bin", "r");
        if(pFile!=NULL)
        {

            hasta pfile lo mismo (sin parser - obs: en pfile = open("data.bin",r)

            while(!feof(pFile))
            {    fread(&auxEmp, sizeof(Emp), 1 , pFile;
                (probamos printf("%s \n", auxEmp.nombre)
                 pEmp = employee_new();
                 if(!employee_setId(pEmp,auxEmp.id) &&
                    !emplyee_setNombre(pEmpleado, auxEmpleado.nombre) &&
                    !employee_setHs(pEmpleado, auxEmpleado.hsTrab) &&
                    !employee_setSueldo(pEmpleado, auxEmpleado.sueldo) )
                {
                        ll_add(pArrayList, pEmpleado)
                }
                else
                {
                    employee_delete(pEmpleado);
                }

            }



        }

    }



    */
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    char buffeNombre[MAX_NOMBRE];
    char bufferHorasTrabajadas[MAX_HS];
    char bufferSueldo[MAX_SUELDO];
    char id [2];
    Employee* auxEmpleado;
    /*auxEmpleado = employee_new();*/
    int reintentos;
    reintentos=2;
    if(pArrayListEmployee!=NULL)
    {
        if( !utn_getName("\nIngrese nombre:", "\nNombre invalido", 1,MAX_NOMBRE, reintentos, buffeNombre) &&
            !getString("\nIngrese hs trabajadas", "\nDato invalido", 1, sizeof(int), &reintentos, bufferHorasTrabajadas) &&
            !getString("\nIngrese sueldo", "dato invalido", 1, sizeof(float), &reintentos, bufferSueldo) )
        {
            auxEmpleado = employee_newParametros(id, buffeNombre, bufferHorasTrabajadas, bufferSueldo);
            if( auxEmpleado!= NULL)
            {
                ll_add(pArrayListEmployee, auxEmpleado);
            }
        }
        /*else
        {
            employee_delete(auxEmpleado);
        }*/
        retorno=0;
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    // hay que usar Emp* pAux = ll_get(this,indice) devuelve el empleado apuntado.-
    // tendria apuntado en el ll y este pAux apuntando al que hay que modificar - modifico los datos con set y listo.-



    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
    //primero delete, y luego lo saco de la lista.-
    // funcion pop lo saca de la lista y lo devuelve, luego deberia usar delete y listo.-
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {


    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    //int Empl *pEmp = NULL;
    //lo mismo de load pero con 'w' hasta if(pFile!=NULL)
    /* luego
    for(i=0;i<ll_len(parrayList);i++)
    {
        pEmp = ll_get(parray,i); (puedo hacer print(%s, pEmp->nombre para ver
        fwrite(pEmp, sizeof(Employee), 1, pFile)
    }
    retorno=0;
    return retorno;*/
    return 1;
}

