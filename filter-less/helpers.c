#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i= 0; i < height; i++)
    {
        for (int j= 0; j < width; j++)
        {
            float average = 0;
            average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            average = (int) round(average);
            //nur ganze mit 0xff
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE save[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
             int sepaired = round((image[i][j].rgbtRed *0.393) + (image[i][j].rgbtGreen *0.769) + (image[i][j].rgbtBlue *0.189));
             int sepaigreen = round((image[i][j].rgbtRed *0.349) + (image[i][j].rgbtGreen *0.686) + (image[i][j].rgbtBlue *0.168));
             int sepaiblue = round((image[i][j].rgbtRed *0.272) + (image[i][j].rgbtGreen *0.534) + (image[i][j].rgbtBlue *0.131));
             if (sepaired > 255)
             {
                sepaired = 255;
             }
             if (sepaigreen > 255)
             {
                sepaigreen = 255;
             }
             if (sepaiblue > 255)
             {
                sepaiblue = 255;
             }
             save[i][j].rgbtRed = sepaired;
             save[i][j].rgbtGreen = sepaigreen;
             save[i][j].rgbtBlue = sepaiblue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = save[i][j].rgbtRed;
            image[i][j].rgbtGreen = save[i][j].rgbtGreen;
            image[i][j].rgbtBlue = save[i][j].rgbtBlue;
        }
    }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
        RGBTRIPLE save[height][width];
    for (int i= 0; i < height; i++)
    {
        for (int j= 0; j < width; j++)
        {
            save[i][width-(j+1)] = image[i][j];
        }
    }
    for (int i= 0; i < height; i++)
    {
        for (int j= 0; j < width; j++)
        {
            image[i][j] = save[i][j];
        }
    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE save[height][width];

    for (int i= 0; i < height; i++)
    {
        for (int j= 0; j < width; j++)
        {
            //betrachte ein pixel
            int y[3] = {i-1, i, i+1};
            int x[3] = {j-1, j, j+1};

            double rgbsum [3] = {0,0,0};
            int n = 0;

            for (int k= 0; k < 3; k++)
            {
                for (int l= 0; l < 3; l++)
                {
                    //betrachte 3x3 block um pixel
                    if (y[k] >= 0 && y[k] < height && x[l] >= 0 && x[l] < width)
                    {
                        //addiere alle existenten farben im block
                        rgbsum[0] += image[y[k]][x[l]].rgbtBlue;
                        rgbsum[1] += image[y[k]][x[l]].rgbtGreen;
                        rgbsum[2] += image[y[k]][x[l]].rgbtRed;
                        n++; //divident
                    }
                }
            }
            save[i][j].rgbtBlue = round((rgbsum[0] / n));
            save[i][j].rgbtGreen = round((rgbsum[1] / n));
            save[i][j].rgbtRed = round((rgbsum[2] / n));
        }
    }
    for (int i= 0; i < height; i++)
    {
        for (int j= 0; j < width; j++)
        {
            image[i][j].rgbtBlue = save[i][j].rgbtBlue;
            image[i][j].rgbtGreen = save[i][j].rgbtGreen;
            image[i][j].rgbtRed = save[i][j].rgbtRed;
        }
    }
    return;
}
