#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Comprobamos que solo hay 1 argumento y este es un numero; de lo contrario, devolvemos instrucciones
    if (argc == 2 && isdigit(*argv[1]))
    {
        int k = atoi(argv[1]);
        // obtenemos la clave y la convertimos a entero con atoi

        string texto = get_string("plaintext: ");
        // obtenemos el texto a cifrar

        printf("ciphertext: ");
        // imprimimos el texto cifrado

        for (int i = 0, n = strlen(texto); i < n; i++)
            // para cada letra que sea alfanumerica, la ciframos
        {
            if (isalpha(texto[i]))
                // y decimos, si es una letra, entonces esta se cifra
            {
                if (isupper(texto[i]))
                    // si es mayuscula, entonces se cifra con la formula
                {
                    printf("%c", (((texto[i] - 65) + k) % 26) + 65);
                }
                else
                    // si es minuscula, entonces ocupamos la formula
                {
                    printf("%c", (((texto[i] - 97) + k) % 26) + 97);
                }
            }
            else
                // pero, si no es una letra, entonces se imprime tal cual esta
            {
                printf("%c", texto[i]);
                // imprimimos el caracter tal cual
            }
        }
        printf("\n");
        // imprimimos un salto de linea para que el texto cifrado quede en una linea aparte
    }
    else
    {
        printf("Usage: ./caesar key (key must be a number)\n");
        // si no se cumple la condicion, se imprime el mensaje de error y se termina el programa
        return 1;
    }

}

// @author: @Meitchouk (GitHub)
// Programa que cifra un texto con el algoritmo de Cesar usando la clave que el usuario ingrese
