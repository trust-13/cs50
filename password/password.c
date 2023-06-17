// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int len = strlen(password);
    int low = 0, up = 0, num = 0, sym = 0;
    for (int i = 0; i < len+1; i++)
    {
        if(0 != isdigit(password[i]))
        {
            num = 1;
        }
        if (0 != islower(password[i]))
        {
            low = 1;
        }
        if (0 != isupper(password[i]))
        {
            up = 1;
        }
        if (0 != ispunct(password[i]))
        {
            sym = 1;
        }
    }
    if (low == 1 && up == 1 && num == 1 && sym == 1)
    {
        return true;
    }
    return false;
}
