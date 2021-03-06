#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
//#include "Controller.h"
#include "Empleado.h"
#include "utn.h"


Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)//, char*sueldoStr)
{
    Employee* pAuxEmpleado;
    Employee* retorno=NULL;
    pAuxEmpleado = employee_new();

    if(pAuxEmpleado!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL)// && sueldoStr!=NULL)
    {
        if( isValidNumber(idStr) && !employee_setId(pAuxEmpleado, atoi(idStr)) &&
            !employee_setNombre(pAuxEmpleado, nombreStr)&&
            isValidNumber(horasTrabajadasStr) && !employee_setHorasTrabajadas(pAuxEmpleado, atoi(horasTrabajadasStr)))// &&
            //isValidNumber(sueldoStr) && !employee_setSueldo(pAuxEmpleado, atoi(sueldoStr)) )
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

Employee* employee_newParametrosBin(int id, char* nombreStr, int horasTrabajadas, int sueldo)
{
    Employee* pEmpleado;
    Employee* retorno=NULL;
    pEmpleado = employee_new();
    if(id>=0 && nombreStr!=NULL && horasTrabajadas>=0 && sueldo>=0 && pEmpleado!=NULL)
    {
        if( !employee_setId(pEmpleado, id) &&
            !employee_setNombre(pEmpleado, nombreStr) &&
            !employee_setHorasTrabajadas(pEmpleado, horasTrabajadas) &&
            !employee_setSueldo(pEmpleado, sueldo) )
        {
            retorno = pEmpleado;
        }
        else
        {
            employee_delete(pEmpleado);
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
    if(this!=NULL && isValidName(nombre))
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

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350*/
void em_calcularSueldo(void* p)
{
    //int retorno=-1;
    Employee* pEmpleado = (Employee*)p;
    int bufferHorasTrabajadas;
    int horasEntre120y160;
    int horasEntre160y240;
    int totalSueldo;
    if(p!=NULL)
    {
        employee_getHorasTrabajadas(pEmpleado, &bufferHorasTrabajadas);
        //retorno=0;
        if(bufferHorasTrabajadas<=120)
        {
            totalSueldo = bufferHorasTrabajadas*180;
        }
        else if(bufferHorasTrabajadas<=160)
        {
            horasEntre120y160 = bufferHorasTrabajadas-120;
            totalSueldo = horasEntre120y160*240 + 120*180;
        }
        else
        {
            horasEntre160y240 = bufferHorasTrabajadas - 160;
            totalSueldo = 120*180 + 40*240 + horasEntre160y240*350;
        }
        employee_setSueldo(pEmpleado, totalSueldo);;
    }
    //return retorno;
}
