#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define CANTIDAD_NOTAS 4

int calcularPromedio(void);
int calcularMaximoyMinimo(int nota, int* notaMaxima, int* notaMinima);

int main()
{
    calcularPromedio();
    return 0;
}

int calcularPromedio(void)
{
    int nota;
    int sumaNotas=0;
    int i;
    float promedio;
    int notaMaxima=INT_MIN;
    int notaMinima=INT_MAX;
    for (i=0; i<CANTIDAD_NOTAS; i+=1)
    {
        printf("Ingrese nota: ");
        scanf("%d", &nota);
        sumaNotas+=nota;
        calcularMaximoyMinimo(nota, &notaMaxima, &notaMinima);
    }
    promedio=(float)sumaNotas/CANTIDAD_NOTAS;
    printf("\nEl promedio es: %.2f", promedio);
    printf("\nLa nota maxima es: %d, y la nota minima es %d", notaMaxima, notaMinima);
    return 0;
}
int calcularMaximoyMinimo(int nota, int* notaMaxima, int* notaMinima)
{
    if (nota>*notaMaxima)
    {
        *notaMaxima=nota;
    }
    if (nota<*notaMinima)
    {
        *notaMinima=nota;
    }
    return 0;
}
