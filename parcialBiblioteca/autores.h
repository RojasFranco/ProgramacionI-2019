#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

typedef struct
{
    int idAutor;
    char nombre[31];
    char apellido[31];
    int isEmpty;
}Autor;

int autores_inicializar(Autor* autores, int len);
int autores_encontrarLibre(Autor* autores, int len);
int autores_alta(Autor* autores, int posicion);
int autores_mostrarAutores(Autor* autores, int len);
int autores_getById(Autor* autores, int len);
int autores_modificar(Autor* autores, int posicionID);
static int autores_generarId(void);



#endif // AUTORES_H_INCLUDED
