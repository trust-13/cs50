// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch
#include <string.h>
#include <cs50.h>
#include <stdio.h>

string replace(string input);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("usage: ./no-vowels word_to_convert\n");
        return 1;
    }
    printf("%s\n" , replace(argv[1]));
}


string replace(string input)
{
    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        switch (input[i])
        {
            case 'a':
                input[i]='6';
                break;
            case 'e':
                input[i]='3';
                break;
            case 'i':
                input[i]='1';
                break;
            case 'o':
                input[i]='0';
            default:
                break;
        }
    }
    return input;
}