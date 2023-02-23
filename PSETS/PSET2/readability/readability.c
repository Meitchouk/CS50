#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int letras(string);
int palabras(string);
int oraciones(string);

float l = 0;
float w = 1;
float s = 0;

int main(void)
{
    string texto = get_string("Text: ");
    l = letras(texto);
    w = palabras(texto);
    s = oraciones(texto);
    float L = (l / w) * 100;
    float S = (s / w) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
        // si el índice es menor a 1, el texto es antes del grado 1
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
        // si el índice es mayor o igual a 16, el texto es del grado 16 o más
    }
    else
    {
        printf("Grade %i\n", grade);
        // si el índice es mayor o igual a 1 y menor a 16, el texto es del grado que se muestra
    }
}

int letras(string texto)
// inicializamos la funcion letras que recibe el teto
{
    for (int i = 0, n = strlen(texto); i < n; i++)
        // y decimos, para cada letra del texto, si es una letra, entonces aumenta el contador de letras
    {
        if (isalpha(texto[i]))
            // si isalpha es verdadero, entonces aumenta el contador de letras
        {
            l++;
        }
    }
    return l;
    // devolvemos el valor de l
}

int palabras(string texto)
// inicializamos la funcion palabras que recibe el texto
{
    for (int i = 0, n = strlen(texto); i < n; i++)
        // y decimos, para cada letra del texto, si es un espacio, entonces aumenta el contador de palabras
    {
        if (isspace(texto[i]))
            // si isspace es verdadero, entonces aumenta el contador de palabras
        {
            w++;
        }
    }
    return w;
    // devolvemos el valor de w
}

int oraciones(string texto)
// inicializamos la funcion oraciones que recibe el texto
{
    for (int i = 0, n = strlen(texto); i < n; i++)
        // y decimos, para cada letra del texto, si es un punto, un signo de exclamación o un signo de interrogación, entonces aumenta el contador de oraciones
    {
        if (texto[i] == '.' || texto[i] == '!' || texto[i] == '?')
            // si es un punto, un signo de exclamación o un signo de interrogación, entonces aumenta el contador de oraciones
        {
            s++;
        }
    }
    return s;
    // devolvemos el valor de s
}

// @author: @Meitchouk (GitHub)
/*
    programa que calcula el índice de legibilidad de un texto según el número de letras, palabras y oraciones que contiene el texto
    y devuelve el grado de legibilidad del texto según el índice de legibilidad calculado (antes del grado 1, del grado 1 al 16, o del grado 16 o más)
    según la fórmula de Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8, donde L es el promedio de letras por 100 palabras en el texto, y S es el promedio
    de oraciones por 100 palabras en el texto
*/
