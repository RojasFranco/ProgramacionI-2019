#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asociado.h"
#include "utn_strings.h"


int asoc_inicializar(Asociado* asociados, int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        asociados[i].estado=1;
        asociados[i].idAsociado=-1;
    }
    return 0;
}

int asoc_mostrar(Asociado* asociados, int len)
{
    int i;
    for (i=0; i<len; i++)
    {
        if(asociados[i].estado==0)
        {
            printf("Estado: %d\n", asociados[i].estado);
            printf("ID asociado: %d\n",asociados[i].idAsociado);
            printf("Nombre: %s\n",asociados[i].nombre);
            printf("Apellido: %s\n",asociados[i].apellido);
            printf("DNI: %s\n",asociados[i].dni);
            printf("Edad: %d\n\n",asociados[i].edad);
        }
    }
    return 0;
}

int asoc_buscarLibre(Asociado* asociados, int len)
{
    int i;
    int retorno=-1;
    for(i=0; i<len; i++)
    {
        if(asociados[i].estado==1)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int asoc_alta(Asociado *asociados, int len, int posicion)
{
    char edadAux[20];

    if(!getStringLetras(asociados[posicion].nombre, "Ingrese su nombre:", "nombre invalido", 2))
    {
        if(!getStringLetras(asociados[posicion].apellido, "Ingrese su apellido:", "apellido invalido", 2))
        {
            if(!getStringNumeros(edadAux, "Ingrese edad:", "edad invalida", 2))
            {
                if(!getStringNumeros(asociados[posicion].dni, "Ingrese DNI:", "dni invalido", 2))
                {
                    asociados[posicion].edad=atoi(edadAux);
                    asociados[posicion].idAsociado=asoc_generarId();
                    asociados[posicion].estado=0;
                }
            }
        }
    }
    return 0;
}

int asoc_buscarPorId(Asociado *asociados, int len)
{
    char bufferId[20];
    int idBuscado;
    int retorno=-1;
    int i;
    if(!getStringNumeros(bufferId, "Ingrese ID a modificar:", "id invalido\n", 2))
    {
        idBuscado=atoi(bufferId);
        for(i=0; i<len; i++)
        {
            if(asociados[i].idAsociado==idBuscado)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int asoc_modificar(Asociado *asociados, int len, int posicion)
{
    if(!getStringLetras(asociados[posicion].nombre, "Ingrese nuevo nombre: ","nombre invalido\n", 2))
    {
        if(!getStringLetras(asociados[posicion].apellido,"Ingrese nuevo apellido: ", "apellido invalido\n", 2))
        {
            printf("Se modifico exitosamente\n");
        }

    }
    return 0;
}

int asoc_baja(Asociado* asociados, int len, int posicion)
{
    asociados[posicion].estado=1;
    return 0;
}

static int asoc_generarId(void)
{
    static int primerId=0;
    return primerId++;
}
