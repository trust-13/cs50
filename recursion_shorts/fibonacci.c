#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>


int fibo(int n);

int main (void)
{
    int x = get_int("nummer der fibonacci reihe: ");
    int y = fibo(x);
    printf("Wert der Fibonacci-reihe an der stelle %i ist %i.\n",x ,y);
    return 0;
}

int fibo(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    return fibo(n-1)+fibo(n-2);
}