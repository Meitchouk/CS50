#include <stdio.h>
#include <cs50.h> // incluimos la libreria cs50.h para poder hacer uso del get_String y get_int que nos pide el ejercicio

int main(void)
{
    int initial_size, final_size, birth_rate, death_rate, annual_population_growth, years = 0;
    // declaramos las variables que vamos a utilizar en el programa
    // inicializamos la variable years a 0 para que no nos de un valor basura al hacer el calculo de años que tarda en alcanzar la poblacion final

    // TODO: Prompt for start size
    do // hacemos un bucle do while para que nos pida el tamaño inicial de la poblacion hasta que introduzcamos un numero mayor que 9
    {
        initial_size = get_int("Ingresa el tamaño inicial de la poblacion: \n");
        // Solicitamos el tamaño inicial de la poblacion de llamas
    }
    while (initial_size < 9);
    // Validamos que el tamaño inicial de la poblacion sea mayor a 9 (si empezamos con menos de 9 llamas, ¡la población de llamas se estancará rápidamente!)

    // TODO: Prompt for end size
    do // hacemos un bucle do while para que nos pida el tamaño final de la poblacion hasta que introduzcamos un numero mayor que el tamaño inicial solicitado anteriormente
    {
        final_size = get_int("Ingresa el tamaño final de la poblacion: \n");
        // Solicitamos el tamaño final de la poblacion
    }
    while (final_size < initial_size);
    // Validamos que el tamaño final de la poblacion sea mayor al tamaño inicial de la poblacion

    // TODO: Calculate number of years until we reach threshold

    while (initial_size < final_size) // hacemos un bucle while para que nos calcule los años que tarda en alcanzar la poblacion final
    {
        birth_rate = initial_size / 3;
        // Calculamos el numero de nacimientos por año (1/3 de la poblacion inicial) y lo almacenamos en la variable birth_rate (tasa de natalidad)
        death_rate = initial_size / 4;
        // Calculamos el numero de muertes por año (1/4 de la poblacion inicial) y lo almacenamos en la variable death_rate (tasa de mortalidad)
        annual_population_growth = birth_rate - death_rate;
        // Calculamos el crecimiento anual de la poblacion (tasa de natalidad - tasa de mortalidad) y lo almacenamos en la variable annual_population_growth (crecimiento anual de la poblacion)
        initial_size += annual_population_growth;
        // Calculamos el tamaño de la poblacion al final del año (tamaño inicial de la poblacion + crecimiento anual de la poblacion) y lo almacenamos en la variable initial_size (tamaño inicial de la poblacion)
        years++;
        /*
            Incrementamos el numero de años en 1 (years = years + 1) y lo almacenamos en la variable years (numero de años) para llevar el conteo de los años que han pasado desde que la poblacion inicial
            de llamas era menor al tamaño final de la poblacion de llamas que queremos alcanzar (final_size).
        */
    }

    // TODO: Print number of years
    printf("Years: %i \n", years); // Imprimimos el numero de años que tarda en alcanzar la poblacion final
    // printf("La poblacion de llamas tarda %i años en alcanzar el tamaño final de %i llamas.\n", years, final_size); // por si quieren probarlo y que se mire mas bonito, pueden descomentar esta linea y comentar la linea de arriba

    // NOTA: El tamaño final de la poblacion es el mismo que el tamaño inicial de la poblacion al final del ultimo año

    return 0; // retornamos 0 para indicar que el programa se ejecuto correctamente
}

// Programa que calcula el numero de años que tarda en alcanzar la poblacion final una poblacion inicial
// @author: @Meitchouk (GitHub)