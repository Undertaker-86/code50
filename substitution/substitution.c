#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    bool key = true, full = true;
    int i, n;

    if (argc >= 2)
    {
        //check if the argument is all letter
        for (i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                key = false;
            }
        }

        //check if the argument contains 26 letter
       for (i = 0, n = strlen(argv[1]); i < n; i++)
        {

        }
        //printf("%i", i);
        if (i != 26)
        {
            full = false;
        }

        //check if there is a duplicate in the argument
        for (i = 0, n = strlen(argv[1]); i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (toupper(argv[1][i]) == toupper(argv[1][j]))
                {
                    key = false;
                }
            }
        }
    }

    //check if all condition is fulfilled
    if (argc == 2 && key == true && full == true)
    {

        string text = get_string("plaintext: ");
        printf("ciphertext: ");

        for (i = 0, n = strlen(text); i < n; i++)
        {
            if (islower(text[i]))
            {
                text[i] = toupper(text[i]);
                for (int j = 0; j < 26; j++)
                {
                    if (text[i] == 'A' + j)
                    {
                        printf("%c", tolower(argv[1][j]));
                    }
                }
            }

            else if (isupper(text[i]))
            {
                text[i] = toupper(text[i]);
                for (int j = 0; j < 26; j++)
                {
                    if (text[i] == 'A' + j)
                    {
                        printf("%c", toupper(argv[1][j]));
                    }
                }
            }

            else
            {
                printf("%c", text[i]);
            }
        }
        printf("\n");
    }

    else if (full == false)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}