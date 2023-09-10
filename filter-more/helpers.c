#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0;
            BYTE gray = 0;
            if (((int)(average + 0.5) - (int)average) == 1)
            {
                gray = (BYTE) average + 1;
            }
            else
            {
                gray = (BYTE) average;
            }
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed = gray;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width + 1) / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j+1)];
            image[i][width - (j+1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE bitmap[height][width];

    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE temp[9];

        //counts the number involved in average (the denominator)
        for (int j = 0; j < width; j++)
        {
            int number = 0;
            float average[3] = {0};
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    if ((i + x) < 0 || (i + x) > height - 1)
                    {
                        continue;
                    }

                    if ((j + y) < 0 || (y + j) > width - 1)
                    {
                        continue;

                    }

                    temp[number] = image[i + x][j + y];
                    number++;
                }
            }

            for (int k = 0; k < number; k++)
            {
                average[0] += temp[k].rgbtRed;
                average[1] += temp[k].rgbtGreen;
                average[2] += temp[k].rgbtBlue;
            }

            for (int k = 0; k < 3; k++)
            {
                average[k] /= number;
                if ((int) (average[k] + 0.5) - (int) (average[k]) == 1)
                {
                    average[k]++;
                }
            }

            bitmap[i][j].rgbtRed = (int) average[0];
            bitmap[i][j].rgbtGreen = (int) average[1];
            bitmap[i][j].rgbtBlue = (int) average[2];
        }


    }

    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                image[i][j] = bitmap[i][j];
            }
        }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int test[3][3];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redx = 0, greenx = 0, bluex = 0, redy = 0, greeny = 0, bluey = 0;
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    if ((x + i) < 0 || (x + i) > (height - 1))
                    {
                        continue;
                    }

                    if((y + j) < 0 || (y + j) > (width - 1))
                    {
                        continue;
                    }

                    redx += image[x + i][y + j].rgbtRed * Gx[x + 1][y + 1];
                    greenx += image[x + i][y + j].rgbtGreen * Gx[x + 1][y + 1];
                    bluex += image[x + i][y + j].rgbtBlue * Gx[x + 1][y + 1];

                    redy += image[x + i][y + j].rgbtRed * Gy[x + 1][y + 1];
                    greeny += image[x + i][y + j].rgbtGreen * Gy[x + 1][y + 1];
                    bluey += image[x + i][y + j].rgbtBlue * Gy[x + 1][y + 1];
                }
            }
            int sobel[3];
            sobel[0] = round(sqrt((redx * redx + redy * redy)));
            sobel[1] = round(sqrt((greenx * greenx + greeny * greeny)));
            sobel[2] = round(sqrt((bluex * bluex + bluey * bluey)));
            for (int k = 0; k < 3; k++)
            {
                if (sobel[k] > 255)
                {
                    sobel[k] = 255;
                }
            }
            temp[i][j].rgbtRed = sobel[0];
            temp[i][j].rgbtGreen = sobel[1];
            temp[i][j].rgbtBlue = sobel[2];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
