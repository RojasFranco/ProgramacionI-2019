#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entrega.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#define MAX_NOMBRE 20
#define MAX_HS 200
#define MAX_SUELDO 30000
#define MAX_ID 2000


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEntrega)
{
    FILE* pFile=NULL;
    int retorno=-1;
    if(path!=NULL && pArrayListEntrega!=NULL)
    {
        pFile = fopen(path, "r");
        if(pFile!=NULL)
        {
            parser_EntregaFromText(pFile, pArrayListEntrega);
            retorno=0;
            printf("\n Entregas cargadas \n");
            fclose(pFile);
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEntrega)
{
    int retorno=-1;
    FILE* pFile = NULL;
    if(path!=NULL && pArrayListEntrega!=NULL)
    {
        pFile = fopen(path, "rb");
        if(pFile!=NULL)
        {
            parser_EntregaFromBinary(pFile, pArrayListEntrega);
            retorno=0;
            printf("\n Empleados cargados \n");
            fclose(pFile);
        }
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int
 *
 */
int controller_addEntrega(LinkedList* pArrayListEntrega)
{
    int retorno=-1;
    char buffeTipo[MAX_NOMBRE];
    int bufferCantidad;
    char bufferCantidadStr[512];
    int bufferImporte;
    char bufferImporteStr[512];
    int id;
    char idStr[512];
    Entrega* auxEmpleado;
    /*auxEmpleado = entrega_new();*/
    int reintentos;
    reintentos=2;
    if(pArrayListEntrega!=NULL)
    {
        if( !utn_getName("\nIngrese nombre: ", "\nTipo invalido", 1,MAX_NOMBRE, reintentos, buffeTipo) &&
            !utn_getUnsignedInt("\nIngrese hs trabajadas: ", "\nDato invalido", 1, 4, 1, MAX_HS, 2, &bufferCantidad) &&
            !utn_getUnsignedInt("\nIngrese sueldo: ", "\ndato invalido", 1, 6, 1, MAX_SUELDO, 2, &bufferImporte) )
        {
            id = controller_IdMaximo(pArrayListEntrega)+1;
            sprintf(idStr, "%d", id);
            sprintf(bufferCantidadStr, "%d", bufferCantidad);
            sprintf(bufferImporteStr, "%d", bufferImporte);
            auxEmpleado = entrega_newParametros(idStr, buffeTipo, bufferCantidadStr, bufferImporteStr);
            if( auxEmpleado!= NULL)
            {
                ll_add(pArrayListEntrega, auxEmpleado);
                printf("\n Empleado agregado \n");
            }
        }
        /*else
        {
            entrega_delete(auxEmpleado);
        }*/
        retorno=0;
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int
 *
 */
int controller_editEntrega(LinkedList* pArrayListEntrega)
{
    int retorno=-1;
    int idBuscado;
    int posicionEmpleado;
    int opcionModificar;
    char bufferTipo[512];
    int bufferCantidad;
    int bufferImporte;
    Entrega* auxEmpleado;
    if(pArrayListEntrega!=NULL)
    {
        controller_ListEntrega(pArrayListEntrega);
        utn_getUnsignedInt("\nIngrese id del empleado a modificar: ", "\n Dato invalido", 1, 5,1,MAX_ID, 2, &idBuscado);
        posicionEmpleado = controller_buscarId(pArrayListEntrega, idBuscado);
        if(posicionEmpleado != -1)
        {
            auxEmpleado = ll_get(pArrayListEntrega, posicionEmpleado);
            do
            {
                utn_getUnsignedInt("\n 1)Tipo\n 2)Horas Trabajadas\n 3)Importe\n 4)Salir\n Opcion a modificar: ", "\nopcion invalida", 1, sizeof(int), 1, 5, 2, &opcionModificar);
                switch(opcionModificar)
                {
                    case 1:
                        utn_getName("\n Nuevo nombre: ", "\nDato invalido", 1, MAX_NOMBRE, 2, bufferTipo);
                        entrega_setTipo(auxEmpleado, bufferTipo);
                        break;
                    case 2:
                        utn_getUnsignedInt("\n cantidad hs trabajadas: ", "\nDato invalido", 1, sizeof(int), 1, MAX_HS, 2, &bufferCantidad);
                        entrega_setCantidad(auxEmpleado, bufferCantidad);
                        break;
                    case 3:
                        utn_getUnsignedInt("\n Nuevo sueldo: ", "\n dato invalido", 1, sizeof(int), 1, MAX_SUELDO, 2, &bufferImporte);
                        entrega_setImporte(auxEmpleado, bufferImporte);
                        break;
                    case 4:
                        break;
                    default:
                        printf("\n Opcion invalida\n");
                }
            }while(opcionModificar!=4);
        }
        else
        {
            printf("\n No se encuentra id \n");
        }
    retorno=0;
    }



    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int
 *
 */
int controller_removeEntrega(LinkedList* pArrayListEntrega)
{
    int retorno=-1;
    int idEliminar;
    int posicionId;
    Entrega* auxEmpleado;
    if(pArrayListEntrega!=NULL)
    {
        controller_ListEntrega(pArrayListEntrega);
        utn_getUnsignedInt("\n Ingrese id a eliminar:", "\nDato invalido", 1, 5, 1, MAX_ID, 2, &idEliminar);
        posicionId = controller_buscarId(pArrayListEntrega, idEliminar);
        if(posicionId!=-1)
        {
            auxEmpleado = ll_get(pArrayListEntrega, posicionId);
            entrega_delete(auxEmpleado);
            ll_remove(pArrayListEntrega, posicionId);
            printf("\n Empleado eliminado \n");
        }
        else
        {
            printf("\n No se encuentra id \n");
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int
 *
 */
int controller_ListEntrega(LinkedList* pArrayListEntrega)
{
    int retorno=-1;
    Entrega* auxEmpleado;
    int i;
    int lenArray;
    int bufferId;
    char bufferTipo[512];
    int bufferCantidad;
    float bufferImporte;
    lenArray = ll_len(pArrayListEntrega);
    if(pArrayListEntrega!=NULL)
    {
        for(i=0; i<lenArray; i++)
        {
            auxEmpleado = ll_get(pArrayListEntrega, i);
            if(!entrega_getId(auxEmpleado, &bufferId) &&
               !entrega_getTipo(auxEmpleado, bufferTipo) &&
               !entrega_getCantidad(auxEmpleado, &bufferCantidad) &&
               !entrega_getImporte(auxEmpleado,&bufferImporte))
            {
                printf("\n ID:%d - Tipo:%s - Cantidad:%d - Importe:%f", bufferId, bufferTipo, bufferCantidad, bufferImporte);
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int
 *
 */
int controller_sortEntrega(LinkedList* pArrayListEntrega)
{
    int retorno=-1;
    if(pArrayListEntrega!=NULL)
    {
        ///ll_sort(pArrayListEntrega, )     aplicar ordenamiento por puntero funcion.-
        ll_sort(pArrayListEntrega, entrega_compararPorTipo, 1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEntrega)
{
    FILE* pFile=NULL;
    int retorno=-1;
    Entrega* auxEmpleado;
    int i;
    int lenArray;
    char bufferTipo[512];
    int bufferId;
    int bufferCantidad;
    float bufferImporte;
    if(path!=NULL && pArrayListEntrega!=NULL)
    {
        lenArray = ll_len(pArrayListEntrega);
        pFile = fopen(path, "w");
        if(pFile!=NULL)
        {
            for(i=0; i<lenArray; i++)
            {
                auxEmpleado = ll_get(pArrayListEntrega, i);
                entrega_getId(auxEmpleado, &bufferId);
                entrega_getCantidad(auxEmpleado, &bufferCantidad);
                entrega_getImporte(auxEmpleado, &bufferImporte);
                entrega_getTipo(auxEmpleado, bufferTipo);
                fprintf(pFile , "%d, %s, %d, %f\n", bufferId, bufferTipo, bufferCantidad, bufferImporte);
            }
            retorno=0;
        }
        fclose(pFile);
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEntrega)
{
    int retorno=-1;
    FILE* pFile=NULL;
    Entrega* auxEmpleado;
    int i;
    int lenArray;
    if(path!=NULL && pArrayListEntrega!=NULL)
    {
        lenArray = ll_len(pArrayListEntrega);
        pFile = fopen(path, "wb");
        if(pFile!=NULL)
        {
            for(i=0; i<lenArray; i++)
            {
                auxEmpleado = ll_get(pArrayListEntrega, i);
                fwrite(auxEmpleado, sizeof(Entrega),1, pFile);
                //printf("\n %s", auxEmpleado->nombre);
            }
            retorno=0;
            fclose(pFile);
        }
    }

    return retorno;
}

int controller_IdMaximo(LinkedList* pArrayListEntrega)
{
    //int retorno=-1;
    Entrega* auxEmpleado;
    int idMaximo=-1;
    int i;
    int lenArray;
    int bufferId;
    lenArray = ll_len(pArrayListEntrega);
    for(i=0; i<lenArray; i++)
    {
        auxEmpleado=ll_get(pArrayListEntrega, i);
        if(!entrega_getId(auxEmpleado, &bufferId) && bufferId>idMaximo)
        {
            idMaximo = bufferId;
        }
    }
    return idMaximo;
}

int controller_buscarId(LinkedList* pArrayListEntrega, int idBuscado)
{
    int retorno=-1;
    Entrega* auxEmpleado;
    int idEmpleado;
    int lenArray;
    lenArray = ll_len(pArrayListEntrega);
    int i;
    if(pArrayListEntrega!=NULL && idBuscado>=0)
    {
        for(i=0; i<lenArray; i++)
        {
            auxEmpleado = ll_get(pArrayListEntrega, i);
            if (!entrega_getId(auxEmpleado, &idEmpleado) && idEmpleado == idBuscado)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}
