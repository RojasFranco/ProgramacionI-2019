#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

typedef struct
{
    int estado;
    int idLlamada;
    int idAmbulancia;
    int idAsociado;
    char motivo[20];
    int tiempo;
}Llamada;


#endif // LLAMADA_H_INCLUDED
