#include <stdio.h>
#include <stdlib.h>
#define CANTIDADNOTAS 3

int calcularNotaMaximayMinima(int nota, int* notaMaxima, int* notaMinima);
int calcularPromedio(void);
int main()
{
    calcularPromedio();
    return 0;
}

int calcularPromedio(void)
{
    int i=0;
    int nota;
    int sumaNotas=0;
    float promedio;
    int notaMaxima;
    int notaMinima;
    int primeraVez=1;
    for(i;i<CANTIDADNOTAS;i++)
    {
        printf("Ingrese nota:");
        scanf("%d", &nota);
        sumaNotas+=nota;
        if (primeraVez)
        {
            notaMaxima=nota;
            notaMinima=nota;
            primeraVez=0;
        }
        else
        {
            calcularNotaMaximayMinima(nota,&notaMaxima, &notaMinima);
        }
    }
    promedio=(float)sumaNotas/CANTIDADNOTAS;
    printf("El promedio es %.2f, la nota maxima: %d, y la minima:%d", promedio, notaMaxima, notaMinima);
    return 0;
}

int calcularNotaMaximayMinima(int nota, int* notaMaxima, int* notaMinima)
{

    if(nota<*notaMinima)
    {
        *notaMinima=nota;
    }
    if(nota>*notaMaxima)
    {
        *notaMaxima=nota;
    }
    return 0;
}
