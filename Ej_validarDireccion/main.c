#include <stdio.h>
#include <stdlib.h>
#include "getDireccion.h"

int main()
{
    char bufferDireccion[4096];
    if(!getDireccion("ing direccion", "dir invalida", 4, 50, 2, bufferDireccion))
    {
        printf("direccion:%s", bufferDireccion);
    }
    return 0;
}
