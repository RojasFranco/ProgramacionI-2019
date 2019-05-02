#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

// Validamos int
//devuelve 1 si V o 0 f
//si esto vuelve v, lo devuelvo(la var apuntada por resultado)
int main()
{
    int numeroIngresado;
    getInt("Ingrese el numero", "Error", 0 , 50, 2, &numeroIngresado);
    printf("El numero ingresado es: %d", numeroIngresado);
    return 0;
}

