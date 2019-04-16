#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validarApellido.h"

int main()
{
    char apellido[20];
    if(!getApellido("ingresa tu apellido", "ap invalido", 2, 20, 3, apellido))
    {
        printf("su apellido es: %s", apellido);
    }
    else
    {
        printf("Errorrrrr");
    }
    return 0;
}
