#include <cs50.h>
#include <stdio.h>

int main(void)
{

    string message = get_string("Encrypted message:\n");

    //length of message
    int l = 0;
    while (message [l] != '\0')
    {
        l++;
    }
    printf("%i\n" ,l);

}



    int index = 0.0588 * L - 0.296 * S - 15.8;
    printf("%i" , index);




        int l = strlen(argv[1]);

    for (int i = 0; i < l; i++)//starten mit i=0? oder mit 9?
    {
        if ((int)argv[1] < 48 || (int)argv[1] > 57)
        {
            printf("Usage: ./caesar key####error2\n");
            return 1;
        }
    }


    int k = atoi(argv[1]);
    if (k < 0)
    {
        printf("Usage: ./caesar key // only positive numbers //error3\n");
        return 1;
    }