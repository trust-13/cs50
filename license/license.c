#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char* buffer = malloc(1*7);
    if (buffer == NULL)
        return 1;
    //char buffer[7];

    // Create array to store plate numbers
    char* array_adress[8];

    int i= 0;

    FILE *infile = fopen(argv[1], "r");

    //int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';
        array_adress[i] = malloc(1*7);
        // Save plate number in array
        strcpy(array_adress[i], buffer);
        //*plates[idx] = buffer;
        //idx++;
    //}

    //for (int i = 0; i < 8; i++)
    //{
        printf("%s\n", array_adress[i]);
        i++;
    }
    fclose(infile);
    free(buffer);
    for (int j = 0; j < 8; j++)
    {
        free(array_adress[j]);
    }
    return 0;
}
