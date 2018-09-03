#include<stdio.h>
#include<iostream>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* start = NULL; //created a pointer to node. called start. NULL initially.

void insertAtFirst()
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->next = NULL;
    printf("Enter the value that you want to enter -->");
    scanf("%i",&n->data); 

    if(start == NULL)
    {
        start = n;
    }
    else
    {
        n->next = start;
        start = n;
    }
}

void viewList()
{
    struct node *t; //Temp
    if (start == NULL)
    {
        printf("List is Empty ! \n");
    }
    else
    {
        t = start;
        while(t->next!=NULL)
        {
            printf(" %i \n",t->data);
            t = t->next;
        }
        printf(" %i \n",t->data); //Just to print the last element of the linked list. 
    }
}

int main()
{
    for(int i = 0; i < 5; i++)
    {
        insertAtFirst();
    }
    viewList();
    return 0;
}