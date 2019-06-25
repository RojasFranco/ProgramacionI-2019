#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entrega.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

int main()
{
    LinkedList* listaEntregas;
    controller_loadFromText("data.csv", "r");
    controller_ListEntrega(listaEntregas);
    //controller_saveAsText("PEPE.csv", listaEntregas);






    return 0;
}
