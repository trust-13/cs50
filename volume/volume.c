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
    uint8_t *ptrx;

    ptrx = malloc (HEADER_SIZE * sizeof(uint8_t));

    if (ptrx == NULL)
    {
        return 1;
    }

    fread (ptrx, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite (ptrx, sizeof(uint8_t), HEADER_SIZE, output);
    free (ptrx);


    // TODO: Read samples from input file and write updated data to output file
    int16_t *ptr;

    ptr =  malloc (1 * sizeof(int16_t));
    if (ptr == NULL)
    {
        return 1;
    }

    //file pointers position pointer took me hours
    while (fread(ptr, sizeof(int16_t), 1, input) == 1)
    {
        *ptr *= factor;
        fwrite (ptr, sizeof(int16_t), 1, output);
    }
    free (ptr);


    // Close files
    fclose(input);
    fclose(output);
}
