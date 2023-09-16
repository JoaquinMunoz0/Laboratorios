#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Par(int num)
{
    if(num % 2 == 0)
    {
        return 1; // Es Par
    }
    else
    {
        return 0; // No Es Par
    }

}

int Primo(int num)
{
    if(num <= 1)
    {
        return 0; // No Es Primo
    }
    for(int i = 2; i * i <= num; i++)
    {
        if(num % i == 0)
        {
            return 0; // No Es Primo Porque tiene un divisor diferente de 1
        }
    }
}

void StatsEnteros(int Enteros[], int Longitud, float *Promedio, int *Maximo, int *Minimo)
{
    int suma = 0;
    *Maximo = Enteros[0];
    *Minimo = Enteros[0];
    for(int i = 0; i < Longitud; i++)
    {
        suma += Enteros[i];
        if(Enteros[i] > *Maximo)
        {
            *Maximo = Enteros[i];
        }
        if(Enteros[i] < *Minimo)
        {
            *Minimo = Enteros[i];
        }
    }
    *Promedio = (float)suma / Longitud;
}

int BuscarIndice(int Numeros[], int Longitud, int Valor) {
    for (int i = 0; i < Longitud; i++) {
        if (Numeros[i] == Valor) {
            return i;  // Devolver el índice si se encuentra el valor
        }
    }
    return -1;  // Devolver -1 si no se encuentra el valor en el arreglo
}

int eliminarDuplicados(int Numeros[], int longitud) {
    if (longitud <= 1) {
        return longitud;  // No hay duplicados que eliminar en arreglos de tamaño 1 o menor
    }

    int nuevoTamano = 1;  // El primer elemento se mantiene
    for (int i = 1; i < longitud; i++) {
        int esDuplicado = 0;  // Flag para indicar si el valor en Numeros[i] es un duplicado

        // Comprobar si Numeros[i] ya está presente en las posiciones anteriores
        for (int j = 0; j < nuevoTamano; j++) {
            if (Numeros[i] == Numeros[j]) {
                esDuplicado = 1;
                break;
            }
        }

        // Si no es un duplicado, copiarlo a la posición correspondiente en el nuevo arreglo
        if (!esDuplicado) {
            Numeros[nuevoTamano] = Numeros[i];
            nuevoTamano++;
        }
    }

    return nuevoTamano;
}

int main()
{
    int num, Maximo, Minimo;
    int Enteros[5];
    int Numeros[5];
    int longitudActual = 5;
    float Promedio;

    // NUMERO PAR O IMPAR

    printf("NUMERO PAR O IMPAR\n\nIngrese un numero: ");
    scanf("%d", &num);
    if(Par(num))
    {
        printf("%d es un numero par\n", num);
    }
    else
    {
        printf("%d es un numero impar\n", num);
    }

    printf("\nIngrese un numero: ");
    scanf("%d", &num);
    if(Par(num))
    {
        printf("%d es un numero par\n", num);
    }
    else
    {
        printf("%d es un numero impar\n", num);
    }

    // NUMERO PRIMO O NO PRIMO

    printf("\nNUMERO PRIMO O NO PRIMO\n\nIngrese un numero: ");
    scanf("%d", &num);
    if(Primo(num))
    {
        printf("%d es un numero primo\n", num);
    }
    else
    {
        printf("%d no es un numero primo\n", num);
    }

    printf("\nIngrese un numero: ");
    scanf("%d", &num);
    if(Primo(num))
    {
        printf("%d es un numero primo\n", num);
    }
    else
    {
        printf("%d no es un numero primo\n", num);
    }

    // PROMEDIO, VALOR MAXIMO Y VALOR MINIMO

    printf("\nPROMEDIO, VALOR MAXIMO Y VALOR MINIMO\n\nIngrese 5 numeros:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("\nNumero %d: ", i + 1);
        scanf("%d",&Enteros[i]);
    }
    StatsEnteros(Enteros, 5,&Promedio, &Maximo, &Minimo);

    printf("\nPromedio: %.2f\n", Promedio);
    printf("\nValor Maximo: %d\n", Maximo);
    printf("\nValor Minimo: %d\n", Minimo);

    // BUSCAR EL INDICE Y ELIMINAR DUPLICADOS

    printf("\nBUSCAR EL INDICE Y ELIMINAR DUPLICADOS\n\nIngrese 5 numeros:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("\nNumero %d: ", i + 1);
        scanf("%d",&Numeros[i]);
    }

    int Longitud = sizeof(Numeros) / sizeof(Numeros[5]);
    int BuscarValor = 5;
    int indice = BuscarIndice(Numeros,Longitud,BuscarValor);

    if (indice != -1)
    {
        printf("\nEl Indice %d se encuentra en el arreglo %d.\n", BuscarValor, indice + 1);
    }
    else
    {
        printf("\nEl Indice %d no se encuentra en el arreglo.\n", BuscarValor);
    }

    int nuevoTamano = eliminarDuplicados(Numeros, longitudActual);

    printf("\nArreglo sin duplicados: ");
    for (int i = 0; i < nuevoTamano; i++) {
        printf("%d ", Numeros[i]);
    }
    printf("\nNuevo tamano: %d\n", nuevoTamano);



    return 0;
}
