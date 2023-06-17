#include <cs50.h>
#include <stdio.h>


int collatz(int n);

int main (void)
{
    int x = 0;
    while (x <= 0)
    {
        x = get_int("use collatz conj. on ");
    }
    int count = 0;
    count = collatz(x);
    printf("it took %i steps to reach one!\n" , count);
    return 0;
}


int collatz(int n)
{
    if (n == 1)
        return 0;
    else if (n%2 == 0)
        return 1 + collatz(n/2);
    else
        return 1 + collatz(3*n+1);
}