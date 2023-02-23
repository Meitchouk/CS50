#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long numero_tarjeta = 0;
long long longitud_numero_tarjeta = 0;
// Variable que almacena el numero de la tarjeta de credito ingresado por el usuario (long long porque el numero de la tarjeta de credito puede tener hasta 16 digitos)

int main(void)
{
    do
    {
        numero_tarjeta = get_long_long("Ingresa el numero de la tarjeta de credito: \n");
        // Solicitamos el numero de la tarjeta de credito al usuario
    }
    while (numero_tarjeta <= 0 || numero_tarjeta >= 10000000000000000);
    // Validamos que el numero de la tarjeta de credito sea mayor a 0 y menor a 10000000000000000 (16 digitos)

    numero_tarjeta = floor(log10(llabs(numero_tarjeta))) + 1;
    // Obtenemos la cantidad de digitos que tiene el numero de la tarjeta de credito ingresado por el usuario

    long long digitos_tarjeta[longitud_numero_tarjeta];

    for (int i = (longitud_numero_tarjeta - 1); i >= 0; i--)
    // Recorremos el numero de la tarjeta de credito de derecha a izquierda
    {
        digitos_tarjeta[i] = numero_tarjeta % 10;
        // Almacenamos cada digito del numero de la tarjeta de credito en un arreglo
        numero_tarjeta = numero_tarjeta / 10;
        // Eliminamos el ultimo digito del numero de la tarjeta de credtio para obtener el siguiente digito en la iteracion siguiente del ciclo

        printf("digitos tarjeta %lld",digitos_tarjeta[i]);
    }



    return 0; // Fin del programa
}

// Programa que valida y clasifica una tarjeta de credito segun su numero de tarjeta de credito (VISA, MASTERCARD, AMERICAN EXPRESS)
// @author: @Meitchouk (GitHub)