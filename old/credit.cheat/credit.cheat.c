#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long cnum;
    do
    {
        cnum = get_long("Card number: ");
    }
    while (cnum < 0);


    //luhn's algorithm
    int card1, card2, card3, card4, card5, card6, card7, card8;
    card1 = ((cnum % 100)/10)*2;
    card2 = ((cnum % 10000)/1000)*2;
    card3 = ((cnum % 1000000)/100000)*2;
    card4 = ((cnum % 100000000)/10000000)*2;
    card5 = ((cnum % 10000000000)/1000000000)*2;
    card6 = ((cnum % 1000000000000)/100000000000)*2;
    card7 = ((cnum % 100000000000000)/10000000000000)*2;
    card8 = ((cnum % 10000000000000000)/1000000000000000)*2;

    card1 = (card1 % 100/10) + (card1 % 10);
    card2 = (card2 % 100/10) + (card2 % 10);
    card3 = (card3 % 100/10) + (card3 % 10);
    card4 = (card4 % 100/10) + (card4 % 10);
    card5 = (card5 % 100/10) + (card5 % 10);
    card6 = (card6 % 100/10) + (card6 % 10);
    card7 = (card7 % 100/10) + (card7 % 10);
    card8 = (card8 % 100/10) + (card8 % 10);

    int sum1 = card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8;


    int card9, card10, card11, card12, card13, card14, card15, card16;
    card9 = (cnum % 10);
    card10 = ((cnum % 1000)/100);
    card11 = ((cnum % 100000)/10000);
    card12 = ((cnum % 10000000)/1000000);
    card13 = ((cnum % 1000000000)/100000000);
    card14 = ((cnum % 100000000000)/10000000000);
    card15 = ((cnum % 10000000000000)/1000000000000);
    card16 = ((cnum % 1000000000000000)/100000000000000);

    int sum2 = card9 + card10 + card11 + card12 + card13 + card14 + card15 + card16;


    int sum3 = sum1 + sum2;


    if((sum3 %10) !=0)
    {
        printf("INVALID\n");
        return 0;
    }





    int length = 0;
    long visa = cnum;
    long master = cnum;
    long amex = cnum;


    //length
    while (cnum > 0)
    {
        cnum /= 10;
        length++;
    }


    //visa//prüfnummer 4111111111111111
    while (visa >= 10)
    {
        visa /= 10;
    }
    if (visa == 4 && (length == 13 || length == 16))
    {
        printf("VISA\n");
        return 0;
    }


    //amex//prüfnummer 378282246310005
    while (amex >= 10000000000000)
    {
        amex /= 10000000000000;
    }
    if (length == 15 && (amex ==34 || amex == 37))
    {
        printf("AMEX\n");
        return 0;
    }


    //master//prüfnummer 5555555555554444
    while (master >= 100000000000000)
    {
        master /= 100000000000000;
    }
    if (length == 16 && (master == 51 || master == 52 ||
        master == 53 || master == 54 || master == 55))
    {
        printf("MASTER\n");
        return 0;
    }


    //wenn keins davon
    else
    {
        printf("INVALIDE.\n");
        return 0;
    }
}
