#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int n;
    do
    {
        n = get_int("start population size: ");
    }
    while (n < 9);





    // TODO: Prompt for end size
    int o;
    do
    {
        o = get_int("ending population size: ");
    }
    while (o < n);





    // TODO: Calculate number of years until we reach threshold
    int y = 0;

    do
    {
            y++;
            int p = n / 3;
            int m = n / 4;
            n = (n + p - m);
    }
    while (n < o);

    {
        printf("Years: %i\n" , y );   // TODO: Print number of years
    }

}
