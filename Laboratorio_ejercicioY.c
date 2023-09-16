#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int entero = 10;
    int edad, anio;
    int numeros[5];
    float flotante = 3.14;
    float num1, num2;
    double doble = 2.71828;
    char caracter = 'A';
    char nombre[50];
    _Bool booleano = 1;
    srand(time(NULL));

    // TIPOS DE DATOS
    printf("Entero: %d\n", entero);
    printf("Flotante: %f\n", flotante);
    printf("Doble: %lf\n", doble);
    printf("Caracter: %c\n", caracter);
    printf("Booleano: %d\n", booleano);

    //OPERACIONES
    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);
    printf("Suma: %.0f\n", num1 + num2);
    printf("Resta: %.0f\n", num1 - num2);
    printf("Multiplicacion: %.0f\n", num1 * num2);
    if (num2 != 0) {
        printf("Division: %.1f\n", num1 / num2);
    } else {
        printf("No se puede dividir entre cero.\n");
    }

    //TEXTOS
    printf("\nIngrese su nombre: ");
    scanf("%s", nombre);
    printf("\nIngrese su edad: ");
    scanf("%d", &edad);
    printf("Hola %s, usted tiene %d anios de edad.\n", nombre, edad);

    // AÑO BISIESTO
    printf("\nIngrese un anio: ");
    scanf("%d", &anio);
    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) {
        printf("%d es un anio bisiesto.\n", anio);
    } else {
        printf("%d no es un anio bisiesto.\n", anio);
    }

    //ARREGLO DE NUMEROS ASCENDENTE Y DESCENDENTE

    for (int i = 0; i < 5; i++) {
        numeros[i] = rand() % 100;
    }
    printf("\nNumeros generados:\n -Ascendente ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n -Descendentes ");
    for (int i = 5; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
