#include <stdio.h>
#include <stdlib.h>
#define LIMITE 3

/*array[3] = {1,8,4} para definir un array y poder probarlo*/
int main()
{
    ordenarNumeros();
    return 0;
}

int ordenarNumeros(int* array, int LIMITE)
{
    /*esto deberia ir con lo anterior*/
    int i;
    int flagSwap;
    int auxiliar;
    do
    {
        for (i=0; i<LIMITE-1; i++)
        {
            flagSwap=0;
            if (array[i]> array[i+1])
            {
                auxiliar= array[i];
                array[i]= array[i+1];
                array[i+1]=auxiliar;
                flagSwap=1;
            }
        }

    } while (flagSwap);
}

void printArrayInt(int* arrayResultado, int limite)
{
    int i;
    for(i=0; i<limite; i++)
    {
        printf("%d\n", arrayResultado[i]);
    }
}
