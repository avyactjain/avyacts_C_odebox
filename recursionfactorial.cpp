#include<stdio.h>
#include<iostream>

int factorial(int x)
{
    int fact = 1;

    if ( x ==1 )
    {
        return 1;
    }

    fact = x * factorial(x-1);
    return fact;
}

int main()
{
    int ui;
    printf("Enter the number you want to find factorial of --- > ");
    scanf("%i",&ui);
    printf("The Factorial of %i is %i \n",ui,factorial(ui));
    return 0;
}