#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entrega.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include "informe.h"

int informe_cantidadTotalEntregas(LinkedList* pListaEntregas)
{
    int retorno=-1;
    int i;
    int auxCantidad;
    Entrega* pBufferEntrega;
    int cantidadTotal=0;
    if(pListaEntregas!=NULL)
    {
        for(i=0; i<ll_len(pListaEntregas); i++)
        {
            pBufferEntrega = ll_get(pListaEntregas, i);
            entrega_getCantidad(pBufferEntrega, &auxCantidad);
            cantidadTotal+=auxCantidad;
        }
        retorno=0;
        printf("\n\n %d", cantidadTotal);
    }
    return retorno;
}

int informe_cantidadPorTipo(LinkedList* pListaEntregas)
{
    Entrega* pAuxEntrega;
    char bufferTipo[512];
    int cantidadGold=0;
    int cantidadRegular=0;
    int cantidadPlus=0;
    int i;
    int bufferCantidad;
    int retorno=-1;
    if(pListaEntregas!=NULL)
    {
        for(i=0; i<ll_len(pListaEntregas); i++)
        {
            pAuxEntrega = ll_get(pListaEntregas, i);
            entrega_getTipo(pAuxEntrega, bufferTipo);
            entrega_getCantidad(pAuxEntrega, &bufferCantidad);
            retorno=0;
            if(strncmp(bufferTipo, "GOLD", sizeof(bufferTipo))==0 )
            {
                cantidadGold+=bufferCantidad;
            }
            else if(strncmp(bufferTipo, "REGULAR", sizeof(bufferTipo))==0)
            {
                cantidadRegular+= bufferCantidad;
            }
            else
            {
                cantidadPlus+= bufferCantidad;
            }
        }
        printf("\n Cantidad GOLD: %d - Cantidad Regular: %d - Cantidad Plus: %d ", cantidadGold, cantidadRegular, cantidadPlus);
    }
    return retorno;
}

