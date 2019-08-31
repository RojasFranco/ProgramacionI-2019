#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "ventas.h"
#include "utn.h"

int main()
{
    LinkedList* listaVentas = ll_newLinkedList();

    controller_loadFromText("data.csv", listaVentas);
    controller_ListVenta(listaVentas);
    controller_saveAsText("informes.txt", listaVentas);
    return 0;
}


/// suewldo = precio unitario   CAMBIAR FLOAT
/// horasTrabj = cantidad  QUEDA IGUAL
