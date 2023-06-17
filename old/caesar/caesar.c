#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //nur key!
    if (argc != 2)
    {
        printf("error_1");
        return 1;
    }
    //key ist 1-25
    if ((int)argv[1] < 49 ||
        ((int)argv[1] > 57 && (int)argv[1] < 4948) ||
        ((int)argv[1] > 4957 && (int)argv[1] < 5048) ||
        (int)argv[1] > 5053)
    {
        printf("error_2");
        return 1;
    }


    string ptx = get_string("plaintext: ");

    //length of message
    int l = 0;
    while (ptx [l] != '\0')
    {
        l++;
    }
    return l;


    printf("ciphertext: ");


    //make key-string to int
    int k = atoi(argv[1]);


    //change char

    for (int c = 0; c < l; c++)
    {
        if ((ptx[c] > 64 && ptx[c] < 91) || (ptx[c] > 96 && ptx[c] < 123))
        {
            ptx[c] = (int) ptx[c] + k;
        }
    printf("%c" , ptx[c]);
    }



























    string message = get_string("Encrypted message:\n");

    //length of message = l
    int l = 0;
    while (message [l] != '\0')
    {
        l++;
    }
    return l


    int c;
    do
    {
        int c = get_int("prombt key: ");
    }
    while (c < 0 && c > 25)

    {
    int argc = c;
    return argc;
    }


}
}