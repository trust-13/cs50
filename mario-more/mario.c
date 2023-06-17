#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("wich height? ");
    }
    while (h<1 || h>8);


    for (int i=0; i<h; i++)
    {
        for(int k=8; k>i; k-- )
        {
            printf(" ");
        }
            for(int j=0; j<i; j++)
            {
                printf("#");
            }


        printf("  ");


        for (int x=0; x<i; x++)
        {
            printf("#");
        }
            for (int y=8; y>i; y--)
            {
                printf(" ");
            }

        printf("\n");
    }
}