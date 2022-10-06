#include <stdio.h>

int main()
{
    int octal;
    int first, second, third;
    int first_decimal, second_decimal, third_decimal, decimal, sum;

    printf("enter an octal: ");
    scanf("%d", &octal);

    first = (octal % 1000) / 100; // first digit
    second = (octal % 100) / 10; // second digit
    third = octal % 10; // third digit

    first_decimal = first * 64;
    second_decimal = second * 8;
    third_decimal = third;

    decimal = first_decimal + second_decimal + third_decimal;

    sum = ((decimal%1000)/100) + ((decimal%100)/10) + decimal%10;



    printf("decimal:%d , sum: %d \n", decimal, sum);


    return 0;
}