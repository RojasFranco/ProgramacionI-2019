#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "ventas.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int parser_VentaFromText(FILE* pFile , LinkedList* pArrayListVenta)
{
    int retorno=-1;
    int cantidadDatosLeidos;
    char auxPrimerLinea[512];
    char bufferId[512];
    char bufferTipoFoto[512];
    char bufferDia[512];
    char bufferMes[512];
    char bufferAnio[512];
    char bufferCantidad[512];
    char bufferPrecioUnitario[512];
    char bufferCuil[512];
    Venta* auxEmpleado;
    if(pFile!=NULL && pArrayListVenta!=NULL)
    {
        retorno = 0;
        fscanf(pFile, "%[^\n]\n", auxPrimerLinea);
        fflush(stdin);
        do
        {

            cantidadDatosLeidos = fscanf(pFile, "%[^,],%[^/]/%[^/]/%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferDia, bufferMes, bufferAnio, bufferTipoFoto, bufferCantidad, bufferPrecioUnitario, bufferCuil);
            if( cantidadDatosLeidos==8 )
            {

                auxEmpleado = venta_newParametros(bufferId, bufferDia, bufferMes, bufferAnio, bufferTipoFoto, bufferCantidad, bufferPrecioUnitario, bufferCuil);
                if(auxEmpleado!=NULL)
                {
                    ll_add(pArrayListVenta, auxEmpleado);
                }
            }
        }while(!feof(pFile));
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int parser_VentaFromBinary(FILE* pFile , LinkedList* pArrayListVenta)
{
    int retorno=-1;
    Venta auxEmpleado;
    Venta* pEmpleado;
    if(pFile!=NULL && pArrayListVenta!=NULL)
    {
        while(!feof(pFile))
        {
            fread(&auxEmpleado, sizeof(Venta), 1, pFile);
            //printf("\n %s", auxEmpleado.tipoFoto);
            pEmpleado = venta_newParametrosBin(auxEmpleado.id, auxEmpleado.tipoFoto, auxEmpleado.cantidad, auxEmpleado.precioUnitario);
            if(pEmpleado != NULL)
            {
                ll_add(pArrayListVenta, pEmpleado);
            }

        }
        retorno=0;
    }
    return retorno;
}
