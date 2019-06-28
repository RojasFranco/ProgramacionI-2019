#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "ventas.h"
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
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListVenta)
{
    FILE* pFile=NULL;
    int retorno=-1;
    if(path!=NULL && pArrayListVenta!=NULL)
    {
        pFile = fopen(path, "r");
        if(pFile!=NULL)
        {
            parser_VentaFromText(pFile, pArrayListVenta);
            retorno=0;
            printf("\n Empleados cargados \n");
            fclose(pFile);
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListVenta)
{
    int retorno=-1;
    FILE* pFile = NULL;
    if(path!=NULL && pArrayListVenta!=NULL)
    {
        pFile = fopen(path, "rb");
        if(pFile!=NULL)
        {
            parser_VentaFromBinary(pFile, pArrayListVenta);
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
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */

/*
int controller_addVenta(LinkedList* pArrayListVenta)
{
    int retorno=-1;
    char buffeTipoFoto[MAX_NOMBRE];
    int bufferCantidad;
    char bufferCantidadStr[512];
    int bufferPrecioUnitario;
    char bufferPrecioUnitarioStr[512];
    int id;
    char idStr[512];
    Venta* auxEmpleado;

    int reintentos;
    reintentos=2;
    if(pArrayListVenta!=NULL)
    {
        if( !utn_getName("\nIngrese nombre: ", "\nTipoFoto invalido", 1,MAX_NOMBRE, reintentos, buffeTipoFoto) &&
            !utn_getUnsignedInt("\nIngrese hs trabajadas: ", "\nDato invalido", 1, 4, 1, MAX_HS, 2, &bufferCantidad) &&
            !utn_getUnsignedInt("\nIngrese sueldo: ", "\ndato invalido", 1, 6, 1, MAX_SUELDO, 2, &bufferPrecioUnitario) )
        {
            id = controller_IdMaximo(pArrayListVenta)+1;
            sprintf(idStr, "%d", id);
            sprintf(bufferCantidadStr, "%d", bufferCantidad);
            sprintf(bufferPrecioUnitarioStr, "%d", bufferPrecioUnitario);
            auxEmpleado = venta_newParametros(idStr, buffeTipoFoto, bufferCantidadStr, bufferPrecioUnitarioStr);
            if( auxEmpleado!= NULL)
            {
                ll_add(pArrayListVenta, auxEmpleado);
                printf("\n Empleado agregado \n");
            }
        }

        retorno=0;
    }

    return retorno;
}
*/
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */

 /*
int controller_editVenta(LinkedList* pArrayListVenta)
{
    int retorno=-1;
    int idBuscado;
    int posicionEmpleado;
    int opcionModificar;
    char bufferTipoFoto[512];
    int bufferCantidad;
    int bufferPrecioUnitario;
    Venta* auxEmpleado;
    if(pArrayListVenta!=NULL)
    {
        controller_ListVenta(pArrayListVenta);
        utn_getUnsignedInt("\nIngrese id del empleado a modificar: ", "\n Dato invalido", 1, 5,1,MAX_ID, 2, &idBuscado);
        posicionEmpleado = controller_buscarId(pArrayListVenta, idBuscado);
        if(posicionEmpleado != -1)
        {
            auxEmpleado = ll_get(pArrayListVenta, posicionEmpleado);
            do
            {
                utn_getUnsignedInt("\n 1)TipoFoto\n 2)Horas Trabajadas\n 3)PrecioUnitario\n 4)Salir\n Opcion a modificar: ", "\nopcion invalida", 1, sizeof(int), 1, 5, 2, &opcionModificar);
                switch(opcionModificar)
                {
                    case 1:
                        utn_getName("\n Nuevo nombre: ", "\nDato invalido", 1, MAX_NOMBRE, 2, bufferTipoFoto);
                        venta_setTipoFoto(auxEmpleado, bufferTipoFoto);
                        break;
                    case 2:
                        utn_getUnsignedInt("\n cantidad hs trabajadas: ", "\nDato invalido", 1, sizeof(int), 1, MAX_HS, 2, &bufferCantidad);
                        venta_setCantidad(auxEmpleado, bufferCantidad);
                        break;
                    case 3:
                        utn_getUnsignedInt("\n Nuevo sueldo: ", "\n dato invalido", 1, sizeof(int), 1, MAX_SUELDO, 2, &bufferPrecioUnitario);
                        venta_setPrecioUnitario(auxEmpleado, bufferPrecioUnitario);
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
*/
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */


int controller_ListVenta(LinkedList* pArrayListVenta)
{
    int retorno=-1;
    Venta* auxEmpleado;
    int i;
    int lenArray;
    int bufferId;
    int bufferDia;
    int bufferMes;
    int bufferAnio;
    char bufferTipoFoto[512];
    int bufferCantidad;
    float bufferPrecioUnitario;
    char bufferCuil[512];
    lenArray = ll_len(pArrayListVenta);
    if(pArrayListVenta!=NULL)
    {
        for(i=0; i<lenArray; i++)
        {
            //printf("ASDASD");
            auxEmpleado = ll_get(pArrayListVenta, i);

            if(!venta_getId(auxEmpleado, &bufferId) &&
                !venta_getDia(auxEmpleado, &bufferDia) &&
                !venta_getMes(auxEmpleado, &bufferMes) &&
                !venta_getAnio(auxEmpleado, &bufferAnio) &&
               !venta_getTipoFoto(auxEmpleado, bufferTipoFoto) &&
               !venta_getCantidad(auxEmpleado, &bufferCantidad) &&
               !venta_getPrecioUnitario(auxEmpleado,&bufferPrecioUnitario) &&
               !venta_getCuil(auxEmpleado, bufferCuil))
            {
                printf("\n ID:%d - Dia:%d - Mes:%d - Anio:%d - TipoFoto:%s - Cantidad:%d - PrecioUnitario:%.2f - Cuil: %s", bufferId, bufferDia, bufferMes, bufferAnio, bufferTipoFoto, bufferCantidad, bufferPrecioUnitario, bufferCuil);
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */

 /*
int controller_sortVenta(LinkedList* pArrayListVenta)
{
    int retorno=-1;
    if(pArrayListVenta!=NULL)
    {
        ///ll_sort(pArrayListVenta, )     aplicar ordenamiento por puntero funcion.-
        ll_sort(pArrayListVenta, venta_compararPorTipoFoto, 1);
        retorno=0;
    }
    return retorno;
}
*/
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListVenta)
{
    FILE* pFile=NULL;
    int retorno=-1;
    //Venta* auxVenta;
    int cantidadTotalFotos;
    int cantidadVentasMayor150;
    int cantidadVentasMayor300;
    int cantidadFotosPolaroids;
    /*int i;
    int lenArray;
    char bufferTipoFoto[512];
    int bufferId;
    int bufferCantidad;
    float bufferPrecioUnitario;*/
    if(path!=NULL && pArrayListVenta!=NULL)
    {
        pFile = fopen(path, "w");
        if(pFile!=NULL)
        {
            cantidadTotalFotos = controller_cantidadFotos(pArrayListVenta);
            cantidadVentasMayor150 = ll_count(pArrayListVenta, ventaMayor150);
            cantidadVentasMayor300 = ll_count(pArrayListVenta, ventaMayor300);
            cantidadFotosPolaroids = ll_count(pArrayListVenta, ventasTipoPolaroids);


            fprintf(pFile, "*****************************\nInforme de Ventas\n*****************************\n");
            fprintf(pFile, "Cantidad Fotos Totales: %d\n", cantidadTotalFotos);
            fprintf(pFile, "Ventas mayor 150: %d\n", cantidadVentasMayor150);
            fprintf(pFile, "Ventas mayor 300: %d\n", cantidadVentasMayor300);
            fprintf(pFile, "Cantidad fotos Polaroids: %d\n" , cantidadFotosPolaroids);
            fprintf(pFile, "*****************************\n");
            retorno=0;
        }
        fclose(pFile);
    }
    return retorno;
}




int controller_IdMaximo(LinkedList* pArrayListVenta)
{
    //int retorno=-1;
    Venta* auxEmpleado;
    int idMaximo=-1;
    int i;
    int lenArray;
    int bufferId;
    lenArray = ll_len(pArrayListVenta);
    for(i=0; i<lenArray; i++)
    {
        auxEmpleado=ll_get(pArrayListVenta, i);
        if(!venta_getId(auxEmpleado, &bufferId) && bufferId>idMaximo)
        {
            idMaximo = bufferId;
        }
    }
    return idMaximo;
}

int controller_buscarId(LinkedList* pArrayListVenta, int idBuscado)
{
    int retorno=-1;
    Venta* auxEmpleado;
    int idEmpleado;
    int lenArray;
    lenArray = ll_len(pArrayListVenta);
    int i;
    if(pArrayListVenta!=NULL && idBuscado>=0)
    {
        for(i=0; i<lenArray; i++)
        {
            auxEmpleado = ll_get(pArrayListVenta, i);
            if (!venta_getId(auxEmpleado, &idEmpleado) && idEmpleado == idBuscado)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int controller_cantidadFotos(LinkedList* pArrayVentas)
{
    int i;
    int retornoCantidad=0;
    int lenArray;
    int cantidadNuevaVenta;
    Venta* auxVenta;
    if(pArrayVentas!=NULL)
    {
        lenArray = ll_len(pArrayVentas);
        for(i=0; i<lenArray; i++)
        {
            auxVenta = ll_get(pArrayVentas, i);
            venta_getCantidad(auxVenta, &cantidadNuevaVenta);
            retornoCantidad+=cantidadNuevaVenta;
        }
    }
    return retornoCantidad;

}
