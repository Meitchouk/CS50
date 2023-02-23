#include <stdio.h> // incluimos la libreria stdio.h para poder hacer uso de printf y scanf
#include <cs50.h> // incluimos la libreria cs50.h para poder hacer uso del get_String

int main(void)
{
    string username;
    // declaramos la variable Nombre_Usuario como tipo string

    username = get_string("Ingresa tu nombre porfavor: ");
    // Solicitamos el nombre del usuario
    printf("Hola %s, bienvenido a CS50, un gusto tenerte por acá\n", username);
    // Imprimimos el nombre del usuario
}

// Programa que imprime un saludo personalizado al usuario
// @author: @Meitchouk (GitHub)
