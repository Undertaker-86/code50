#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    for (int x = 0; x < 2 ; x++)
    {
        if (argv[1][x] < 48 || argv[1][x] > 57)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {break;}
    }

    if (argv[1] == 0)
    {
        printf("Error\n");
        return 1;
    }

    else if (atoi (argv[1]) < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else if ( atoi (argv[1])  < 0 || atoi (argv[1]) > 2147483647 )
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else {
        int k = (atoi (argv[1])) % 26;
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int i = 0; plaintext[i] != '\0'; i++)
        {
            if (plaintext[i] > 64 && plaintext[i] < 91)
            {
                plaintext[i] += k;
                if (plaintext[i] > 90)
                {
                    plaintext[i] -= 26;
                    printf("%c", plaintext[i]);
                }
                else
                {
                    printf("%c", plaintext[i]);
                }
            }
            else if (plaintext[i] > 96 && plaintext[i] < 123)
            {
                plaintext[i] -= 32;
                plaintext[i] += k;
                if (plaintext[i] > 90)
                {
                    plaintext[i] -= 26;
                    printf("%c", tolower(plaintext[i]));
                }
                else
                {
                    printf("%c", tolower(plaintext[i]));
                }
            }

            else
            {
                printf("%c", plaintext[i]);
            }
        }
    }
    printf("\n");
}
*/