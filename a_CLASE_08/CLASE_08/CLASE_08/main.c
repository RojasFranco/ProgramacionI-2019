#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define ELEMENTOS 5

int main()
{
    char arrayNombres[ELEMENTOS][50];

    strncpy(arrayNombres[0],"JUAN",50);

    strncpy(arrayNombres[1],"LUCAS",50);

    strncpy(arrayNombres[2],"CAMILA",50);


    printArrayString(arrayNombres,ELEMENTOS);
    //getName("Ingrese un nombre: ","ERROR: ",2,10,5,auxName);

    /*
    if(getName("Nombre?: ","Error",2,5,2,auxName) == 0)
    {
        printf("OK: %s",auxName);
    }
    else
    {
        printf("ERROR: %s",auxName);
    }
    */
    return 0;
}
