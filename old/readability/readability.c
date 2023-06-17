#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int count_letters(string txt);
int count_words(string txt);
int count_sentences(string txt);

int main(void)
{
    string txt = get_string("Text: \n");
    int letters = count_letters(txt);
    int words = count_words(txt);
    int sentences = count_sentences(txt);
    //printf("letters:%i \nwords:%i \nsentences:%i \n" , letters , words , sentences);

    //Coleman-Liau index
    double L = (double)letters / words * 100;
    double S = (double)sentences / words * 100;
    double index = 0.0588 * L - 0.296 * S - 15.8;
    int indexround = round(index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (indexround < 17 && index >= 1)
    {
        printf("Grade %i\n" , indexround);
    }
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
}





int count_letters(string txt)
{
    int l = strlen(txt);
    int lamount = 0;
    for (int i = 0; i < l ; i++)
    {
        if (isupper(txt[i]) > 0 || islower(txt[i]) > 0)
        {
        lamount++;
        }
    }
    return lamount;
}


int count_words(string txt)
{
    int l = strlen(txt);
    int wamount = 1;
    for (int i = 0; i < l ; i++)
    {
        if ((int)txt[i] == 32 )
        {
            wamount++;
        }
    }
    return wamount;
}


int count_sentences(string txt)
{
    int l = strlen(txt);
    int samount = 0;
    for (int i = 0; i < l ; i++)
    {
        if ((int)txt[i] == 46 || (int)txt[i] == 33 || (int)txt[i] == 63 )
        {
            samount++;
        }
    }
    return samount;
}