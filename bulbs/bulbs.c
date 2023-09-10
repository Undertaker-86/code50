#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    char *store = get_string("What is your secret message: ");

    int temp = store[0];
    int j = 0;
    while (temp != 0)
    {

        for (int i = 0, divider = 128; i < 8; i++)
        {
        if (temp >= divider)
        {
            print_bulb(1);
            temp -= divider;
        }
        else
        {
            print_bulb(0);
        }
        divider /= 2;
        }

        j++;
        printf("\n");
        temp = store[j];
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
