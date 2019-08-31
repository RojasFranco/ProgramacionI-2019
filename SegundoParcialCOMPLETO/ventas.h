#ifndef venta_H_INCLUDED
#define venta_H_INCLUDED
typedef struct
{
    int id;
    int dia;
    int mes;
    int anio;

    char tipoFoto[128];
    float precioUnitario;
    int cantidad;

    char cuil[128];
}Venta;

Venta* venta_new();
Venta* venta_newParametros(char* idStr,char* diaStr, char* mesStr, char* anioStr,char* tipoFotoStr,char*cantidadStr, char* precioUnitarioStr, char* cuilStr);
Venta* venta_newParametrosBin(int id, char* tipoFotoStr, float precioUnitario, int cantidad);
void venta_delete(Venta* this);

int venta_setId(Venta* this,int id);
int venta_getId(Venta* this,int* id);
//int venta_setIdStr(Venta* this, char* idStr);

int venta_setTipoFoto(Venta* this,char* tipoFoto);
int venta_getTipoFoto(Venta* this,char* tipoFoto);

int venta_setCantidad(Venta* this,int cantidad);
int venta_getCantidad(Venta* this,int* cantidad);
//int venta_setCantidadStr(Venta* this, char* precioUnitarioStr);

int venta_setPrecioUnitario(Venta* this,float precioUnitario);
int venta_getPrecioUnitario(Venta* this,float* precioUnitario);

int venta_compararPorTipoFoto(void* thisUno, void* thisDos);

int venta_setDia(Venta* this, int dia);
int venta_getDia(Venta* this,int* dia);

int venta_setMes(Venta* this, int mes);
int venta_getMes(Venta* this,int* mes);

int venta_setAnio(Venta* this, int anio);
int venta_getAnio(Venta* this,int* anio);

int venta_setCuil(Venta* this,char* cuil);
int venta_getCuil(Venta* this,char* cuil);

int ventaMayor150(void* pVenta);
int ventaMayor300(void* pVenta);
int ventasTipoPolaroids(void* pVenta);


#endif // venta_H_INCLUDED

