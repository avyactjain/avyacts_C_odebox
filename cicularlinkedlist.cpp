#include<stdio.h>
#include<iostream>

struct node{
    int data;
    struct node *next;
};

struct node* createList(struct node *last);
void display (struct node *last);
struct node* addtoempty(struct node *last, int value);
struct node* addatbeg(struct node *last, int value);
struct node* addatend(struct node *last, int value);
struct node* addafter(struct node*last, int value,int item);
struct node* del(struct node *last, int value);

struct node* addatbeg(struct node *last, int value)
{
    //return type is pointer to node.
    //create a new node and store its address in a pointer to node 'n'
    //give the data part to the new node
    //make n->next = last->next. now n is the first node.
    // make last -> next = n
    // return last ( pointer to node )
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = value;
    n->next = last->next;
    last->next = n;
    return(last);
}

void display(struct node *last)
{
    struct node *t;
    if(last == NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        t = last->next; //t now contains the address of first node
        do //Simply means, untill t attains its value back. iterate the loop
        {
        printf("%i\n", t->data); //Printing the first value .
        t = t->next;
        }while(t!= last->next); 
        //Application of do while loop above. 
    }
}

struct node* addtoempty(struct node *last, int value)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = value;
    last = n;
    last->next= last; //Node is pointing to itself
    return last;
}

struct node* addatend(struct node *last, int value)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = value;
    n->next = last -> next;
    last->next = n;
    last = n;
    return last;
}

struct node* addafter(struct node*last, int value, int item) //item is the entry after which i will insert the node
{
    struct node *t;
    t = last->next;
    do{
    if(t->data == item)
    {
        struct node *n;
        n = (struct node*)malloc(sizeof(struct node));
        n -> data = value;
        n->next = t->next;
        t->next = n;
        if( t == last)
        {
            last = n;
        }
        return last;
    }
    t = t->next;
    }while(t!=last->next); //untill t gets its value back
    printf("%i is not in the list. \n",item);
    return last;
}

struct node* del(struct node *last, int value)
{
    struct node *t,*p;
    if(last == NULL)
    {
        printf("List is empty! \n");
        return last;
    }

    if(last == last->next && last->data == value) //only one node in list and it contains the value we want to delete
    {
        t = last;
        last = NULL;
        free(t);
        return last;
    }

    if(last->next->data == value) //deleting first node
    {
        t = last->next; //t pointing first element
        last -> next = t->next;
        free(t);
        return last;
    }

    p = last->next; //p is pointing to fist element.
    while(p->next != last)
    {
        if ( p->next->data == value) //because we have checked for the first value
        {
            t = p->next;
            p->next = t->next;
            free(t);
            return last;
        }
        p = p->next;
    }

    if ( last->data == value)
    {
        t = last;
        p->next = t->next;
        last = p;

        free(t);
        return(last);
    }
    printf("%i Not Found!\n",value);
    return last;
}


struct node* createList(struct node *last)
{
    int n,value;
    int i; //for the loop
    printf("How many values you want to enter? ");
    scanf("%i",&n);
    printf("\n");
    printf("Enter data 1 for the list. ");
    scanf("%i",&value);

    last = addtoempty(last,value);

    for (i=2; i<=n;i++) //i=2 because we already took the first value
    {
        printf("Enter data %i for the list. ",i);
        scanf("%i",&value);
        last = addatend(last,value);
    }
    return last;
}


int main()
{
    printf("Welcome to Doubly Linked List! \n");
    int choice,value,item;
    struct node *last = NULL;
    while(1)
    {
        
        printf("\n 1. Create List ");
        printf("\n 2. Display List ");
        printf("\n 3. Add to Empty List ");
        printf("\n 4. Add at Begining ");
        printf("\n 5. Add at End ");
        printf("\n 6. Add after ");
        printf("\n 7. Delete ");
        printf("\n 8. Exit! ");
        printf("\n");

        printf("Enter your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            last = createList(last);
            break;

            case 2:
            display(last);
            break;

            case 3:
            printf("Enter a Number for the list ");
            scanf("%d", &value);
            last = addtoempty(last,value);
            break;

            case 4:
            printf("Enter a Number for the list ");
            scanf("%d", &value);
            last = addatbeg(last,value);
            break;

            case 5:
            printf("Enter a Number for the list ");
            scanf("%d", &value);
            last = addatend(last,value);
            break;

            case 6:
            printf("Enter a Number for the list ");
            scanf("%d", &value);
            printf("Enter item value after new value to be inserted. \n");
            scanf("%d",&item);
            last = addafter(last,value,item);
            break;

            case 7:
            printf("Enter Value of element to be deleted. ");
            scanf("%d", &value);
            last = del(last,value);

            case 8:
            exit(0);

            default:
            printf("Invalid Choice! \n");
        }
        getchar();
    }
    return 0;
}