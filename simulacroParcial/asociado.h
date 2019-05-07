#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED

typedef struct
{
    int estado; ///vacio, lleno, inhabilitado
    int idAsociado;
    char nombre[20];
    char apellido[20];
    char dni[20];
    int edad;
}Asociado;


int asoc_inicializar(Asociado* asociados, int len);

int asoc_mostrar(Asociado* asociados, int len);


int asoc_buscarLibre(Asociado* asociados, int len);


int asoc_alta(Asociado *asociados, int len, int posicion);

int asoc_buscarPorId(Asociado *asociados, int len);

int asoc_modificar(Asociado *asociados, int len, int posicion);


static int asoc_generarId(void);

#endif // ASOCIADO_H_INCLUDED
