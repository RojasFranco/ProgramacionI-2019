#define TRUE 1
#define FALSE 0

int getString ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);
//-------------------------------------

int getName (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);


int isValidName (char* cadena);

int getDireccion(char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);

int isValidDireccion(char* resultado);
int getNumero(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, int* resultado);
int esValidoNumero(char* cadena);
int isValidChar(letra,minimo,maximo);
int getChar(char *mensaje, char *mensajeError, int reintentos, int minimo, int maximo, char* resultado);



