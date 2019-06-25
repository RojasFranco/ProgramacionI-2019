#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entrega.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int
 *
 */
int parser_EntregaFromText(FILE* pFile , LinkedList* pArrayListEntrega)
{
    int retorno=-1;
    int cantidadDatosLeidos;
    char auxPrimerLinea[512];
    char bufferId[512];
    char bufferTipo[512];
    char bufferCantidad[512];
    char bufferImporte[512];
    Entrega* auxEmpleado;
    if(pFile!=NULL && pArrayListEntrega!=NULL)
    {
        retorno = 0;
        fscanf(pFile, "%[^\n]\n", auxPrimerLinea);
        do
        {
            cantidadDatosLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferTipo, bufferCantidad, bufferImporte);
            if( cantidadDatosLeidos==4 )
            {
                auxEmpleado = entrega_newParametros(bufferId, bufferTipo, bufferCantidad, bufferImporte);
                if(auxEmpleado!=NULL)
                {
                    ll_add(pArrayListEntrega, auxEmpleado);
                }
                //printf("\n%s", bufferImporte);
            }
        }while(!feof(pFile));
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int
 *
 */
int parser_EntregaFromBinary(FILE* pFile , LinkedList* pArrayListEntrega)
{
    int retorno=-1;
    Entrega auxEmpleado;
    Entrega* pEmpleado;
    if(pFile!=NULL && pArrayListEntrega!=NULL)
    {
        while(!feof(pFile))
        {
            fread(&auxEmpleado, sizeof(Entrega), 1, pFile);
            //printf("\n %s", auxEmpleado.tipo);
            pEmpleado = entrega_newParametrosBin(auxEmpleado.id, auxEmpleado.tipo, auxEmpleado.cantidad, auxEmpleado.importe);
            if(pEmpleado != NULL)
            {
                ll_add(pArrayListEntrega, pEmpleado);
            }

        }
        retorno=0;
    }
    return retorno;
}
