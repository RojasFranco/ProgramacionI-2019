#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "autor.h"
#include "libro.h"
#include "socio.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array socio Array of socio
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int socio_Inicializar(Socio array[], int size)                                    //cambiar socio
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
            array[size-1].idSocio=-1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array socio Array de socio
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int socio_buscarEmpty(Socio array[], int size, int* posicion)                    //cambiar socio
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array socio Array de socio
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socio_buscarID(Socio array[], int size, int valorBuscado, int* posicion)                    //cambiar socio
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idSocio==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


//String
/** \brief Busca un string en un array
* \param array socio Array de socio
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socio_buscarString(Socio array[], int size, char* valorBuscado, int* indice)                    //cambiar socio
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array socio Array de socio
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int socio_alta(Socio array[], int size, int* contadorID, Fecha fechaAsociado[], int *contadorIDFecha)                          //cambiar socio
{
    int retorno=-1;
    int posicion;
    char bufferSexo;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(socio_buscarEmpty(array,size,&posicion)==-1)                          //cambiar socio
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idSocio=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
            utn_getName("\nApellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);
            utn_getChar("\nSexo (F/M):","Error",1, 1, 1, &array[posicion].sexo);
            utn_getTelefono("\nTelefono:", "\nTel invalido", 1, 20, 1, 20, 1, array[posicion].telefono);
            utn_getEmail("\nEmail: ","\nError",1,TEXT_SIZE,1,array[posicion].email);                 //mensaje + cambiar campo email
            fecha_alta(fechaAsociado, 10, &contadorIDFecha);
            array.fechaAsociado = fechaAsociado;
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array socio Array de socio
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int socio_baja(Socio array[], int sizeArray)                                      //cambiar socio
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(socio_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            /*array[posicion].idSocio=0;                                                                   //cambiar campo id


            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].email,"");                                               //cambiar campo email
            retorno=0;*/
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array socio Array de socio
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int socio_bajaValorRepetidoInt(Socio array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idSocio==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idSocio=0;                                                                   //cambiar campo id


                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].email,"");                                               //cambiar campo email
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array socio Array de socio
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int socio_modificar(Socio array[], int sizeArray)                                //cambiar socio
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(socio_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\nnombre: %s\n email: %s",
                   posicion, array[posicion].idSocio,array[posicion].nombre,array[posicion].email);
                utn_getChar("\nModificar: A-Nombre\n B-Apellido\n C-Sexo\n D-Tel\n E-Email\n S(salir)\n","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nNombre nuevo: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
                        break;
                    case 'B':
                        utn_getName("Apellido nuevo: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);
                        break;
                    case 'C':
                        utn_getChar("Ingrese nuevo sexo","sexo invalido\n", 1, 2, 1, &array[posicion].sexo);
                        break;
                    case 'D':
                        utn_getTelefono("Ingrese nuevo telefono:", "tel invalido\n", 1, 20, 1, 20, 1, array[posicion].telefono);
                        break;
                    case 'E':
                        utn_getTexto("Email\n: ","\nError",1,TEXT_SIZE,1,array[posicion].email);             //mensaje + cambiar campo email
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array socio Array de socio
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int socio_ordenarPorDobleCriterio(Socio array[],int size, int orderFirst, int orderSecond)                              //cambiar socio
{
    int retorno=-1;
    int i;
    Socio buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0) && orderFirst) ||
                    ((strcmp(array[i].nombre,array[i+1].nombre) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
               /* else if(strcmp(array[i].nombre,array[i+1].nombre) == 0)
                {
                    if( ((array[i].varFloat < array[i+1].varFloat) && orderSecond) ||
                        ((array[i].varFloat > array[i+1].varFloat) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                    }
                }*/
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array socio Array de socio
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int socio_listar(Socio array[], int size)                      //cambiar socio
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n Posicion: %d\n ID: %d\nnombre: %s\napellido:%s \nsexo:%c \nTelefono:%s \n email: %s\nFecha:%d\n",
                   i, array[i].idSocio,array[i].nombre,array[i].apellido, array[i].sexo, array[i].telefono, array[i].email, array[i].fechaAsociado.dia);
        }
        retorno=0;
    }
    return retorno;
}

/*
void socio_mock(Socio arraySocio[], int size,int *contadorId)                      //cambiar socio
{
    //*******************************************************************
    arraySocio[0].idSocio=0;
    arraySocio[0].isEmpty=0;
    arraySocio[0].varInt=0;
    arraySocio[0].varFloat=0;
    strcpy(arraySocio[0].email,"CCCCC");
    strcpy(arraySocio[0].nombre,"CCCCC");
    *contadorId++;

    arraySocio[1].idSocio=1;
    arraySocio[1].isEmpty=0;
    arraySocio[1].varInt=0;
    arraySocio[1].varFloat=0;
    strcpy(arraySocio[1].email,"AAAAA");
    strcpy(arraySocio[1].nombre,"AAAAA");
    *contadorId++;

    arraySocio[2].idSocio=2;
    arraySocio[2].isEmpty=0;
    arraySocio[2].varInt=0;
    arraySocio[2].varFloat=20;
    strcpy(arraySocio[2].email,"BBBBB");
    strcpy(arraySocio[2].nombre,"BBBBBB");
    *contadorId++;

    arraySocio[3].idSocio=3;
    arraySocio[3].isEmpty=0;
    arraySocio[3].varInt=0;
    arraySocio[3].varFloat=10;
    strcpy(arraySocio[3].email,"BBBBB");
    strcpy(arraySocio[3].nombre,"BBBBBB");
    contadorId++;
}
*/
