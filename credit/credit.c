#include <stdio.h>
#include <cs50.h>
#include <math.h>

void card_checker(long int card)
{
    int n = trunc(card / 1000000000000); // Divides to check the lowest amount of digits
    if (n == 4)
    {
        printf("VISA\n");
        return;
    }

    else if (n / 100 == 51 || n / 100 == 52 || n / 100 == 53 || n / 100 == 54 || n / 100 == 55)
    {
        printf("MASTERCARD\n");
        return;
    }

    else if (n / 10 == 34 || n / 10 == 37)
    {
        printf("AMEX\n"); // American Express
        return;
    }

    else if (n / 1000 == 4)
    {
        printf("VISA\n");
        return;
    }
    printf("INVALID\n"); // Passed through all the other tests but it isn't one of the card brands we're looking for
}

void credit_card(long int card)
{

    int sum = 0;
    int rest = 0;
    long int card_op = card;
    for (int i = 0; i < 16; i++) // Picks two digits at once
    {
        sum += card_op % 10;
        card_op = card_op / 10;
        rest = (card_op % 10) * 2;
        if (rest >= 10) // if the product is more than 10, splits into two digits
        {
            sum += rest % 10;
            sum += rest / 10;
        }
        else // if the product is only one digit
        {
            sum += rest;
        }
        card_op = card_op / 10;
    }
    if (sum % 10 == 0)
    {
        card_checker(card); // Checks what credit card this is, if one at all
    }
    else
    {
        printf("INVALID\n");
    }
}

int main(void)
{
    long int card;
    card = get_long("Number: ");
    credit_card(card);
}