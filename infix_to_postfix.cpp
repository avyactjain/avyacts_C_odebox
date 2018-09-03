#include<stdio.h>
#include<iostream>

#define size 100
char stack[size];
int top = -1;

void push(char item)
{
    if(top>=size-1)
    {
        printf("Stack Overflow! Push not possible.\n");
    }
    else
    {
        top++;
        stack[top] = item;
    }

}

int is_operator(char symbol)
{
 if((symbol=='^' || symbol == '*' )|| (symbol == '/' || symbol =='+' ||symbol=='-'))
 {
     return 1;
 }
 else
 {
     return 0;
 }
}

char pop()
{
    char item;
    item = stack[top];
    top--;
    return item;
}

int precedence(char symbol)
{
    if(symbol =='^')
    return 3;
    else if(symbol == '*' || symbol == '/')
    return 2;
    else if(symbol == '+' || symbol =='-' )
    return 1;
    else 
    return 0;
}
int main()
{
    char infix[size],postfix[size];
    char item,temp;

    int i = 0, j = 0; //these are loop counters. one for infix array and other for postfix array
    
    printf("Enter your infix expression \n");
    gets(infix);

    while(infix[i] != '\0')
    {
        item = infix[i];
        if(item == '(')
        {
            push(item);
        }
        else if((item>='A' && item<='Z') || (item >='a' && item<='z'))
        {
            postfix[j] = item;
            j++;
        }
        else if(is_operator(item) == 1)
        {
            temp = pop();
            while(is_operator(temp)==1 && precedence(temp)>=precedence(item))
            {
                postfix[j] = temp;
                j++;
                temp = pop();
            }
            push(temp);
            push(item);
        }
        else if(item == ')')
        {
            temp = pop();
            while(temp != '(')
            {
                postfix[j] = temp;
                j++;
                temp = pop();
            }
        }
        else
        {
            printf("Invalid Infix Operation! \n");
            exit(0);
            getchar();
        }
        i++;
    }

    while(top>-1)
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    printf(" \n Arithmetic Expression in Postfix notation is : ");
    puts(postfix);
    
    return 0;
}