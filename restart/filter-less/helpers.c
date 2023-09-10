#include "helpers.h"

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            double average = (image[row][col].rgbtBlue + image[row][col].rgbtGreen + image[row][col].rgbtRed) / (double) 3;
            int rounded_average = (int)(average + 0.5);
            image[row][col].rgbtBlue = rounded_average;
            image[row][col].rgbtGreen = rounded_average;
            image[row][col].rgbtRed = rounded_average;
        }
    }
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            double sepia_red = .393 * image[row][col].rgbtRed + .769 * image[row][col].rgbtGreen + .189 * image[row][col].rgbtBlue;
            double sepia_green = .349 * image[row][col].rgbtRed + .686 * image[row][col].rgbtGreen + .168 * image[row][col].rgbtBlue;
            double sepia_blue = .272 * image[row][col].rgbtRed + .534 * image[row][col].rgbtGreen + .131 * image[row][col].rgbtBlue;

            if (sepia_red > 255)
            {
                image[row][col].rgbtRed = 255;
            }

            else if ((int) (sepia_red + 0.5) > sepia_red)
            {
                image[row][col].rgbtRed = (int) (sepia_red + 0.5);
            }

            else
            {
                image[row][col].rgbtRed = (int) sepia_red;
            }

            if (sepia_green > 255)
            {
                image[row][col].rgbtGreen = 255;
            }

            else if ((int) (sepia_green + 0.5) > sepia_green)
            {
                image[row][col].rgbtGreen = (int) (sepia_green + 0.5);
            }

            else
            {
                image[row][col].rgbtGreen = (int) sepia_green;
            }

            if (sepia_blue > 255)
            {
                image[row][col].rgbtBlue = 255;
            }

            else if ((int) (sepia_blue + 0.5) > sepia_blue)
            {
                image[row][col].rgbtBlue = (int) (sepia_blue + 0.5);
            }

            else
            {
                image[row][col].rgbtBlue = (int) sepia_blue;
            }
        }
    }
}
/*
 sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
  sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
  sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
*/
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE input[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int j = 0; j < width; j++)
        {
            input[row][j] = image[row][width - 1 - j];
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col] = input[row][col];
        }
    }
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int count = 0;
                double sumBlue = 0;
                double sumRed = 0;
                double sumGreen = 0;

            for (int i = row - 1; i <= row + 1; i++)
            {
                for (int j = col - 1; j <= col + 1; j++)
                {

                    if (!(i <= -1 || i >= height || j <= -1 || j >= width))
                    {
                        sumBlue += image[i][j].rgbtBlue;
                        sumRed += image[i][j].rgbtRed;
                        sumGreen += image[i][j].rgbtGreen;
                        count++;
                    }


                }


            }


            temp[row][col].rgbtBlue = (int) ( (sumBlue / count) + 0.5);
            temp[row][col].rgbtRed = (int) ( (sumRed / count) + 0.5);
            temp[row][col].rgbtGreen = (int) ( (sumGreen / count) + 0.5);
        }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}