#include <cs50.h>
#include <stdio.h>


int main(void)
{

    long cnum;
    do
    {
        cnum = get_long("Type in your credit card number:\n");
    }
    while (cnum <= 0);

    //folgende zahlen beginnen von hinten num1 = ziffer nummer 16
    int num1, num2, num3, num4, num5, num6, num7, num8;
    num1 = (cnum %100 / 10) * 2;
    num2 = (cnum %10000 / 1000) *2;
    num3 = (cnum %1000000 / 100000) *2;
    num4 = (cnum %100000000 / 10000000)*2;
    num5 = (cnum %10000000000 / 1000000000)*2;
    num6 = (cnum %1000000000000 / 100000000000)*2;
    num7 = (cnum %100000000000000 / 10000000000000)*2;
    num8 = (cnum %10000000000000000 / 1000000000000000)*2;

    num1 = (num1 %100 / 10) + (num1 %10);
    num2 = (num2 %100 / 10) + (num2 %10);
    num3 = (num3 %100 / 10) + (num3 %10);
    num4 = (num4 %100 / 10) + (num4 %10);
    num5 = (num5 %100 / 10) + (num5 %10);
    num6 = (num6 %100 / 10) + (num6 %10);
    num7 = (num7 %100 / 10) + (num7 %10);
    num8 = (num8 %100 / 10) + (num8 %10);

    int sum1 = num1 + num2 + num3 + num4 + num5 + num6 +num7 + num8;


    int num9, num10, num11, num12, num13, num14, num15, num16;
     num9 = (cnum %10);
    num10 = (cnum %1000 / 100);
    num11 = (cnum %100000 / 10000);
    num12 = (cnum %10000000 / 1000000);
    num13 = (cnum %1000000000 / 100000000);
    num14 = (cnum %100000000000 / 10000000000);
    num15 = (cnum %10000000000000 / 1000000000000);
    num16 = (cnum %1000000000000000 / 100000000000000);

    int sum2 = num9 + num10 + num11 + num12 + num13 + num14 + num15 + num16;

    int sum = sum1 + sum2;


    if (sum %10 !=0) //!=0 bedeutet ungleich null
    {
        printf("INVALID\n");
        return 0;//sollte das programm beenden!!!!!!!
    }

    int length;
    long visa = cnum;
    long master = cnum;
    long amex = cnum;


    for (length = 0; cnum > 0 ; length++)
    {
        cnum = cnum / 10;
    }

    //visa
    while (visa > 9)
    {
        visa = visa / 10;   // identisch zu "visa /=10"
    }

    if (visa == 4 && (length == 13 || length == 16))
    {
        printf("VISA\n");
        return 0;
    }

    //amex
    while (amex >= 100)
    {
        amex /= 10;
    }


    if ((amex == 34 || amex == 37) && length == 15)
    {
        printf("AMEX\n");
        return 0;
    }

    //master
    while (master >= 100)
    {
        master /= 10;
    }

    if ((50 < master && master < 56) && length == 16)     //möglich?
    {
        printf("MASTER CARD\n");
        return 0;
    }

    else
    printf("INVALID.bottom\n");
    return 0;

}