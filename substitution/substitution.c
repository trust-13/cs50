#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (argc != 2)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    int keyL = strlen(argv[1]);

    if (keyL != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

    for (int n = 0; n < 25 ; n++)
        {
            for (int z = n+1 ; z < 26 ; z++)
            {
                if (argv[1][n] == argv[1][z])
                {
                    printf("each character only once!\n");
                    return 1;
                }
            }
        }

    for (int m = 0; m < 26 ; m++)
        {
            if (isalpha(argv[1][m]) == 0)
            {
                printf("Key can only contain letters!\n");
                return 1;
            }
        }


    string ptxt = get_string("plaintext: ");

    int txtL = strlen(ptxt);

    printf("ciphertext: ");

    for (int k = 0; k < txtL ; k++)
        {
            if (islower(ptxt[k]))
            {
                int v = (int) ptxt[k] - 97;
                char x = argv[1][v];
                char a = tolower(x);
                printf("%c", a);
            }
            if (isupper(ptxt[k]))
            {
                int w = (int) ptxt[k] - 65;
                char y = argv[1][w];
                char b = toupper(y);
                printf("%c", b);
            }
            if (!isalpha(ptxt[k]))
            {
                printf("%c", ptxt[k]);
            }
        }
    printf("\n");

}