#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD_LETRAS 10

/**
    char nombre[257] = {'x','O','L','x','X','\0'}; // Es igual a char nombre[257]="HOLA"
    char nombre2[257]="HOLA";
    /** strncpy(nombre, nombre2, 257) funcion para copiar un string en otro**
    ///NO HACER nombre = "Juan"
    printf("%s", nombre);
    strncpy(nombre, nombre2, sizeof(nombre)); //sizeof informa cuantos bytes ocupa
    printf("%s", nombre);
    fgets(nombre, sizeof(nombre), stdin); //(donde dejo la inf, cual es el tamaño, cual es el string"stdin" es el archivo)
    /** fgets es = scanf("%s", nombre) pero limita el tamaño de  lo que ingresa el usuario*
    printf("%s", nombre);

    ///strlen() mide string
    ///strcmp() compara tamaño de las cadenas
**/

int validarNombre(char *buffer);
int main()
{
    char nombre[CANTIDAD_LETRAS];
    char buffer[CANTIDAD_LETRAS];
    printf("Ingrese su nombre:");
    fgets(buffer, sizeof(buffer), stdin); ///lo ultimo que ingresa es enter"\n"
    if (validarNombre(buffer))
    {
        strncpy(nombre, buffer, sizeof(nombre));
        printf("Su nombre es: %s", nombre);
    }
    else
    {
        printf("Error, el nombre no es valido");
    }
    return 0;
}


int validarNombre(char *buffer)
{
    int i;
    int tamanoBuffer;
    tamanoBuffer=strlen(buffer);
    for(i=0; i<tamanoBuffer-1; i++)
    {
        //if(strcmp(buffer[i]<"A")<0) solo para comparar cadenas
        if(buffer[i]>'Z' && buffer[i]<'a' || buffer[i]<'A' || buffer[i]>'z')
        {
            return 0;
        }
    }
    return 1;
}
