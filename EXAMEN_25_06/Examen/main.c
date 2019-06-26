#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entrega.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include "informe.h"

int main()
{
    LinkedList* listaEntregas = ll_newLinkedList();
    controller_loadFromText("data.csv", listaEntregas);
    //controller_ListEntrega(listaEntregas);
    //controller_saveAsText("PEPE.csv", listaEntregas);
    informe_cantidadTotalEntregas(listaEntregas);
    informe_cantidadPorTipo(listaEntregas);





    return 0;
}
