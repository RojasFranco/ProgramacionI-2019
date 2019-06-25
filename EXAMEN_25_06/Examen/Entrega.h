#ifndef entrega_H_INCLUDED
#define entrega_H_INCLUDED
typedef struct
{
    int id;
    char tipo[128];
    int cantidad;
    float importe;
}Entrega;

Entrega* entrega_new();
Entrega* entrega_newParametros(char* idStr,char* tipoStr,char* cantidadStr, char*importeStr);
Entrega* entrega_newParametrosBin(int id, char* tipoStr, int cantidad, int importe);
void entrega_delete(Entrega* this);

int entrega_setId(Entrega* this,int id);
int entrega_getId(Entrega* this,int* id);
//int entrega_setIdStr(Entrega* this, char* idStr);

int entrega_setTipo(Entrega* this,char* tipo);
int entrega_getTipo(Entrega* this,char* tipo);

int entrega_setCantidad(Entrega* this,int cantidad);
int entrega_getCantidad(Entrega* this,int* cantidad);
//int entrega_setCantidadStr(Entrega* this, char* cantidadStr);

int entrega_setImporte(Entrega* this,int importe);
int entrega_getImporte(Entrega* this,int* importe);
int entrega_compararPorTipo(void* thisUno, void* thisDos);

#endif // entrega_H_INCLUDED
