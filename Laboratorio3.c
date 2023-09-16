#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estudiante
{
    char nombre[50];
    int numeroLista;
    float promedioFinal;
};

struct Libro
{
    char titulo[100];
    char autor[50];
    char ISBN[14];
    float precio;
};

struct Producto
{
    char nombre[50];
    int ID;
    float precio;
    int cantidad;
};

void agregarProducto(struct Producto productos[], int *numProductos)
{
    if(*numProductos < 50)
        {

            struct Producto nuevoProducto;

            printf("Ingrese el nombre del producto: ");
            scanf("%s", nuevoProducto.nombre);
            printf("Ingrese el ID del producto: ");
            scanf("%d", &nuevoProducto.ID);
            printf("Ingrese el precio del producto: ");
            scanf("%f", &nuevoProducto.precio);
            printf("Ingrese la cantidad en stock del producto: ");
            scanf("%d", &nuevoProducto.cantidad);

            productos[*numProductos] = nuevoProducto;
            (*numProductos)++;

            printf("Producto agregado.\n");

        }else
        {
            printf("No hay espacio para agregar mas productos.\n");
        }
}

void mostrarProductoMayorValor(struct Producto productos[], int numProductos)
{
    if (numProductos > 0)
        {
            int indiceMayorValor = 0;

            for(int i = 1; i < numProductos; i++)
                {
                    if(productos[i].precio > productos[indiceMayorValor].precio)
                    {
                        indiceMayorValor = i;
                    }
                }

            printf("\nProducto de mayor valor:\n");
            printf("Nombre: %s\n", productos[indiceMayorValor].nombre);
            printf("ID: %d\n", productos[indiceMayorValor].ID);
            printf("Precio: %.2f\n", productos[indiceMayorValor].precio);
            printf("Cantidad en stock: %d\n", productos[indiceMayorValor].cantidad);

        }else
        {
            printf("No hay productos para mostrar.\n");
        }
}

void mostrarStockActual(struct Producto productos[], int numProductos)
{
    if (numProductos > 0)
    {
        printf("\nStock actual de productos:\n");
        printf("Nombre\t\tID\tPrecio\tCantidad\n");
        for (int i = 0; i < numProductos; i++)
        {
            printf("%s\t%d\t%.2f\t%d\n", productos[i].nombre, productos[i].ID, productos[i].precio, productos[i].cantidad);
        }
    }else
    {
        printf("No hay productos para mostrar.\n");
    }
}

int main()
{

    struct Estudiante estudiantes[5];
    struct Estudiante estudianteConPromedioMasAlto;
    struct Libro libros[5];
    struct Libro libroConMayorPrecio;
    struct Producto productos[50];
    float promedioMasAlto = 1.0;
    float mayorPrecio = 0;
    int numEstudiantes;
    int numLibros;
    int numProductos = 0;
    int opcion;

    printf("NUMERO DE ESTUDIANTES: ");
    scanf("%d", &numEstudiantes);

    for(int i = 0; i < numEstudiantes; i++)
        {
        printf("\nIngrese los datos del estudiante #%d:\n", i + 1);
        printf("Nombre: ");
        scanf("%s", estudiantes[i].nombre);
        printf("Numero de lista: ");
        scanf("%d", &estudiantes[i].numeroLista);
        printf("Promedio final: ");
        scanf("%f", &estudiantes[i].promedioFinal);

        if(estudiantes[i].promedioFinal > promedioMasAlto)
            {
            promedioMasAlto = estudiantes[i].promedioFinal;
            estudianteConPromedioMasAlto = estudiantes[i];
            }
        }

    printf("\n\nEstudiante con el promedio mas alto:\n");
    printf("Nombre: %s\n", estudianteConPromedioMasAlto.nombre);
    printf("Numero de lista: %d\n", estudianteConPromedioMasAlto.numeroLista);
    printf("Promedio final: %.2f\n", estudianteConPromedioMasAlto.promedioFinal);

    printf("\n\nNUMERO DE LIBROS: ");
    scanf("%d", &numLibros);
    for(int i = 0; i < numLibros; i++)
        {
        printf("\nIngrese los datos del libro %d:\n", i + 1);
        printf("Titulo: ");
        scanf("%s", libros[i].titulo);
        printf("Autor: ");
        scanf("%s", libros[i].autor);
        printf("ISBN: ");
        scanf("%s", libros[i].ISBN);
        printf("Precio: ");
        scanf("%f", &libros[i].precio);

        if(libros[i].precio > mayorPrecio)
            {
            mayorPrecio = libros[i].precio;
            libroConMayorPrecio = libros[i];
            }
        }

    printf("\nLibro con el mayor precio:\n");
    printf("Titulo: %s\n", libroConMayorPrecio.titulo);
    printf("Autor: %s\n", libroConMayorPrecio.autor);
    printf("ISBN: %s\n", libroConMayorPrecio.ISBN);
    printf("Precio: %.0f\n", libroConMayorPrecio.precio);

    do{
        printf("\nMENU DE OPCIONES:\n");
        printf("1. Agregar un producto\n");
        printf("2. Mostrar el producto de mayor valor\n");
        printf("3. Mostrar el stock actual de productos\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion (1-4): ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                agregarProducto(productos, &numProductos);
                break;
            case 2:
                mostrarProductoMayorValor(productos, numProductos);
                break;
            case 3:
                mostrarStockActual(productos, numProductos);
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
        }
    }while (opcion != 4);

    return 0;
}
