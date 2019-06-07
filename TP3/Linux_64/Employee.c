#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/*static int idEmpleado=0;
static int employee_generarId(void)
{
    return idEmpleado++;
}

static void setIdMaximo(int valorId)
{
    idEmpleado = valorId;
}
*/
Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char*sueldoStr)
{
    Employee* pAuxEmpleado;
    Employee* retorno=NULL;
    pAuxEmpleado = employee_new();

    if(pAuxEmpleado!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
    {
        if( !employee_setId(pAuxEmpleado, atoi(idStr)) && atoi(idStr)>=0 &&
            !employee_setNombre(pAuxEmpleado, nombreStr)&&
            !employee_setHorasTrabajadas(pAuxEmpleado, atoi(horasTrabajadasStr)) && atoi(horasTrabajadasStr)>=0 &&
            !employee_setSueldo(pAuxEmpleado, atoi(sueldoStr)) && atoi(sueldoStr)>=0 )
        {
            retorno = pAuxEmpleado;
        }

        else
        {
            employee_delete(pAuxEmpleado);
        }
    }

    return retorno;
}

void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

int employee_setId(Employee* this,int id)
{

    int retorno=-1;
    if(this!=NULL && id>=0)
    {
        this->id = id;
        retorno=0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno=0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strncpy(nombre, this->nombre, sizeof(this->nombre));
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}


int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo>=0)
    {
        this->sueldo = sueldo;
        retorno=0;
    }
    return retorno;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo = this->sueldo;
        retorno=0;
    }
    return retorno;
}


int employee_compararPorNombre(void* thisUno, void* thisDos)
{
    int retorno;
    char auxStrA[4096];
    char auxStrB[4096];
    employee_getNombre((Employee*)thisUno, auxStrA);
    employee_getNombre((Employee*)thisDos, auxStrB);
    if(strcmp(auxStrA, auxStrB)>0)
    {
        retorno=1;
    }
    else if(strcmp(auxStrA, auxStrB)<0)
    {
        retorno = -1;
    }
    else
    {
        retorno=0;
    }


    return retorno;
}


//int employee_getIdMax()
