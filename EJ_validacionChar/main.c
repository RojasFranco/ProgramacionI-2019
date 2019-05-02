#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char* letraIngresada;
    if(!getChar("Ingrese letra:", "err", 2, 'a', 'f', &letraIngresada))
    {
        printf("Letra ingresada: %c", letraIngresada);
    }
    return 0;
}
