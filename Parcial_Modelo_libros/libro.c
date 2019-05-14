#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "autor.h" //cambiar por nombre entidad
#include "libro.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array libro Array of libro
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int libro_Inicializar(Libro array[], int size)                                    //cambiar libro
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array libro Array de libro
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int libro_buscarEmpty(Libro array[], int size, int* posicion)                    //cambiar libro
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
* \param array libro Array de libro
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libro_buscarID(Libro array[], int size, int valorBuscado, int* posicion)                    //cambiar libro
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idLibro==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array libro Array de libro
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libro_buscarInt(Libro array[], int size, int valorBuscado, int* posicion)                    //cambiar libro
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idAutor==valorBuscado)                                                   //cambiar campo idAutor
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
* \param array libro Array de libro
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libro_buscarString(Libro array[], int size, char* valorBuscado, int* indice)                    //cambiar libro
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].tituloLibro,valorBuscado)==0)                                        //cambiar campo tituloLibro
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
* \param array libro Array de libro
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int libro_alta(Libro array[], Autor arrayAutor[], int sizeAutor, int size, int* contadorID)                          //cambiar libro
{
    int retorno=-1;
    int posicion;
    int bufferId;
    int posicionId;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(libro_buscarEmpty(array,size,&posicion)==-1)                          //cambiar libro
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            autor_listar(arrayAutor, sizeAutor);                   //cambiar
            utn_getUnsignedInt("\ngetIngrese ID autor: ","\nError",1,sizeof(int),1,10,1,&bufferId);           //mensaje + cambiar campo idAutor
            if(!autor_buscarID(arrayAutor, sizeAutor, bufferId, &posicionId))
            {
                if(!utn_getTexto("\nTitulo del libro: ","\nError",1,TEXT_SIZE,1,array[posicion].tituloLibro))                      //mensaje + cambiar campo tituloLibro
                {

                    (*contadorID)++;
                    array[posicion].idLibro=*contadorID;                                                       //campo ID
                    array[posicion].isEmpty=0;
                    array[posicion].idAutor=arrayAutor[posicionId].idUnico;
                    printf("\n Posicion: %d\n ID: %d\n idAutor: %d\n tituloLibro: %s\n",
                    posicion, array[posicion].idLibro, array[posicion].idAutor, array[posicion].tituloLibro);
                    retorno=0;
                }
            }
            else
            {
                printf("ID no encontrado\n\n");
            }


        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array libro Array de libro
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int libro_baja(Libro array[], int sizeArray)                                      //cambiar libro
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(libro_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            /*array[posicion].idLibro=0;                                                                   //cambiar campo id
            array[posicion].idAutor=0;                                                               //cambiar campo idAutor
                                                                         //cambiar campo varFloat
            strcpy(array[posicion].tituloLibro,"");                                                   //cambiar campo tituloLibro
            */                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array libro Array de libro
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int libro_bajaValorRepetidoInt(Libro array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idLibro==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idLibro=0;                                                                   //cambiar campo id
                array[i].idAutor=0;                                                               //cambiar campo idAutor

                strcpy(array[i].tituloLibro,"");                                                   //cambiar campo tituloLibro

            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array libro Array de libro
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int libro_modificar(Libro array[], Autor arrayAutor[], int sizeArrayAutor, int sizeArray)                                //cambiar libro
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    int bufferIdAutor;
    int posicionIdAutor;
    if(array!=NULL && sizeArray>0)
    {
        libro_listar(array, sizeArray);
        utn_getUnsignedInt("\nID a modificar: ","Error\n",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(libro_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n idAutor: %d\ntituloLibro: %s\n",
                    posicion, array[posicion].idLibro,array[posicion].idAutor,array[posicion].tituloLibro);
                utn_getChar("\nModificar: A-Id autor \nB- Titulo libro\n S(salir)\n","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        autor_listar(arrayAutor, sizeArrayAutor);
                        if(!utn_getUnsignedInt("\nIngrese nuevo id de autor:","error",0,sizeof(int), 0, 10, 1, &bufferIdAutor))
                        {
                            if(autor_buscarID(arrayAutor, sizeArrayAutor, bufferIdAutor, &posicionIdAutor))
                            {
                                printf("Id de autor invalido\n");
                            }
                            else
                            {
                                array[posicion].idAutor=arrayAutor[posicionIdAutor].idUnico;
                            }
                        }
                        break;
                    /*case 'B':
                        utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
                        break;*/
                    case 'B':
                        utn_getTexto("Nuevo titulo: ","\nError",1,TEXT_SIZE,1,array[posicion].tituloLibro);              //mensaje + cambiar campo tituloLibro
                        break;
                    /*case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);             //mensaje + cambiar campo varLongString
                        break;*/
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
* \param array libro Array de libro
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int libro_ordenarPorDobleCriterio(Libro array[],int size, int orderFirst, int orderSecond)                              //cambiar libro
{
    int retorno=-1;
    int i;
    Libro buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].tituloLibro,array[i+1].tituloLibro) < 0) && orderFirst) ||
                    ((strcmp(array[i].tituloLibro,array[i+1].tituloLibro) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                /*else if(strcmp(array[i].tituloLibro,array[i+1].tituloLibro) == 0)
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
* \param array libro Array de libro
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int libro_listar(Libro array[], int size)                      //cambiar libro
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
                printf("\n Posicion: %d\n ID: %d\n idAutor: %d\ntituloLibro: %s\n",
                       i, array[i].idLibro,array[i].idAutor,array[i].tituloLibro);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}

/*
void libro_mock(Libro arrayLibro[], int size,int *contadorId)                      //cambiar libro
{
    //*******************************************************************

    arrayLibro[0].idLibro=0;
    arrayLibro[0].isEmpty=0;
    arrayLibro[0].idAutor=0;


    strcpy(arrayLibro[0].tituloLibro,"CCCCC");
    *contadorId++;

    arrayLibro[1].idLibro=1;
    arrayLibro[1].isEmpty=0;
    arrayLibro[1].idAutor=0;


    strcpy(arrayLibro[1].tituloLibro,"AAAAA");
    *contadorId++;

    arrayLibro[2].idLibro=2;
    arrayLibro[2].isEmpty=0;
    arrayLibro[2].idAutor=0;


    strcpy(arrayLibro[2].tituloLibro,"BBBBBB");
    *contadorId++;

    arrayLibro[3].idLibro=3;
    arrayLibro[3].isEmpty=0;
    arrayLibro[3].idAutor=0;


    strcpy(arrayLibro[3].tituloLibro,"BBBBBB");
    contadorId++;
}

*/
