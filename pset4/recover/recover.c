#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
typedef uint8_t BYTE; 
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

//open file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Unable to open file\n");
        return 2;
    }
 
//create buffer
    BYTE buffer[512];
//if first image
    _Bool jpg_found = 0;
//number of jpgs so far
    int jpgno = 0;
//pointer to current jpg file
    FILE *output = NULL;

//go through memory card to find jpg, forever loop until 512 bytes is null
    while (fread(buffer, 512, 1, input) == 1)
    {
//find jpg header in first 4 bytes of buffer
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if not first jpg, close previous
            if (jpg_found == 1)
            {
                fclose(output);
            }
            //if first jpg
            else
            {
                jpg_found = 1;
            }
            //create file for new jpg
            char filename[8];
            sprintf(filename, "%03i.jpg", jpgno);
            output = fopen(filename, "w");
            jpgno++;
            fwrite(&buffer, 512, 1, output);
        }
        //if no header found
        else
        {
            //if already writing a jpg, continue
            if (jpg_found == 1)
            {
                fwrite(&buffer, 512, 1, output);
            }
        }
    }
 
 
    fclose(intput);
    fclose(output);
    return 0;
}