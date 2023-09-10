#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    // Read header into an array
    // TODO #3
    WAVHEADER wh;
    fread(&wh, sizeof(WAVHEADER), 1, input);
    //printf("%li\n", ftell(input));

    // Use check_format to ensure WAV format
    // TODO #4
    int check = check_format(wh);
    if (check == 1)
    {
        fclose(input);
        printf("Unsupported file type\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5

        FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not write file\n");
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&wh, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7

    int sample = get_block_size(wh);
    if (sample == 0)
    {
        printf("No audio file\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    // Write reversed audio to file
    // TODO #8
    BYTE trash[sample];
    int n = 0;
    int first = ftell(input);
    fseek(input, 0, SEEK_END);
    int last = ftell(input);
    int steps = (last - first) / sample;

    for (int i = 1; i <= steps; i++)
    {
        fseek(input, -i*sample, SEEK_END);
        fread(trash, sample, 1, input);
        fwrite(trash, sample, 1, output);
    }
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] != 'W' || header.format[1] != 'A' || header.format[2] != 'V' || header.format[3] != 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    if (header.bitsPerSample != 0)
    {
        return header.bitsPerSample * header.numChannels / 8;
    }
    return 0;
}