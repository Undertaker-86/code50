
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("See instruction for futher detail\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    uint8_t buffer[512];


    FILE* output = NULL;
    char filename[8];
    int i = 0;

    while (fread(buffer, 512, 1, input) == 1)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (i > 0)
            {
                fclose(output);
            }
            sprintf(filename, "%.3d.jpg", i);
            output = fopen(filename, "w");
            i++;
        }

        if (output != NULL)
        {
            fwrite(buffer, 512, 1, output);
        }
    }

    fclose(input);
    fclose(output);
}
