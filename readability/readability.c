#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

void grade_checker(string text);

int main(void)
{
    string text = get_string("Text: ");
    grade_checker(text);
    return 0;
}

float count_words(string text)
{
    float word_count = 1; // Counts the words
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            word_count += 1;
        }
    }
    return word_count;
}

float count_sentences(string text)
{
    float sentence_count = 0; // Counts the sentences
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count += 1;
        }
    }
    return sentence_count;
}

float count_letters(string text)
{
    float letter_count = 0; // Counts the letters
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letter_count += 1;
        }
    }
    return letter_count;
}

void grade_checker(string text)
{

    float letter_count = count_letters(text);
    float word_count = count_words(text);
    float sentence_count = count_sentences(text);

    // printf("letras: %.0f ", letter_count);
    // printf("word: %.0f ", word_count);
    // printf("frases: %.0f\n", sentence_count);

    float L = (100 * letter_count) / word_count; // Letters per 100 words
    float S = (100 * sentence_count) / word_count; // Sentences per 100 words

    int grade_value = round(0.0588 * L - 0.296 * S - 15.8); // the Coleman-Liau index

    if (grade_value > 16)
    {
        printf("Grade 16+\n");
    }

    else if (grade_value < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %i\n", grade_value);
    }
}
