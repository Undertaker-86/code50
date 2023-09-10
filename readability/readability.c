#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int i = 0, sentence = 0, letter = 0, comma = 0;
    float words = 0.0;
    string text = get_string("Text: ");
    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }

        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence++;
        }

        else if(text[i] == ',' || (int) text[i] == 39 || (int) text[i] == 34 || text[i] == ';')
        {
            comma++;
        }

        else
        {
            letter++;
        }
        }

    words++;
    printf("%i, %i, %f", letter, sentence, words);
    float L = ((float) letter / words) * 100;
    float S = ((float) sentence / words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(round(index) > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}