#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover infile\n");
        return 1;
    }

    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Cannot open file\n");
        return 2;
    }

    BYTE buffer[512];
    int count = 0;
    char name[8];
    FILE *outptr = NULL;

    while (fread(buffer, 512, 1, inptr) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ( (buffer[3] & 0xf0) == 0xe0))
        {
            sprintf(name, "%.3i.jpg", count);
            outptr = fopen(name, "w");
            count++;
        }

        if (outptr != NULL)
        {
            fwrite(buffer, 512, 1, outptr);
        }
    }
}