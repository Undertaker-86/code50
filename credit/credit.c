#include <cs50.h>
#include <stdio.h>
#include <math.h>

long get_credit(void);
void verify_credit(long number);

int main(void)
{
    //Get the credit card number
    long n = get_credit();

    //Verifying the credit card number
    verify_credit(n);
}

long get_credit(void)
{
    long n = get_long("What is your credit card number: ");
    return n;
}

void verify_credit(long number)
{
    int n, verify = 0;
    for (int i = 1; i < 9; i++)
    {
        //printf("%d\n", verify);
        n = 2 * (((number / (long)(pow(10, 2*i - 1))))%10);
        //printf("%d\n", n);
        if (n >= 10)
        {
            verify += n - 9; //because n will always be less than or equal to 18
        }
        else
        {
            verify += n;
        }
        n = (number / (long)(pow(10, 2*i - 2)))%10;
        //printf("%d\n", n);
        verify += n;
    }
    if ((verify % 10) != 0)
    {
        printf("INVALID\n");
    }
        else if (((number / (long)(pow(10, 14)))) == 51 || ((number / (long)(pow(10, 14)))) == 52 || ((number / (long)(pow(10, 14)))) == 53 || ((number / (long)(pow(10, 14)))) == 54 || ((number / (long)(pow(10, 14)))) == 55)
    {
        printf("MASTERCARD\n");
    }
        else if (((number / (long)(pow(10, 13)))) == 34 || ((number / (long)(pow(10, 13)))) == 37)
    {
        printf("AMEX\n");
    }
    else if (((number / (long)(pow(10, 15)))) == 4 || ((number / (long)(pow(10, 12)))) == 4 )
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}