#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void cypher(string text, int key)
{
    char sum;
    for (int i = 0; i < strlen(text); i++)
    {
        sum = 0;
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            sum = text[i] - 65 + key; // Subtracts this amount from the letters so they can be calculated correctly
            sum = sum % 26;
            text[i] = sum + 65; // Adds the amount back so the right ASCII character can show up on the screen
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            sum = text[i] - 97 + key; // Subtracts this amount from the letters so they can be calculated correctly
            sum = sum % 26;
            text[i] = sum + 97; // Adds the amount back so the right ASCII character can show up on the screen
        }
    }
    printf("ciphertext: %s\n", text);
}

int main(int argc, string argv[])
{
    if (!argv[1] || (argc > 2))
    {
        printf("Usage: ./caesar key\n"); // No argument or more than one
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n"); // Non digit character
            return 1;
        }
    }
    string plaintext = get_string("plaintext: ");
    int key =  atol(argv[1]);
    cypher(plaintext, key);
    return 0;
}