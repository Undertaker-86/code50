#include "helpers.h"

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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        float sepia[3] = {0, 0, 0};
        for (int j = 0; j < width; j++)
        {
            sepia[0] = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            sepia[1] = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            sepia[2] = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            for (int k = 0; k < 3; k++)
            {
                if (sepia[k] > 255)
                {
                    sepia[k] = 255;
                }

                if (((int) (sepia[k] + 0.5) - (int) (sepia[k])) == 1)
                {
                    sepia[k] += 1;
                }
            }

            image[i][j].rgbtRed = (int) sepia[0];
            image[i][j].rgbtGreen = (int) sepia[1];
            image[i][j].rgbtBlue = (int) sepia[2];
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
