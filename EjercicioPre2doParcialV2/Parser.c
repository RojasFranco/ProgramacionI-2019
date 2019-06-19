#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"

int parser_parseEmpleados(char* fileName,LinkedList* listaEmpleados)
{
    int retorno=-1;
    FILE* pFile;
    int cantidadDatosLeidos;
    char auxPrimerLinea[512];
    char bufferId[512];
    char bufferNombre[512];
    char bufferHorasTrabajadas[512];
    //char bufferSueldo[512];
    Employee* auxEmpleado;
    if(fileName!=NULL && listaEmpleados!=NULL)
    {
        pFile = fopen(fileName, "r");
        if(pFile!=NULL)
        {

            retorno = 1;
            fscanf(pFile, "%[^\n]\n", auxPrimerLinea);
            do
            {
                cantidadDatosLeidos = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferHorasTrabajadas);//, bufferSueldo);
                if( cantidadDatosLeidos==3 )
                {
                    auxEmpleado = employee_newParametros(bufferId, bufferNombre, bufferHorasTrabajadas);//, bufferSueldo);
                    if(auxEmpleado!=NULL)
                    {
                        ll_add(listaEmpleados, auxEmpleado);
                    }
                    //printf("\n%s", bufferNombre);
                }
            }while(!feof(pFile));
        }
    }
    return retorno;
}
