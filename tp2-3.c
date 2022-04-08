#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANO_TIPOS 5

typedef struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         // El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
} Cliente;

void IngresarCliente(Cliente *cliente);
void MostrarClientes(Cliente *cliente, int CantidadClientes);
void IngresarProductos(Cliente *Cliente, int CantidadProductosAPedir, char* TiposProductos[], int TiposTamano);
float CostoTotal(Producto Producto);

int main()
{
    int CantidadClientes;
    Cliente *Clientes;
    Cliente* Cabecera;
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};    

    srand(time(NULL));

    printf("Ingrese la cantidad de clientes\n");
    scanf("%i", &CantidadClientes);
    
    Clientes = (Cliente *) malloc(CantidadClientes * sizeof(Cliente));
    Cabecera = Clientes;

    for (unsigned int i = 0; i < CantidadClientes; i++)
    {
        IngresarCliente(Clientes);
        Clientes->CantidadProductosAPedir = rand() % 5 + 1;
        Clientes->Productos = (Producto *) malloc(Clientes->CantidadProductosAPedir * sizeof(Producto));        
        IngresarProductos(Clientes, Clientes->CantidadProductosAPedir, TiposProductos, TAMANO_TIPOS);
        Clientes++;
    }

    MostrarClientes(Cabecera, CantidadClientes);

    free(Clientes);
    return 0;
}

void IngresarCliente(Cliente *cliente)
{
    char *Buffer = (char *) malloc(100 * sizeof(char));
    printf("Ingrese el ID\n");
    scanf("%i", &cliente->ClienteID);

    getchar(); // Evita que se tome el espacio como entrada

    printf("Ingrese el nombre del cliente\n");
    gets(Buffer);
    
    cliente->NombreCliente = (char *) malloc((strlen(Buffer) + 1) * sizeof(char));
    strcpy(cliente->NombreCliente, Buffer);
}

void MostrarClientes(Cliente *Cliente, int CantidadClientes)
{
    float temporal = 0;

    for (unsigned int i = 0; i < CantidadClientes; i++)
    {
        printf("--- Cliente %i ---", i);
        printf("\nID: %i\n", Cliente->ClienteID);
        printf("Nombre de cliente: %s\n", Cliente->NombreCliente);
        printf("Cantidad de productos pedidos: %i\n", Cliente->CantidadProductosAPedir);
        printf("Productos:\n");

        for (unsigned int i = 0; i < Cliente->CantidadProductosAPedir; i++)
        {
            printf("ID: %i\n", Cliente->Productos[i].ProductoID);
            printf("Precio: %.2f\n", Cliente->Productos[i].PrecioUnitario);
            printf("Tipo: %s\n", Cliente->Productos[i].TipoProducto);
            printf("Cantidad: %i\n", Cliente->Productos[i].Cantidad);    
            temporal += CostoTotal(Cliente->Productos[i]);
        }
        
        printf("Total: %.2f\n", temporal);
        printf("\n");
        Cliente++;
    }
}

void IngresarProductos(Cliente *Cliente, int CantidadProductosAPedir, char* TiposProductos[], int TiposTamano)
{            
    for (int i = 0; i < CantidadProductosAPedir; i++)
    {
        Cliente->Productos[i].ProductoID = i;
        Cliente->Productos[i].Cantidad = rand() % 10 + 1;        
        Cliente->Productos[i].TipoProducto = TiposProductos[rand() % TiposTamano];
        Cliente->Productos[i].PrecioUnitario = rand() % 91 + 10;        
    }        
}

float CostoTotal(Producto Producto){
    return Producto.Cantidad * Producto.PrecioUnitario;
}