#include "helpers.h"
#include <math.h>

#define RED 0
#define GREEN 1
#define BLUE 2

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int newColor;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            newColor =
                round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = newColor;
            image[i][j].rgbtRed = newColor;
            image[i][j].rgbtGreen = newColor;
        }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                             .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                               .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                              .131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
                image[i][j].rgbtRed = 255;
            else
                image[i][j].rgbtRed = sepiaRed;

            if (sepiaBlue > 255)
                image[i][j].rgbtBlue = 255;
            else
                image[i][j].rgbtBlue = sepiaBlue;

            if (sepiaGreen > 255)
                image[i][j].rgbtGreen = 255;
            else
                image[i][j].rgbtGreen = sepiaGreen;
        }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
}

// Calculate blur for a specific color channel
int getBlur(int i, int j, int height, int width, RGBTRIPLE image[height][width], int colorPos)
{
    float count = 0;
    int sum = 0;
    for (int row = i - 1; row <= i + 1; row++)
        for (int column = j - 1; column <= j + 1; column++)
        {
            if (row < 0 || row >= height || column < 0 || column >= width)
                continue;

            switch (colorPos)
            {
                case RED:
                    sum += image[row][column].rgbtRed;
                    break;
                case GREEN:
                    sum += image[row][column].rgbtGreen;
                    break;
                case BLUE:
                    sum += image[row][column].rgbtBlue;
                    break;
            }
            count++;
        }
    return round(sum / count);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            temp[i][j] = image[i][j];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = getBlur(i, j, height, width, temp, RED);
            image[i][j].rgbtGreen = getBlur(i, j, height, width, temp, GREEN);
            image[i][j].rgbtBlue = getBlur(i, j, height, width, temp, BLUE);
        }
}
