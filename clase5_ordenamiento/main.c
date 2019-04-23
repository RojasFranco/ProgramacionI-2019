#include <stdio.h>
#include <stdlib.h>
#include "ordenamiento.h"

/*array[3] = {1,8,4} para definir un array y poder probarlo*/
int main()
{
    int array[3] = {1,8,4};
    printArrayInt(array, 3);
    ordenarNumeros(array, 3);
    printArrayInt(array, 3);
    return 0;
}

void printArrayInt(int* arrayResultado, int limite)
{
    int i;
    for(i=0; i<limite; i++)
    {
        printf("%d\n", arrayResultado[i]);
    }
}
