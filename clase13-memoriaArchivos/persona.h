#ifndef EMPLEADO_H
#define EMPLEADO_H
typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    int estado;
}Persona;
#endif

Persona* persona_new(void); ///crea persona vacia
Persona* persona_newStr(char* id, char* nombre, char* apellido, char* estado); ///crea persona con datos
int persona_delete(Persona* this);

int persona_setId(Persona* this, int id);
int persona_getId(Persona* this, int* resultado);
int persona_setApellido(Persona* this, char* apellido);
int persona_getApellido(Persona* this, char* resultado);
int persona_setNombre(Persona* this, char* nombre);
int persona_getNombre(Persona* this, char* resultado);
int persona_setEstado(Persona* this, int estado);
int persona_getEstado(Persona* this, int* resultado);




