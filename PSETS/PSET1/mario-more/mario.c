#include <stdio.h> // incluimos la libreria stdio.h para poder hacer uso de printf y scanf
#include <cs50.h>  // incluimos la libreria cs50.h para poder hacer uso del get_int

int main(void)
{
    // en este caso no utilice las variables en ingles para no confundirlas, pero si quieren pueden cambiarlas a ingles si se les hace mas comodo
    int altura, espacios, numerales, filas, nivel;
    // declaramos las variables que vamos a utilizar en el programa

    do
        // hacemos un do while para validar que el usuario no ingrese un numero menor a 1 o mayor a 8
    {
        altura = get_int("Ingrese la altura deseada (valores enteros mayores a 0 y menores a 9): \n");
    }
    while (altura <= 0 || altura >= 9);
    // Mientras que la altura sea menor o igual a 0 o mayor o igual a 9, se volvera a solicitar la altura

    for (filas = 0; filas < altura; filas++)
        // si la variable filas es = a 0, y filas es menor a la altura ingresada por el usuario, entonces se ejecuta el bucle for
    {
        for (espacios = altura - filas; espacios > 1; espacios--)
            // si la variable espacios es mayor a 1, entonces se imprime un espacio en blanco
        {
            printf(" ");
        }
        for (numerales = 0; numerales < filas + 1; numerales++)
            // si la variable numeral es igual a 0, se imprime un numeral y se aumenta en 1 la variable numeral hasta que la variable numeral sea menor a la variable filas + 1
        {
            printf("#");
        }
        printf("  ");
        // se imprimen dos espacios en blanco para hacer una separacion entre las dos piramides tal a como lo pide el ejercicio

        for (nivel = 0; nivel < filas + 1; nivel++)
            // en este ciclo for se imprime la segunda piramide pero, en este caso, se imprime de derecha a izquierda
        {
            printf("#");
        }
        printf("\n");
        // se imprime un salto de linea para que la siguiente fila de la piramide se imprima debajo de la fila anterior
    }
    return 0;
    // retornamos 0 para indicar que el programa se ejecuto correctamente
}

// Programa que imprime una piramide de mario con la altura ingresada por el usuario (valores enteros entre 0 y 23) y centrada en la pantalla
// @author: @Meitchouk (GitHub)