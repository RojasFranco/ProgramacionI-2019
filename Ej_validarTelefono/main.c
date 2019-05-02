#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validarTelefono.h"

int main()
{
    int telefono;
    if(!getTelefono("Ingresa tu telefono", "nro invalido", 2, 5, 2, &telefono))
    {
        printf("telefono: %d", telefono);
    }
    else
    {
        printf("error en tu telefono");
    }
    return 0;
}
