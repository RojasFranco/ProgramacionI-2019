#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

int realizarOperaciones(int primerNumero, int segundoNumero, int opcionSeleccionada);
int brindarMenu();
int main()
{

    brindarMenu();
    return 0;
}

int brindarMenu() //int *suma, int *resta, int *multiplicacion, int *division)
{
    int primerNumero;
    int segundoNumero;
    int opcionSeleccionada;
    int primerIngreso=1;
    do
    {
        if (primerIngreso)
        {
            printf("\n1- Ingresar primer operando (A = X)");
            printf("\n2- Ingresar segundo operando (B = Y)");
            primerIngreso=0;
        }
        else
        {
            printf("\n1- Ingresar primer operando (A = %d)", primerNumero);
            printf("\n2- Ingresar segundo operando (B = %d)", segundoNumero);
        }
        printf("\n3- Calcular todas las operaciones");
        printf("\n4- Informar resultados");
        printf("\n5- Salir\n");
        printf("Seleccione la opcion deseada:");
        scanf("%d", &opcionSeleccionada);
        if (opcionSeleccionada==1)
        {
            printf("Ingrese el primer numero:");
            scanf("%d", &primerNumero);
        }
        if (opcionSeleccionada==2)
        {
            printf("Ingrese el segundo numero:");
            scanf("%d", &segundoNumero);
        }
        if (opcionSeleccionada==3 || opcionSeleccionada==4)
        {
            //REALIZAR CUENTAS
            realizarOperaciones(primerNumero, segundoNumero, opcionSeleccionada);
        }
    } while (opcionSeleccionada!=5);
    return 0;

}

int realizarOperaciones(int primerNumero, int segundoNumero, int opcionSeleccionada)
{
    int suma;
    int resta;
    int multiplicacion;
    int division;
    int factorialPrimerNumero;
    int factorialSegundoNumero;
    calcularSuma(primerNumero, segundoNumero, &suma);
    calcularResta(primerNumero, segundoNumero, &resta);
    calcularMultiplicacion(primerNumero, segundoNumero, &multiplicacion);
    calcularDivision(primerNumero, segundoNumero, &division);
    calcularFactorial(primerNumero, &factorialPrimerNumero);
    calcularFactorial(segundoNumero, &factorialSegundoNumero);
    if (opcionSeleccionada==4)
    {
        printf("\nla suma  %d + %d es: %d", primerNumero, segundoNumero, suma);
        printf("\nla resta %d - %d es: %d", primerNumero, segundoNumero, resta);
        printf("\nla multiplicacion %d*%d es: %d", primerNumero, segundoNumero, multiplicacion);
        if (calcularDivision(primerNumero, segundoNumero, &division)==-1)
        {
            printf("\nla division %d/%d es: No es posible dividir por 0", primerNumero, segundoNumero);
        }
        else
        {
            printf("\nla division %d/%d es: %d", primerNumero, segundoNumero, division);
        }
        printf("\nfactorial de %d es: %d y el factorial de %d es: %d\n", primerNumero, factorialPrimerNumero,segundoNumero, factorialSegundoNumero);
    }
    return 0;
}
