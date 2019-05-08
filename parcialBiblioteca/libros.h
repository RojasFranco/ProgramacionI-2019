#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

typedef struct
{
    int isEmpty;
    int idLibro;
    char tituloLibro[51];
    int idAutor;
}Libro;

int libro_inicializar(Libro* libros, int len);

#endif // LIBROS_H_INCLUDED
