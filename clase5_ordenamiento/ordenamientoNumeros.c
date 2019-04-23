#include <stdio.h>
#include <stdlib.h>
#include "ordenamiento.h"

int ordenarNumeros(int* array, int limite)
{
    int i;
    int flagSwap;
    int auxiliar;
    do
    {
        for (i=0; i<limite-1; i++)
        {
            if (array[i]> array[i+1])
            {
                auxiliar= array[i];
                array[i]= array[i+1];
                array[i+1]=auxiliar;
                flagSwap=1;
            }
            else
            {
                flagSwap=0;
            }
        }

    } while (flagSwap);
    return 0;
}
