#include "helpers.h"
#include <math.h>

// Convertimos la imagen a escala de grises
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
        // recorremos la imagen en filas y columnas para obtener los valores de cada pixel y calcular el promedio
    {
        for (int j = 0; j < width; j++)
            // para cada pixel en la imagen se calcula el promedio de los colores y se actualiza el pixel
        {
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            int average = round((Red + Green + Blue) / 3);
            // se calcula el promedio de los colores y se redondea al entero mas cercano con round
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
            // se actualiza el pixel con el promedio de los colores y se redondea al entero mas cercano con round
        }
    }
    return;
    // se retorna la imagen en escala de grises con los colores actualizados
}

// Convertimos la imagen a sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // inicializamos sepia
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            // para cada pixel en la imagen se calcula el promedio de los colores y se actualiza el pixel
        {
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            // evaluar con if el valor de los colores
            if (sepiaRed > 255)
                // si el valor del color es mayor a 255 se actualiza con 255 para evitar valores negativos
            {
                sepiaRed = 255;
                // se actualiza el valor del color
            }

            if (sepiaGreen > 255)
                // si el valor del color es mayor a 255 se actualiza con 255 para evitar valores negativos
            {
                sepiaGreen = 255;
                // se actualiza el valor del color
            }

            if (sepiaBlue > 255)
                // si el valor del color es mayor a 255 se actualiza con 255 para evitar valores negativos
            {
                sepiaBlue = 255;
                // se actualiza el valor del color
            }

            // se actualiza el pixel con el promedio de los colores y se redondea al entero mas cercano con round
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // inicializamos reflect horizontal y vertical con el mismo codigo cambiando el orden de los ciclos for para recorrer la imagen en columnas y filas y no en filas y columnas
    for (int i = 0; i < height; i++)
    {
        // recorremos la imagen en filas y columnas para obtener los valores de cada pixel y calcular el promedio y actualizar el pixel
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            // se crea una variable temporal para guardar el valor del pixel
            image[i][j] = image[i][width - (j + 1)];
            // se actualiza el pixel con el valor del pixel de la otra mitad de la imagen
            image[i][width - (j + 1)] = temp;
            // se actualiza el pixel con el valor del pixel guardado en la variable temporal
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // inicializamos blur con el mismo codigo cambiando el orden de los ciclos for para recorrer la imagen en columnas y filas y no en filas y columnas
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
        // recorremos la imagen en filas y columnas para obtener los valores de cada pixel y calcular el promedio y actualizar el pixel
    {
        for (int j = 0; j < width; j++)
            // para cada pixel en la imagen se calcula el promedio de los colores y se actualiza el pixel
        {
            temp[i][j] = image[i][j];
            // se crea una variable temporal para guardar el valor del pixel
        }
    }
    // recorremos la imagen en filas y columnas para obtener los valores de cada pixel y calcular el promedio y actualizar el pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            // para cada pixel en la imagen se calcula el promedio de los colores y se actualiza el pixel
        {
            int totalRed, totalGreen, totalBlue;
            totalRed = totalGreen = totalBlue = 0;
            float counter = 0.00;
            // se inicializan las variables para calcular el promedio de los colores

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                    // se recorren los pixeles vecinos
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }
                    // Obtener la imagen
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }

                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
    // se actualiza el pixel con el promedio de los colores y se redondea al entero mas cercano con round
}

// @Author: @Meitchouk (GitHub)