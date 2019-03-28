#include <stdio.h>
#include <stdlib.h>

int getInt(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, int *resultado);
int isValidInt(int numero, int minimo, int maximo);
// Validamos int
//devuelve 1 si V o 0 f
//si esto vuelve v, lo devuelvo(la var apuntada por resultado)
int main()
{
    int numeroIngresado;
    int errorDeIngreso;
    errorDeIngreso = getInt("Ingrese el numero", "Error", 0 , 50, 2, &numeroIngresado);
    if (errorDeIngreso)
    {
        printf("Se ha ingresado algo invalido");
    }
    else
    {
        printf("El numero ingresado es: %d", numeroIngresado);
    }
    return 0;
}

int isValidInt(int numero, int minimo, int maximo)
{
    if (numero<=maximo && numero>=minimo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int getInt(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, int *resultado)
{
    int buffer; // aca guardo lo que ingresa user
    int i=0;
    int retorno=-1;
    if(mensaje != NULL && mensajeError != NULL && resultado!= NULL && reintentos>=0 && maximo>=minimo)
    {
        for (i=0; i<=reintentos; i+=1);
        {
            printf("%s", mensaje); // para imprimir el mensaje
            scanf("%d", buffer);
            if (isValidInt(buffer, minimo, maximo))
            {
                *resultado = buffer;
                return retorno;
                break; // para no seguir iterando
            }
            else
            {
                printf("%s", mensajeError)
            }
        }
        retorno = 0; //para cambiar el retorno
    }
}
