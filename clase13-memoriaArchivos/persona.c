#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include <string.h>

Persona* persona_new(void)
{
    return (Persona*) malloc(sizeof(Persona));
}

Persona* persona_newStr(char* id, char* nombre, char* apellido, char* estado)
{
    Persona* retorno=NULL; ///si no puedo completar algun dato devuelvo NULL
    Persona* pAuxPersona;
    if( id!=NULL & nombre!=NULL && apellido!=NULL && estado!=NULL)
    {
        pAuxPersona = persona_new();
        if(pAuxPersona!=NULL)
        {
            if( !persona_setNombre(pAuxPersona, nombre) &&
                !persona_setApellido(pAuxPersona, apellido) &&
                !persona_setIdString(pAuxPersona, id) &&
                !persona_setEstadoStr(pAuxPersona, estado))
            {
                retorno = pAuxPersona;
            }
            else
            {
                persona_delete(pAuxPersona);
            }
        }
    }
}




int persona_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int persona_setIdString(Persona* this, char* id)
{
    int retorno=-1;
    if( this!=NULL && id!=NULL && isValidNumber(id)) ///isValid devuelve 1 o 0
    {
        //this->id = atoi(id); Puede ser un id negativo
        retorno = persona_setId(this, atoi(id));
    }
    return retorno;
}


int persona_setId(Persona* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int persona_getId(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}


int persona_getStringId(Persona* this, char* resultado)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && resultado != NULL)
    {
        persona_getId(this, bufferInt);
        sprintf(resultado, "%d", bufferInt); ///sprintf(donde, mascara, que)
        retorno = 0;
    }
    return retorno;
}

int persona_setApellido(Persona* this, char* apellido)
{
    int retorno=-1;
    if(this != NULL && apellido!=NULL)
    {
        strncpy(this->apellido, apellido, sizeof(apellido));
        retorno=0;

    }
    return retorno;
}


int persona_getApellido(Persona* this, char* resultado)
{
    int retorno=-1;
    if(this!=NULL && resultado!=NULL)
    {
        strncpy(resultado, this->apellido, sizeof(this->apellido));
        retorno=0;
    }
    return retorno;

}


int persona_setNombre(Persona* this, char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strncpy(this->nombre, nombre, sizeof(nombre));
        retorno=0;
    }
    return retorno;
}

int persona_getNombre(Persona* this, char* resultado)
{
    int retorno=-1;
    if(this!=NULL && resultado!=NULL)
    {
        strncpy(resultado, this->nombre, sizeof(this->nombre));
        retorno=0;
    }
    return retorno;
}


int persona_setEstado(Persona* this, int estado)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->estado = estado;
        retorno=0;
    }
    return retorno;
}



int persona_getEstado(Persona* this, int* resultado)
{
    int retorno=-1;
    if(this!=NULL && resultado!=NULL)
    {
        *resultado=this->estado;
        retorno=0;
    }
    return retorno;
}


int persona_compararNombres(Persona* this, Persona* otroPersona)
{
    int retorno=-1;
    if(this!=NULL && otroPersona!=NULL)
    {
        if(strcmp(this->nombre, otroPersona->nombre)<0)
        {
            printf("\n%s es menor que %s", this->nombre, otroPersona->nombre);
        }
        else
        {
            printf("\n%s es menor que %s", otroPersona->nombre, this->nombre);
        }
        retorno=0;
    }

    return retorno;
}
