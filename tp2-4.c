#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANO 10

int main()
{
    char* Buff = (char *)malloc(100 * sizeof(char));
    char** Nombres;
    int Cantidad;

    printf("Ingrese la cantidada de nombres que se introduciran\n");
    scanf("%i", &Cantidad);
    getchar();

    Nombres = (char**) malloc(Cantidad * sizeof(char*));

    for (unsigned int i = 0; i < Cantidad; i++)
    {
        printf("Ingrese el nombre %i \n", i);
        gets(Buff);        

        Nombres[i] = (char *) malloc((strlen(Buff) + 1) * sizeof(char));        

        strcpy(Nombres[i], Buff);
         
    }

    for (unsigned int i = 0; i < Cantidad; i++)
    {        
        printf("%s \n", Nombres[i]);
    }

    for(unsigned int i = 0; i < Cantidad; i++){
        free(Nombres[i]);        
    }

    free(Buff);       
    return 0;
}