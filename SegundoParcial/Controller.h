int controller_loadFromText(char* path , LinkedList* pArrayListVenta);
int controller_loadFromBinary(char* path , LinkedList* pArrayListVenta);
int controller_addVenta(LinkedList* pArrayListVenta);
int controller_editVenta(LinkedList* pArrayListVenta);
int controller_removeVenta(LinkedList* pArrayListVenta);
int controller_ListVenta(LinkedList* pArrayListVenta);
int controller_sortVenta(LinkedList* pArrayListVenta);
int controller_saveAsText(char* path , LinkedList* pArrayListVenta);
int controller_saveAsBinary(char* path , LinkedList* pArrayListVenta);
int controller_IdMaximo(LinkedList* pArrayListVenta);
int controller_buscarId(LinkedList* pArrayListVenta, int idBuscado);

int controller_cantidadFotos(LinkedList* pArrayVentas);
