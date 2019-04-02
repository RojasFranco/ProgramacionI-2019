#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

int calcularSuma(int primerNumero, int segundoNumero, int* suma)
{
    *suma=primerNumero+segundoNumero;
    return 0;
}

int calcularResta(int primerNumero, int segundoNumero, int *resta)
{
    *resta=primerNumero-segundoNumero;
    return 0;
}

int calcularDivision(int primerNumero, int segundoNumero, int *division)
{
    if(segundoNumero==0)
    {
        return -1;
    }
    else
    {
        *division=primerNumero/segundoNumero;
        return 0;
    }
}

int calcularMultiplicacion(int primerNumero, int segundoNumero, int *multiplicacion)
{
    *multiplicacion = primerNumero*segundoNumero;
    return 0;
}

int calcularFactorial(int numero, int *factorialNumero)
{
    int i;
    int factorial=1;
    if (numero<0)
    {
        return -1;
    }
    for (i=1; i<= numero; i+=1)
    {
        factorial*=i;
    }
    *factorialNumero = factorial;
    return 0;
}

