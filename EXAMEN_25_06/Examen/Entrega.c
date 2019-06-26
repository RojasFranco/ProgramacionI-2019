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

Entrega* entrega_newParametros(char* idStr,char* tipoStr,char* cantidadStr, char*importeStr)
{
    Entrega* pAuxEmpleado;
    Entrega* retorno=NULL;
    pAuxEmpleado = entrega_new();
    if(pAuxEmpleado!=NULL && idStr!=NULL && tipoStr!=NULL && cantidadStr!=NULL && importeStr!=NULL)
    {
        if( isValidNumber(idStr) && !entrega_setId(pAuxEmpleado, atoi(idStr)) &&
            !entrega_setTipo(pAuxEmpleado, tipoStr)&&
            isValidNumber(cantidadStr) && !entrega_setCantidad(pAuxEmpleado, atoi(cantidadStr)) &&
            isValidFloatNumber(importeStr) && !entrega_setImporte(pAuxEmpleado, atof(importeStr)) )
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

Entrega* entrega_newParametrosBin(int id, char* tipoStr, int cantidad, float importe)
{
    Entrega* pEmpleado;
    Entrega* retorno=NULL;
    pEmpleado = entrega_new();
    if(id>=0 && tipoStr!=NULL && cantidad>=0 && importe>=0 && pEmpleado!=NULL)
    {
        if( !entrega_setId(pEmpleado, id) &&
            !entrega_setTipo(pEmpleado, tipoStr) &&
            !entrega_setCantidad(pEmpleado, cantidad) &&
            !entrega_setImporte(pEmpleado, importe) )
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

int entrega_setTipo(Entrega* this,char* tipo)
{
    int retorno=-1;
    if(this!=NULL && isValidName(tipo))
    {
        strncpy(this->tipo, tipo, sizeof(this->tipo));
        retorno=0;
    }
    return retorno;
}

int entrega_getTipo(Entrega* this,char* tipo)
{
    int retorno=-1;
    if(this!=NULL && tipo!=NULL)
    {
        strncpy(tipo, this->tipo, sizeof(this->tipo));
        retorno=0;
    }
    return retorno;
}

int entrega_setCantidad(Entrega* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL && cantidad>=0)
    {
        this->cantidad = cantidad;
        retorno=0;
    }
    return retorno;
}

int entrega_getCantidad(Entrega* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL && cantidad!=NULL)
    {
        *cantidad = this->cantidad;
        retorno=0;
    }
    return retorno;
}


int entrega_setImporte(Entrega* this,float importe)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->importe = importe;
        retorno=0;
    }
    return retorno;
}


int entrega_getImporte(Entrega* this,float* importe)
{
    int retorno=-1;
    if(this!=NULL && importe!=NULL)
    {
        *importe = this->importe;
        retorno=0;
    }
    return retorno;
}


int entrega_compararPorTipo(void* thisUno, void* thisDos)
{
    int retorno;
    char auxStrA[4096];
    char auxStrB[4096];
    entrega_getTipo((Entrega*)thisUno, auxStrA);
    entrega_getTipo((Entrega*)thisDos, auxStrB);
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
