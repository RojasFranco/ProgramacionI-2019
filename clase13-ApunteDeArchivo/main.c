#include <stdio.h>
#include <stdlib.h>

int main()
{
//stdin y stdout para archivos

///   *********  LECTURA *******************

    char bufferStr[4096];

    FILE *pFile = NULL; ///lo inicializo
    pFile = fopen("data.csv", "r"); ///fopen(direccion, modo de lectura(lect,escrit,append). si no lo abre devuelve null

    if(pFile!=NULL)
    {
        ///feof(pFile) devuelve v cuando termino de leer el archivo.
        while(!feof(pFile))
        {
            fscanf(pFile, "%s", bufferStr); ///fscanf es scanf de archivos. Lee hasta \n.
            printf("%s\n", bufferStr);
        }
        fclose(pFile);
    }


///   *********  ESCRITURA(con lectura) *******************
    FILE *pFileBkp = NULL;
    pFileBkp = fopen("data_bkp.csv", "w");
    if(pFile!=NULL && pFileBkp!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%s", bufferStr);
            fprintf(pFileBkp,"%s\n", bufferStr);
        }
        fclose(pFile);
        fclose(pFileBkp);
    }


///   ********* LECTURA con delimitadores *******************


    char bufferId[4096];
    char bufferNombre[4096];
    char bufferApellido[4096];
    char bufferEstado[4096];
    FILE *pFile = NULL;
    FILE *pFileBkp = NULL;
    pFile = fopen("data.csv", "r"); ///data.csv --- id,nombfre,apellido,estado\n
    pFileBkp = fopen("data_bkp.csv", "w");
    if(pFile!=NULL && pFileBkp!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],[^\n]\n", bufferId, bufferNombre, bufferApellido, bufferEstado);
            printf("%s\n", bufferApellido);
        }
        fclose(pFile);
        fclose(pFileBkp);
    }




    return 0;
}

