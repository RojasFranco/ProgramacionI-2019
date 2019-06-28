#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "ventas.h"
#include "utn.h"


Venta* venta_new(void)
{
    return (Venta*) malloc(sizeof(Venta));
}

Venta* venta_newParametros(char* idStr,char* diaStr, char* mesStr, char* anioStr,char* tipoFotoStr,char*cantidadStr, char* precioUnitarioStr, char* cuilStr)
{
    Venta* pAuxEmpleado;
    Venta* retorno=NULL;
    pAuxEmpleado = venta_new();

    if(pAuxEmpleado!=NULL && idStr!=NULL && diaStr!=NULL && mesStr!=NULL && anioStr!=NULL && tipoFotoStr!=NULL && precioUnitarioStr!=NULL && cantidadStr!=NULL && cuilStr!=NULL)
    {
        if( isValidNumber(idStr) && !venta_setId(pAuxEmpleado, atoi(idStr)) &&

            !venta_setDia(pAuxEmpleado, atoi(diaStr))&&

            !venta_setMes(pAuxEmpleado, atoi(mesStr)) &&

            !venta_setAnio(pAuxEmpleado, atoi(anioStr)) &&

            !venta_setTipoFoto(pAuxEmpleado, tipoFotoStr)&&
            isValidFloatNumber(precioUnitarioStr) && !venta_setPrecioUnitario(pAuxEmpleado, atof(precioUnitarioStr)) &&
            isValidNumber(cantidadStr) && !venta_setCantidad(pAuxEmpleado, atoi(cantidadStr)) &&

            !venta_setCuil(pAuxEmpleado, cuilStr)   )
        {
            retorno = pAuxEmpleado;
        }

        else
        {
            venta_delete(pAuxEmpleado);
        }
    }

    return retorno;
}

Venta* venta_newParametrosBin(int id, char* tipoFotoStr, float precioUnitario, int cantidad)
{
    Venta* pEmpleado;
    Venta* retorno=NULL;
    pEmpleado = venta_new();
    if(id>=0 && tipoFotoStr!=NULL && precioUnitario>=0 && cantidad>=0 && pEmpleado!=NULL)
    {
        if( !venta_setId(pEmpleado, id) &&
            !venta_setTipoFoto(pEmpleado, tipoFotoStr) &&
            !venta_setPrecioUnitario(pEmpleado, precioUnitario) &&
            !venta_setCantidad(pEmpleado, cantidad) )
        {
            retorno = pEmpleado;
        }
        else
        {
            venta_delete(pEmpleado);
        }
    }
    return retorno;
}

void venta_delete(Venta* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

int venta_setId(Venta* this,int id)
{

    int retorno=-1;
    if(this!=NULL && id>=0)
    {
        this->id = id;
        retorno=0;
    }
    return retorno;
}

int venta_getId(Venta* this,int* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}


int venta_setDia(Venta* this, int dia)
{
    int retorno=-1;
    if(this!=NULL && dia>0 && dia<=31)//&& dia!=NULL)
    {
        this->dia=dia;
        retorno=0;
    }
    return retorno;
}


int venta_getDia(Venta* this,int* dia)
{
    int retorno=-1;
    if(this!=NULL && dia!=NULL)
    {
        *dia = this->dia;
        retorno=0;
    }
    return retorno;
}



int venta_setMes(Venta* this, int mes)
{
    int retorno=-1;
    if(this!=NULL && mes>0 && mes<=12)// && mes!=NULL)
    {
        this->mes=mes;
        retorno=0;
    }
    return retorno;
}


int venta_getMes(Venta* this,int* mes)
{
    int retorno=-1;
    if(this!=NULL && mes!=NULL)
    {
        *mes = this->mes;
        retorno=0;
    }
    return retorno;
}





int venta_setAnio(Venta* this, int anio)
{
    int retorno=-1;
    if(this!=NULL)// && anio!=NULL)
    {
        this->anio=anio;
        retorno=0;
    }
    return retorno;
}


int venta_getAnio(Venta* this,int* anio)
{
    int retorno=-1;
    if(this!=NULL && anio!=NULL)
    {
        *anio = this->anio;
        retorno=0;
    }
    return retorno;
}



int venta_setTipoFoto(Venta* this,char* tipoFoto)
{
    int retorno=-1;
    if(this != NULL);
    {
        strncpy(this->tipoFoto, tipoFoto, sizeof(this->tipoFoto));
        retorno=0;
    }
    return retorno;
}

int venta_getTipoFoto(Venta* this,char* tipoFoto)
{
    int retorno=-1;
    if(this!=NULL && tipoFoto!=NULL)
    {
        strncpy(tipoFoto, this->tipoFoto, sizeof(this->tipoFoto));
        retorno=0;
    }
    return retorno;
}

int venta_setPrecioUnitario(Venta* this,float precioUnitario)
{
    int retorno=-1;
    if(this!=NULL && precioUnitario>=0)
    {
        this->precioUnitario = precioUnitario;
        retorno=0;
    }
    return retorno;
}

int venta_getPrecioUnitario(Venta* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL && precioUnitario!=NULL)
    {
        *precioUnitario = this->precioUnitario;
        retorno=0;
    }
    return retorno;
}


int venta_setCantidad(Venta* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL && cantidad>=0)
    {
        this->cantidad = cantidad;
        retorno=0;
    }
    return retorno;
}


int venta_getCantidad(Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL && cantidad!=NULL)
    {
        *cantidad = this->cantidad;
        retorno=0;
    }
    return retorno;
}

/////////////////////////////



int venta_setCuil(Venta* this,char* cuil)
{
    int retorno=-1;
    if(this!=NULL && isValidCUIT(cuil))
    {
        strncpy(this->cuil, cuil, sizeof(this->cuil));
        retorno=0;
    }
    return retorno;
}

int venta_getCuil(Venta* this,char* cuil)
{
    int retorno=-1;
    if(this!=NULL && cuil!=NULL)
    {
        strncpy(cuil, this->cuil, sizeof(this->cuil));
        retorno=0;
    }
    return retorno;
}


/////////////////////////////



int venta_compararPorTipoFoto(void* thisUno, void* thisDos)
{
    int retorno;
    char auxStrA[4096];
    char auxStrB[4096];
    venta_getTipoFoto((Venta*)thisUno, auxStrA);
    venta_getTipoFoto((Venta*)thisDos, auxStrB);
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

//int venta_getIdMax()


int ventaMayor150(void* pVenta)
{
    int retorno=-1;
    float montoVenta;
    float precioUnitario;
    int cantidadVentas;

    Venta* pAuxVenta=(Venta*)pVenta;
    if(pAuxVenta!=NULL)
    {
        venta_getPrecioUnitario(pAuxVenta, &precioUnitario);
        venta_getCantidad(pAuxVenta, &cantidadVentas);


        montoVenta = cantidadVentas*precioUnitario;
        if(montoVenta>150)
        {
            retorno=1;
        }
        else
        {
            retorno=0;
        }

    }
    return retorno;
}



int ventaMayor300(void* pVenta)
{
    int retorno=-1;;
    float montoVenta;
    float precioUnitario;
    int cantidadVentas;

    if(pVenta!=NULL)
    {
        venta_getPrecioUnitario((Venta*)pVenta, &precioUnitario);
        venta_getCantidad((Venta*)pVenta, &cantidadVentas);

        montoVenta = precioUnitario*cantidadVentas;
        if(montoVenta>300)
        {
            retorno=1;
        }
        else
        {
            retorno=0;
        }

    }
    return retorno;
}



int ventasTipoPolaroids(void* pVenta)
{
    int retorno=-1;
    char bufferTipo[512];
    if(pVenta!=NULL)
    {
        venta_getTipoFoto((Venta*)pVenta, bufferTipo);

        if(strcmp(bufferTipo, "POLAROID_11x9")==0 || strcmp(bufferTipo, "POLAROID_10x10")==0)
        {
            retorno=1;
        }
        else
        {
            retorno=0;
        }
    }
    return retorno;
}
