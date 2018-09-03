#include<stdio.h>
#include<iostream>
#include<stdlib.h>
struct node
{
int info;
struct node *prev, *next ; //Created to pointer to nodes. one for next node other for previous node
};

struct node* start = NULL; //Created a pointer to node called start. it is null because it is the starting point of the ll is empty
void insertAsFirstNode()
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    //n is a pointer to node which contains address of a new node that i just created
    printf("Enter a Number \n");
    scanf("%i", &n->info);
    n->prev = NULL;
    n->next = NULL;
    if(start == NULL)
    {
        start = n;    
    }
    else
    {
        start -> prev = n;
        n -> next = start;
        start =  n;
    }

}

void deleteFirstNode()
{
    struct node *r;
    if ( start == NULL)
    {
        printf("List is Empty! \n");
    }
    else
    {
        r = start; //r now has address of start
        start = start -> next;
        start->prev = NULL;
        free(r);
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
            printf(" %i \n",t->info);
            t = t->next;
        }
        printf(" %i \n",t->info); //Just to print the last element of the linked list. 
    }
}

void viewAtPosition(int a)
{
    struct node *p; //Temp
    int x = 0;
    if(start == NULL)
    {
        printf("List is Empty");
    }
    else
    {
        p = start;
        while(x<a-1)
        {
        p = p->next;
        x++ ; 
        }
        printf("Value at position %i is %i\n",a,p->info);
    }   
}

void insertAtPosition(int a)
{
    struct node *p; //Temp
    int x = 0;
    if(start == NULL)
    {
        printf("List is Empty");
    }
    else
    {
        p = start;
        while(x<a-1)
        {
        p = p->next;
        x++ ; 
        }
    }
    if(p->prev == NULL)
    {
        printf("Can't be inserted! \n");
    }  
    else
    {
        struct node* toinsert = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value you want to insert ---->\n");
        scanf("%i",&toinsert->info);
        toinsert->next = p->next;
        p->next = toinsert;
        toinsert->prev = p; 
    }
    
}


int main(){ //Driver Program
    int counter = 0;
    for(int i = 0; i < 5; i++)
    {
        insertAsFirstNode();
    }
    printf("========= \n");
    viewAtPosition(4);
    viewList();
    insertAtPosition(4);
    printf("========= \n");
    viewList();
    return 0;
}