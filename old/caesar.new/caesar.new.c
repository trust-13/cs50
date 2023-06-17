#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key ////only one input////error1\n");
        return 1;
    }


    string key = argv[1];
    int lkey = strlen(key); // = strlen(argv[1]);


    for (int i = 0; i < lkey; i++)
    {
        if (isdigit(key[i]) == 0) // (!isdigit(key[i])) ist identisch
        {
        printf("Usage: ./caesar key ////all inputs must be decimal digits////error2\n");
        return 1;
        }
    }






    int k = atoi(key);

    string txt = get_string("Input Plaintext:\n");
    int ltxt = strlen(txt);


    printf("Ciphertext:\n");

    for (int j = 0; j < ltxt; j++)
    {
        if (isupper(txt[j]))
        {
            char C = (txt[j] - 65 + k) % 26 + 65;
            printf("%c" , C);
        }
        if (islower(txt[j]))  // else if (islower(txt[j]))
        {
            char c = (txt[j] - 97 + k) % 26 + 97;
            printf("%c" , c);
        }
        if (!isalpha(txt[j])) // else
        {
            printf("%c" , txt[j]);
        }
    }
    printf("\n");

return 0;
}