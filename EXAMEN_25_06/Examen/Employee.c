#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Entrega.h"
#include "utn.h"


Entrega* entrega_new(void)
{
    return (Entrega*) malloc(sizeof(Entrega));
}

Entrega* entrega_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char*sueldoStr)
{
    Entrega* pAuxEmpleado;
    Entrega* retorno=NULL;
    pAuxEmpleado = entrega_new();

    if(pAuxEmpleado!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
    {
        if( isValidNumber(idStr) && !entrega_setId(pAuxEmpleado, atoi(idStr)) &&
            !entrega_setNombre(pAuxEmpleado, nombreStr)&&
            isValidNumber(horasTrabajadasStr) && !entrega_setHorasTrabajadas(pAuxEmpleado, atoi(horasTrabajadasStr)) &&
            isValidNumber(sueldoStr) && !entrega_setSueldo(pAuxEmpleado, atoi(sueldoStr)) )
        {
            retorno = pAuxEmpleado;
        }

        else
        {
            entrega_delete(pAuxEmpleado);
        }
    }

    return retorno;
}

Entrega* entrega_newParametrosBin(int id, char* nombreStr, int horasTrabajadas, int sueldo)
{
    Entrega* pEmpleado;
    Entrega* retorno=NULL;
    pEmpleado = entrega_new();
    if(id>=0 && nombreStr!=NULL && horasTrabajadas>=0 && sueldo>=0 && pEmpleado!=NULL)
    {
        if( !entrega_setId(pEmpleado, id) &&
            !entrega_setNombre(pEmpleado, nombreStr) &&
            !entrega_setHorasTrabajadas(pEmpleado, horasTrabajadas) &&
            !entrega_setSueldo(pEmpleado, sueldo) )
        {
            retorno = pEmpleado;
        }
        else
        {
            entrega_delete(pEmpleado);
        }
    }
    return retorno;
}

void entrega_delete(Entrega* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

int entrega_setId(Entrega* this,int id)
{

    int retorno=-1;
    if(this!=NULL && id>=0)
    {
        this->id = id;
        retorno=0;
    }
    return retorno;
}

int entrega_getId(Entrega* this,int* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}

int entrega_setNombre(Entrega* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && isValidName(nombre))
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno=0;
    }
    return retorno;
}

int entrega_getNombre(Entrega* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strncpy(nombre, this->nombre, sizeof(this->nombre));
        retorno=0;
    }
    return retorno;
}

int entrega_setHorasTrabajadas(Entrega* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int entrega_getHorasTrabajadas(Entrega* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}


int entrega_setSueldo(Entrega* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo>=0)
    {
        this->sueldo = sueldo;
        retorno=0;
    }
    return retorno;
}


int entrega_getSueldo(Entrega* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo = this->sueldo;
        retorno=0;
    }
    return retorno;
}


int entrega_compararPorNombre(void* thisUno, void* thisDos)
{
    int retorno;
    char auxStrA[4096];
    char auxStrB[4096];
    entrega_getNombre((Entrega*)thisUno, auxStrA);
    entrega_getNombre((Entrega*)thisDos, auxStrB);
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

//int entrega_getIdMax()
