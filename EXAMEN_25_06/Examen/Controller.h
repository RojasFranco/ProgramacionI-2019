int controller_loadFromText(char* path , LinkedList* pArrayListEntrega);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEntrega);
int controller_addEntrega(LinkedList* pArrayListEntrega);
int controller_editEntrega(LinkedList* pArrayListEntrega);
int controller_removeEntrega(LinkedList* pArrayListEntrega);
int controller_ListEntrega(LinkedList* pArrayListEntrega);
int controller_sortEntrega(LinkedList* pArrayListEntrega);
int controller_saveAsText(char* path , LinkedList* pArrayListEntrega);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEntrega);
int controller_IdMaximo(LinkedList* pArrayListEntrega);
int controller_buscarId(LinkedList* pArrayListEntrega, int idBuscado);

