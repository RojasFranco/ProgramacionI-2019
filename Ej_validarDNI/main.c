#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validarDNI.h"

int main()
{
    int* numeroDni;
    if (!getDNI("Ingrese DNI","DNI invalido",0,0,2,&numeroDni))
    {
        printf("Su dni es: %d", numeroDni);
    }
    else
    {
        printf("Error al ingresar dni");
    }
    return 0;
}
