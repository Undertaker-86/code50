#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        }

    }


    char *decrypted = get_string("Plaintext: ");
    int shift = atoi(argv[1]);
    printf("ciphertext: ");

    for (int i = 0; i < strlen(decrypted); i++)
    {
        if (decrypted[i] <= 90 && decrypted[i] >= 65)
        {
            int alphabet = (decrypted[i]- 65 + shift) % 26;
            printf("%c", alphabet + 65);
        }

        else if (decrypted[i] >= 97 && decrypted[i] <= 122)
        {
            int alphabet = (decrypted[i] - 97 + shift) % 26;
            printf("%c", alphabet + 97);
        }

        else
        {
            printf("%c", decrypted[i]);
        }
    }
    printf("\n");
}