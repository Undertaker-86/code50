#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (argc == 2)
    {
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 character\n");
            return 1;
        }

        if (strlen(argv[1]) == 26)
        {
            for (int i = 0; i < 26; i++)
            {
                argv[1][i] = toupper(argv[1][i]);
            }
            for (int i = 0; i < 26; i++)
            {
                if (!isalpha(argv[1][i]))
                {
                printf("Usage: ./substitution key\n");
                }
            }
        for (int i = 0; i < 26; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("Duplicate character found\n");
                    return 1;
                }
            }
        }
        }

    }

    char *decrypted = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, n = strlen(decrypted); i < n; i++)
    {
        if (decrypted[i] >= 65 && decrypted[i] <= 90)
        {
            int temp = argv[1][decrypted[i] - 65];
            printf("%c", temp);
        }

        else if (decrypted[i] >= 97 && decrypted[i] <= 122)
        {
            int temp = argv[1][decrypted[i] - 97];
            printf("%c", temp + 32);
        }

        else
        {
            printf("%c", decrypted[i]);
        }
    }
    printf("\n");

}