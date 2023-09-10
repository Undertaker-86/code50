/*
 * Author           : Gyan Edbert Zesiro
 * Student Number   : 38600060
 * Lab Section      : L2E
 * Email            : gzesiro@student.ubc.ca
 * Date             : 28th February 2023
 * Purpose          : create a function
 *                    that outputs the average
 *                    of the last n number
 *                    in an array
*/

#include <stdio.h>
#include <math.h>

double sum = 0;

for (int i = 0; i < 10000000; i++)
{
    sum += pow(-1, i) / i;
}

printf("%f\n", sum);