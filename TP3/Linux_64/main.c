#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

///para modificar: encontrar por id (crear funcion findById.-
///para ordenar ll tiene funcion - a sort le puedo pasar una funcion creada con strcmp(en la cual determino cual va antes
///guardar: guardar el empleado(copiar los datos) no el puntero- (usar *)



int main()
{

    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();


    /*FILE* pFile = NULL;
    pFile = fopen("data.csv", "r");
    if(pFile!=NULL)
    {
        parser_EmployeeFromText(pFile, listaEmpleados);
    }*/
    controller_loadFromText("data.csv",listaEmpleados);
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 6:
                controller_loadFromBinary("data.bin", listaEmpleados);
        }
    }while(option != 10);
    return 0;
}
