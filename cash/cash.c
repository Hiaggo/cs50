#include <stdio.h>
#include <cs50.h>
#include <math.h>

void change(float cash)
{
    int coin_number = 0;
    int cents = round(cash * 100);
    while (cents > 0)
    {
        if (cents >= 25)
        {
            coin_number += 1;
            cents -= 25;
            // printf("1cash: %i\n", cents);
        }

        else if (cents >= 10)
        {
            coin_number += 1;
            cents -= 10;
            // printf("2cash: %i\n", cents);
        }

        else if (cents >= 5)
        {
            coin_number += 1;
            cents -= 5;
            // printf("3cash: %i\n", cents);
        }

        else if (cents >= 1)
        {
            coin_number += 1;
            cents -= 1;
            // printf("4cash: %i\n", cents);
        }
    }
    printf("%i\n", coin_number);
}

int main(void)
{
    float cash;
    do
    {
        cash = get_float("Change owed: ");
    }
    while (cash < 0);
    change(cash); // Calls the function to count how many coins
}