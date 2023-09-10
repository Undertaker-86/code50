// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    long header_array[HEADER_SIZE];

    for (int i = 0; i < HEADER_SIZE; i++)
    {
        fscanf(input, " %ld", &header_array[i]);
    }

    for (int i = 0; i < HEADER_SIZE; i++)
    {
        fprintf(output, "%ld ", header_array[i]);
    }
    // TODO: Read samples from input file and write updated data to output file

    u_int16_t input_sound;
    while (fscanf(input, "%lf ", &input_sound))
    {
        fprintf(output, "%lf ", input_sound * factor);
    }
    // Close files
    fclose(input);
    fclose(output);
}
