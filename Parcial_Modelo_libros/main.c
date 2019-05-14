#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "fantasma.h"  //cambiar por nombre entidad
#include "autor.h"
#include "libro.h"
#include "socio.h"
#include "fecha.h"

#define QTY_ARRAY_TIPO 10
#define QTY_ARRAY_AUTOR 10
#define QTY_ARRAY_LIBRO 10
#define QTY_ARRAY_SOCIO 10
#define QTY_ARRAY_FECHA 10
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;
    int contadorIdfantasma=0;                   //cambiar

    Fantasma arrayFantasma[QTY_ARRAY_TIPO];                   //cambiar
    fantasma_Inicializar(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
    fantasma_mock(arrayFantasma, QTY_ARRAY_TIPO, &contadorIdfantasma) ;                     //cambiar fantasma

    int contadorIdFecha=0;
    Fecha arrayFecha[QTY_ARRAY_FECHA];
    fecha_Inicializar(arrayFecha, QTY_ARRAY_FECHA);


    int contadorIdautor=0;
    Autor arrayAutor[QTY_ARRAY_AUTOR];                   //cambiar
    autor_Inicializar(arrayAutor,QTY_ARRAY_AUTOR);                   //cambiar
    //autor_mock(arrayAutor, QTY_ARRAY_AUTOR, &contadorIdautor) ;                     //cambiar fantasma


    int contadorIdlibro=0;
    Libro arrayLibro[QTY_ARRAY_LIBRO];                   //cambiar
    libro_Inicializar(arrayLibro,QTY_ARRAY_LIBRO);                   //cambiar
    //libro_mock(arrayLibro, QTY_ARRAY_LIBRO, &contadorIdlibro) ;

    int contadorIdSocio=0;
    Socio arraySocio[QTY_ARRAY_SOCIO];
    socio_Inicializar(arraySocio, QTY_ARRAY_SOCIO);


    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n"
                            "6) Alta autor \n7) Modificar autor \n8) Baja autor \n9) Listar autor \n10) Ordenar autor \n"
                           "11) Alta libro \n12) Modificar libro \n13) Baja libro \n14) Listar libro \n15) Ordenar libro\n"
                           "16) Alta socio\n17)Modificar socio \n18)Baja socio \n19)Listar socio  \n20)Ord socio\n21)Salir\n",                   //cambiar
                            "\nError",1,sizeof(int),1,16,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                fantasma_alta(arrayFantasma,QTY_ARRAY_TIPO,&contadorIdfantasma);                   //cambiar
                break;

            case 2: //Modificar
                fantasma_modificar(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 3: //Baja
                fantasma_baja(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 4://Listar
                fantasma_listar(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 5://Ordenar
                fantasma_ordenarPorDobleCriterio(arrayFantasma,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;
            case 6: //Alta
                autor_alta(arrayAutor,QTY_ARRAY_TIPO,&contadorIdautor);                   //cambiar
                break;

            case 7: //Modificar
                autor_modificar(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 8: //Baja
                autor_baja(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 9://Listar
                autor_listar(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 10://Ordenar
                autor_ordenarPorDobleCriterio(arrayAutor,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;

            case 11: //Alta
                libro_alta(arrayLibro, arrayAutor, QTY_ARRAY_AUTOR, QTY_ARRAY_LIBRO,&contadorIdlibro);                   //cambiar
                break;

            case 12: //Modificar
                libro_modificar(arrayLibro, arrayAutor, QTY_ARRAY_AUTOR, QTY_ARRAY_LIBRO);
                break;

            case 13: //Baja
                libro_baja(arrayLibro,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 14://Listar
                libro_listar(arrayLibro,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 15://Ordenar
                libro_ordenarPorDobleCriterio(arrayLibro,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;

            case 16:
                socio_alta(arraySocio, QTY_ARRAY_SOCIO, &contadorIdSocio, arrayFecha, &contadorIdFecha);
                break;

            case 17:
                socio_modificar(arraySocio, QTY_ARRAY_SOCIO);
                break;

            case 18:
                socio_baja(arraySocio, QTY_ARRAY_SOCIO);
                break;

            case 19:
                socio_listar(arraySocio, QTY_ARRAY_SOCIO);
                break;

            case 20:
                socio_ordenarPorDobleCriterio(arraySocio, QTY_ARRAY_SOCIO, SORT_UP, SORT_UP);
                break;
            case 21://Salir
                break;

            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=21);
    return 0;
}
