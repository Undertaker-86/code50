#include <cs50.h>
#include <stdio.h>

int get_input();
int x, y, n, i, j;
void print_block(int size);

int main(void)
{
    //get height input from user
    get_input();

    //the print block function
    print_block(n);
}

int get_input(void)
{
    //get number between 1 and 8, inclusive
    do
    {
        n  = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    //return number
    return n;
}

void print_block(int size)
{
    //to not modify size
    x = size;
    //left side of the gap
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (j < x - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        //the gap
        for (y = 0; y < 2; y++)
        {
            printf(" ");
        }
        //right side of the gap
        for (; j > x - 1; j--)
        {
            printf("#");
        }
        x--;
        printf("\n");
    }
}