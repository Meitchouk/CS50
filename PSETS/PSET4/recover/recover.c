#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// eliminate magic numbers
#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // validamos si la entrada es diferente de cero
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *rawFile = fopen(argv[1], "r");

    // comprobamos si el archivo es nulo
    if (rawFile == NULL)
    {
        fclose(rawFile);
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        return 1;
    }

    FILE *image;
    char filename[8];

    BYTE buffer[BLOCK_SIZE];
    int count = 0;

    while (fread(&buffer, BLOCK_SIZE, 1, rawFile))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            /** Close previous jpeg before processing a new one */
            if (count > 0)
            {
                fclose(image);
            }

            sprintf(filename, "%03d.jpg", count);

            image = fopen(filename, "w");

            count++;
        }
        /** Keep writing after you find first jpeg block */
        if (count > 0)
        {
            fwrite(buffer, BLOCK_SIZE, 1, image);
        }
    }
    // cerramos la imagen
    fclose(image);
    fclose(rawFile);

    return 0;
}