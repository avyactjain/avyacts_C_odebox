#include<stdio.h>
#include<iostream>

void TOH(int n, char BEG, char AUX, char END)
{
    if(n>=1)
    {
        TOH(n-1,BEG,END,AUX); //Shift n-1 disks from begining to ending using auxiliary
        printf("Shift %c to %c \n",BEG,END); 
        TOH(n-1,AUX,BEG,END); // Shift disks on auxiliary to end using begining
    }
}


int main()
{
    char A = 'A';
    char B = 'B';
    char C = 'C';
    TOH(3,A,B,C);
    return 0;
}