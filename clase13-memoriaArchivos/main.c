#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

int main()
{
    char bufferStr[4096];
    FILE *pFileBkp = NULL;
    FILE *pFile = NULL;
    pFile = fopen("data.csv", "r");
    pFileBkp = fopen("data_bkp.csv", "w");
    if(pFile!=NULL && pFileBkp!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%s", bufferStr);
            fprintf(pFileBkp,"%s\n", bufferStr);
        }
        fclose(pFile);
        fclose(pFileBkp);
    }


    Persona *pArrayPersona[1000];
    int ultimoElementoArraypersonaleado = 0;
    int indiceActual;
    int auxInt;
    char auxNombre[50];
    char auxApellido[50];
    int auxEstado;

    indiceActual = ultimoElementoArraypersonaleado;
    pArrayPersona[indiceActual] =  persona_new();


    if(pArrayPersona[indiceActual] != NULL)
    {
        ultimoElementoArraypersonaleado++;
        printf("OK");
        if(!persona_setId(pArrayPersona[indiceActual],14))
        {
            persona_getId(pArrayPersona[indiceActual], &auxInt);
            printf("\nEl id es %d",auxInt);

        }

        if(!persona_setApellido(pArrayPersona[indiceActual], "Ruiz"))
        {
            persona_getApellido(pArrayPersona[indiceActual], auxApellido);
            printf("\nApellido: %s", auxApellido);
        }

        if(!persona_setNombre(pArrayPersona[indiceActual], "pepe"))
        {
            persona_getNombre(pArrayPersona[indiceActual], auxNombre);
            printf("\nNombre: %s", auxNombre);
        }

        if(!persona_setEstado(pArrayPersona[indiceActual], 1))
        {
            persona_getEstado(pArrayPersona[indiceActual], &auxEstado);
            printf("\nEstado: %d", auxEstado);

        }
    }

    Persona auxEmp;
    Persona *paraComparar;
    paraComparar = &auxEmp;
    strcpy(auxEmp.nombre,"zz");
    persona_compararNombres(pArrayPersona[0], paraComparar);

    Persona auxpersona;
  //  Persona *paraComparar;
    paraComparar = &auxpersona;
    strcpy(auxpersona.nombre,"zz");
    persona_compararNombres(pArrayPersona[0], paraComparar);

    return 0;
}
