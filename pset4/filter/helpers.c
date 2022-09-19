#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float ogRed = image[h][w].rgbtRed;
            float ogBlue = image[h][w].rgbtBlue;
            float ogGreen = image[h][w].rgbtGreen;
            
            int ave = round((ogRed + ogBlue + ogGreen) / 3);
            
            image[h][w].rgbtRed = ave;
            image[h][w].rgbtBlue = ave;
            image[h][w].rgbtGreen = ave;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int originalRed = image[h][w].rgbtRed;
            int originalBlue = image[h][w].rgbtBlue;
            int originalGreen = image[h][w].rgbtGreen;
            
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            
            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtBlue = sepiaBlue;
            image[h][w].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer_row[width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            buffer_row[w] = image[h][w];
        }
        
        for (int w = 0; w < width; w++)
        {
            image[h][w].rgbtRed = buffer_row[width - w - 1].rgbtRed;
            image[h][w].rgbtBlue = buffer_row[width - w - 1].rgbtBlue;
            image[h][w].rgbtGreen = buffer_row[width - w - 1].rgbtGreen;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempimage[height][width];
    //copy image
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            tempimage[h][w] = image[h][w];
        }
    }
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            //to count number of cells that exist adjacent
            int count = 0;
            //to add up total of each colour
            float sumRed = 0;
            float sumBlue = 0;
            float sumGreen = 0;
            //for cells above and below
            for (int updown = -1; updown < 2; updown++)
            {
                //for cells left and right
                for (int leftright = -1; leftright < 2; leftright++)
                {
                    //check if cell is within height
                    if (h + updown < 0 || h + updown >= height)
                    {
                        continue;
                    }
                    //check if cell is within width
                    if (w + leftright < 0 || w + leftright >= width)
                    {
                        continue;
                    }
                    //if cell is within, add colours
                    else
                    {
                        sumRed += tempimage[h + updown][w + leftright].rgbtRed;
                        sumBlue += tempimage[h + updown][w + leftright].rgbtBlue;
                        sumGreen += tempimage[h + updown][w + leftright].rgbtGreen;
                        count++;
                    }
                }
            }
            //to change colour of cell
            image[h][w].rgbtRed = round(sumRed / count);
            image[h][w].rgbtBlue = round(sumBlue / count);
            image[h][w].rgbtGreen = round(sumGreen / count);
        }
    }
    return;
}
