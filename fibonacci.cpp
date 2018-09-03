#include<stdio.h>
#include<iostream>


int fib(int a)
{
    if ( a == 1 | a == 2)
    {
        return 1;
    }
    else
    {
        int i = fib(a-1);
        int j = fib(a-2);
        return i+j;
    }
}

int main(){
    printf("%i \n",fib(9));
    return 0;
}