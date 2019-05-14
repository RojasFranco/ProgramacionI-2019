#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    int dia;
    int mes;
    int anio;

}Fecha;


#endif // FECHA_H_INCLUDED

int fecha_Inicializar(Fecha array[], int size);                                    //cambiar fecha
int fecha_buscarEmpty(Fecha array[], int size, int* posicion);                    //cambiar fecha
int fecha_buscarID(Fecha array[], int size, int valorBuscado, int* posicion);                    //cambiar fecha
int fecha_buscarInt(Fecha array[], int size, int valorBuscado, int* posicion);                    //cambiar fecha
int fecha_buscarString(Fecha array[], int size, char* valorBuscado, int* indice);                    //cambiar fecha
int fecha_alta(Fecha array[], int size, int* contadorID);                          //cambiar fecha
int fecha_baja(Fecha array[], int sizeArray);                                      //cambiar fecha
int fecha_bajaValorRepetidoInt(Fecha array[], int sizeArray, int valorBuscado);
int fecha_modificar(Fecha array[], int sizeArray);                                //cambiar fecha
int fecha_ordenarPorDobleCriterio(Fecha array[],int size, int orderFirst, int orderSecond);                                  //cambiar fecha
int fecha_listar(Fecha array[], int size);
