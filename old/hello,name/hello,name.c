#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("hi, whats your name? ");
    printf("hello, %s\n", name);
}