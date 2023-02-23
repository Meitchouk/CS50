// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file

    uint8_t header[HEADER_SIZE];

    fread(header, HEADER_SIZE, 1, input);
    // Leemos el header del archivo de entrada

    fwrite(header, HEADER_SIZE, 1, output);
    // Escribimos el header en el archivo de salida

    // TODO: Read samples from input file and write updated data to output file

    int16_t buffer;

    while (fread(&buffer, sizeof(int16_t), 1, input))
        // Mientras se pueda leer un bloque de 16 bits del archivo de entrada
    {
        buffer *= factor;
        // Multiplicamos el valor de la muestra por el factor de escala
        fwrite(&buffer, sizeof(int16_t), 1, output);
        // Escribimos el valor de la muestra en el archivo de salida
    }

    // Close files
    fclose(input);
    fclose(output);

}

// @author: @Meitchouk (Github)
// Programa que aumenta o volume de um archivo .wav