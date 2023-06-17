#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;
bool newpic(BYTE* buffer);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("wrong usage!\n");
        return 1;
    }
    FILE *raw_ptr = fopen(argv[1], "r");
    if (raw_ptr == NULL)
    {
        printf("cannot open file.\n");
        return 2;
    }

    BYTE *buffer = malloc(512);
    if (buffer == NULL)
    {
        return 3;
    }

    char *filename = malloc(8);
    if (filename == NULL)
    {
        return 4;
    }

    int i = 0;
    FILE *recov_ptr = NULL;

    while (512 == fread(buffer, 512, 1, raw_ptr))
    {
        if (newpic(buffer) == true)
        {
            if (recov_ptr != NULL)
            {
                fclose(recov_ptr);
            }
            sprintf(*filename, "%03i.jpg", i);
            recov_ptr = fopen(filename, "w");
            if (recov_ptr == NULL)
            {
                return 5;
            }
            i++;
        }
        fwrite(buffer, 512, 1, recov_ptr);
    }
    fclose(recov_ptr);
    fclose(raw_ptr);
    free(buffer);
    free(filename);
    return 0;
}


//unsigned ints
bool newpic(BYTE* buffer)
{
    if (0xff != *(buffer) && 0xd8 != *(buffer+1) && 0xff != *(buffer+2))
    {
        if (0xe0 > *(buffer+3) || 0xef < *(buffer+3))
        {
            return false;
        }
    }
    return true;
}













/*Implement a program called recover that recovers JPEGs from a forensic image.

Implement your program in a file called recover.c in a directory called recover.
Your program should accept exactly one command-line argument, the name of a forensic image
from which to recover JPEGs.
If your program is not executed with exactly one command-line argument, it should remind the
user of correct usage, and main should return 1.
If the forensic image cannot be opened for reading, your program should inform the user
as much, and main should return 1.
The files you generate should each be named ###.jpg, where ### is a three-digit decimal
number,starting with 000 for the first image and counting up.
Your program, if it uses malloc, must not leak any memory.
*/