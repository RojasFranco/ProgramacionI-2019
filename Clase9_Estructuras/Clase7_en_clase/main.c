#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Empleado.h"

#define LEN_LISTA    100

///Estructuras
//cada nueva entidad la guardamos en un archivo c(trabajamos las funciones) y un archivo h(struc y firma de funciones)
/*
struct sEmpleado
{
    int idEmpleado; //lo que ingrese el usuario lo guardamos en un id de modo que si modifica inf no afecte a ese id
    int isEmpty;
    ///1ero registro los campos que tiene el empleado
    char nombre[50];
    char apellido[50];
    char dni[50];
}

struct sEmpleado auxiliarEmpleado; ///declaro un aux de la estructura empleado
struct sEmpleado *pEmpleado;
struct sEmpleado auxiliarEmpleado[500];///para declarar 500 empleados

auxiliarEmpleado.dni; ///acceder a dni

pEmpleado= &auxiliarEmpleado;
pEmpleado=&auxiliarEmpleado[114]; ///nombre de la posicion 114
pEmpleado->apellido; /// acceder apellido pero de un puntero
*/
///La forma mas común de escribila
/*
typedef struct
{
    int idEmpleado;
    int isEmpty;
    char nombre[50];
    char apellido[50];
    char dni[30]
}Empleado;

Empleado auxiliarEmpleado[500];
Empleado *pEmpleado;

pEmpleado=&auxiliarEmpleado[114];
pEmpleado->apellido;
*/








int buscarLibre(char lista[][20],
                int len,
                int* pIndex)
{
    int i;
    int ret=-1;
    for(i=0; i<len ; i++)
    {
        if(lista[i][0]=='\0')
        {
            *pIndex = i;
            ret=0;
            break;
        }
    }
    return ret;

}


int buscarNombre(char* pNombre,
                 char lista[][20],
                 int len,
                 int* pIndex
)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(strcmp(pNombre,lista[i])==0)
        {
            *pIndex = i;
            ret=0;
            break;
        }
    }
    return ret;


}


int main()
{
    /*
    int opcion;
    char nombres[LEN_LISTA][20];
    int i,posLibre, posAeliminar;
    char buffer[20];

    for(i=0; i<LEN_LISTA;i++)
        nombres[i][0]='\0';



    while(1)
    {

        utn_getNumber(&opcion,
                      "1)ingresar\n2)listar,4)eliminar\n",
                      "NO!",
                      1,10,2);

        printf("elegiste:%d\n",opcion);
        switch(opcion)
        {
            case 1:
            {
                printf("agregar nombre\n");

                if(buscarLibre(nombres,LEN_LISTA,&posLibre)==0)
                {
                    printf("1.se encontro lugar en %d\n",posLibre);

                    //utn_getString(buffer,"Ingrese:","No!",0,20,1);
                    fgets(buffer,20,stdin);

                    printf("se ingreso:%s\n",buffer);

                    printf("2. se encontro lugar en %d\n",posLibre);
                    //nombres[posLibre] = buffer;
                    strncpy(nombres[posLibre],buffer,20);


                    for(i=0;i<10; i++)
                        printf("-%d: %s\n",i,nombres[i]);

                }

                break;
            }
            case 4:
            {
                // PIDO NOMBRE
                //utn_getString(buffer,...)
                fgets(buffer,20,stdin);buffer[strlen(buffer)-1]='\0';

                // en buffer esta el nombre
                buscarNombre(buffer,
                            nombres,
                            LEN_LISTA,
                            &posAeliminar);

                // borro
                nombres[posAeliminar][0]='\0';

                break;
            }
        }

    }
    */
    Empleado arrayEmpleado[3];
    emp_initArray(arrayEmpleado, 3);
    return 0;
}



