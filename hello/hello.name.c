#include <stdio.h>
#include <cs50.h>

int main(void)

{
    string name = get_string("whats ur name? ");
    printf("Hello, %s!\n" , name);
}