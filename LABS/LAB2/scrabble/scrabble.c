#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        // si el puntaje del jugador 1 es mayor al puntaje del jugador 2
        printf("Player 1 wins!!!");
        // entonces el jugador 1 gana
    }
    else if (score1 < score2)
    {
        // pero si el puntaje del jugador 1 es menor al puntaje del jugador 2
        printf("Player 2 wins!!!");
        // imprimimos el mensaje de que gano el jugador 2
    }
    else if (score1 == score2)
    {
        // pero si el puntaje del jugador 1 es igual al puntaje del jugador 2
        printf("Tie!!!");
        // imprimimos un empate
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;
    // Inicializamos la variable score en 0 para que se vaya sumando el puntaje de cada letra del string

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // para cada letra del string ingresado por el usuario recorremos el string de izquierda a derecha y sumamos el puntaje de cada letra al puntaje total
        if (isupper(word[i]))
        {
            // si el puntaje de la letra es mayuscula entonces le restamos 65 para que nos de el indice de la letra en el array
            score += POINTS[word[i] - 65]; // 65 es el valor de la letra A en ASCII
            // sumamos el puntaje de la letra al puntaje total
        }
        else if (islower(word[i]))
        {
            // pero si el puntaje de la letra es minuscula entonces le restamos 97 para que nos de el indice de la letra en el array
            score += POINTS[word[i] - 97]; // 97 es el valor de la letra a en ASCII
            // sumamos el puntaje de la letra al puntaje total
        }
    }
    return score;
    // retornamos el puntaje para que se pueda comparar con el puntaje del otro jugador y asi determinar el ganador o si hay empate
}

// A=1, B=3, C=3, D=2, E=1, F=4, G=2, H=4, I=1, J=8, K=5, L=1, M=3,
// N=1, O=1, P=3, Q=10, R=1, S=1, T=1, U=1, V=4, W=4, X=8, Y=4, Z=10

// Codigo de juego de Scrabble en C
// @AUTHOR: @Meitchouk (GitHub)