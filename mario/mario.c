#include <cs50.h>
#include <stdio.h>

void print_pyramid(int height)
{
    int i, j;
    i = 0;
    j = 0;
    for (i = 1; i < height + 1; i++)
    {
        for (j = 0; j < height - i; j++)
        {
            printf(" "); // Adds every blank space character
        }
        for (j = 0; j < i; j++)
        {
            printf("#"); // Adds the hash character according to i
        }
        for (j = 0; j < i; j++)
        {
            if (j == 0)
            {
                printf("  "); // Separates both half pyramids
            }
            printf("#"); // Adds the hash character as in the 'for' before this one
        }
        if (i < height)
        {
            printf("\n"); // Breaks the line checking if it isn't the last row
        }
    }
}

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: "); // Receives the height of the pyramid
    }
    while (height < 1 || height > 8); // Loop to check if the user is writting a valid input
    print_pyramid(height); // Calling the function to print the pyramid following the height the user chose
    printf("\n");
}