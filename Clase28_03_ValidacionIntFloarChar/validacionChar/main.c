#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int isValidChar(letra,minimo,maximo);
int getChar(char *mensaje, char *mensajeError, int reintentos, int minimo, int maximo, char *resultado);
int main()
{
    char letraIngresada;
    getChar("Ingrese letra", "Error letra no valida", 2, 'a', 'f', &letraIngresada);
    printf("La letra ingresada es: %c", letraIngresada);
    return 0;
}
