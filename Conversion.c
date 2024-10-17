#include <stdio.h>

// Funcion decimal a binario
void binario(int num) {
    int bin[32], i = 0,  j=0;
    if (num == 0) {
        printf("Binario: 00");
        return;
    }
    while (num > 0) {
        bin[i] = num % 2;
        num = num / 2;
        i++;
    }
    printf("Binario: 0");
    for (j = i - 1; j >= 0; j--)
        printf("%d", bin[j]);
}

// Funcion decimal a hexadecimal
void hexadecimal(int num) {
    char hex[32];
    int i = 0, j;
    if (num == 0) {
        printf("Exadecimal: 00");
        return;
    }
    while (num > 0) {
        int temp = num % 16;
        if (temp < 10)
            hex[i] = temp + 48;  // Números del 0 al 9
        else
            hex[i] = temp + 55;  // Letras de A a F
        i++;
        num = num / 16;
    }
    printf("Exadecimal: 0");
    for (j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
}

int main() {
    int a[15], i, j, k, n = 15;
    int validInput;
    int repetidos[15] = {0}; 

    printf("Digite 15 numeros naturales entre 20 y 1024:\n");
    
    // Leer el arreglo
    for (i = 0; i < n; i++) {
        do {
            printf("Ingrese un numero (Posicion %d): ", i + 1);
            validInput = scanf("%d", &a[i]);

            // Verificar si la entrada es válida y si está en el rango
            if (validInput != 1 || a[i] < 20 || a[i] > 1024) {
                printf("\nNo se encuentra en el intervalo o ha ingresado un valor no entero. \nDebe ser un numero entero entre 20 y 1024.\n");

                // Limpiar el buffer de entrada
                while(getchar() != '\n');
            }
        } while (validInput != 1 || a[i] < 20 || a[i] > 1024);
    }

    // Marcar los repetidos
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] == a[j] && repetidos[j] == 0) {
                repetidos[j] = 1; 
                a[j] = 0;         
            }
        }
    }

    // Mostrar y aplicar funciones
    for (i = 0; i < n; i++) {
        if (a[i] == 0) {
            printf("Posicion %d: 0\n", i);
        } else {
            printf("Posicion %d: %d - ", i, a[i]);
            if (a[i] % 2 == 0) {
                binario(a[i]); // Números pares a binario
            } else {
                hexadecimal(a[i]); // Números impares a hexadecimal
            }
            printf("\n");
        }
    }

    return 0;  
}

