#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedList{
    int val;
    struct LinkedList *next;
}node;
void ins_b(node **head,int a)
{
    node *new;
    new= (node *) malloc (sizeof(node));
    new->val=a;
    new->next=*head;
    *head=new;
}
void ins_e(node **head,int a)
{
    node *new,*p;
    new= (node *) malloc(sizeof(node));
    new->val=a;
    new->next=NULL;
     if (*head == NULL)
        *head = new;
    else
    {
        p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = new; // Add the new node to the end of the list
    }
}
void display(node * p)
{
    if (p==NULL) printf("\n the list is empty \n");
    printf("\n the elements of list : \n");
    while(p!=NULL)
    {
     printf("%d\n",p->val);
     p=p->next;
    }
}
void pos_i(node ** head, int pos, int a)
{
        node *new;
    node *q,*p;
    int i;
    new= (node *) malloc (sizeof(node));
    new->val=a;
    if(pos==1)
    {
        new->next=*head;
        *head=new;
    }
    else
    {
        i=1;
        p=*head;
        q=NULL;
        while(p != NULL && i<pos )
        {
            i++;
            q=p;
            p=p->next;
        }

        if(p==NULL)
            printf("the position is greater than the size of the list");
        else
        {
            new->next=p;
            q->next=new;
        }
    }
}
void add_eba(node **head,int a,int x)
{
    node *p,*q;
    node *new;
    new= (node *) malloc (sizeof(node));
    new->val=a;
    if(head == NULL)
    {
        printf("\n the list is empty \n");
        return NULL;
    }
    if((*head)->val==x)
    {
        new->next=*head;
        *head=new;
    }
    else
    {
        p=*head;
        q=NULL;
        while(p!=NULL && p->val != x)
        {
            q=p;
            p=p->next;
        }
        new->next=p;
        q->next=new;
    }
}
void add_eaa(node **head,int a,int x)
{
    node *p;
    node *new;
    new= (node *) malloc (sizeof(node));
    new->val=a;
    if((*head)->val==x)
    {
        new->next=*head;
        *head=new;
    }
    else
    {
        p=*head;
        while(p!=NULL && p->val != x)
        {
            p=p->next;
        }
        new->next=p;
    }
}
void del_b(node **head)
{
    node *p;
    if(head == NULL)
        return NULL;
    p=*head;
    *head=(*head)->next;
    free(p);
}
void del_e(node **head)
{
    node *p,*q;
    p = *head;
    if(head == NULL)
        return NULL;
    while (p->next != NULL)
    {
            q=p;
            p = p->next;
    }
    q->next=NULL;
    free(p);      

}
void sum_occ(node *head,int x)
{
    node *p;
    p=head;
    int c=0;
    if(head==NULL)
    {
        printf("list is empty\n");
        return NULL;
    }
    else
    {
    while(p!=NULL)
    {
        if(p->val==x)
            c=c+1;
        p=p->next;
    }
    }
    printf("number of occurrences is %d\n",c);
}
int main()
{
    node *head = NULL;
    int a,b,x,choice;
        do
        {
            printf("\n\n\n");
            printf("  __  __ ______ _   _ _    _ \n");
            printf(" |  \\/  |  ____| \\ | | |  | |\n");
            printf(" | \\  / | |__  |  \\| | |  | |\n");
            printf(" | |\\/| |  __| | . ` | |  | |\n");
            printf(" | |  | | |____| |\\  | |__| |\n");
            printf(" |_|  |_|______|_| \\_|\\____/\n");
            printf("---------------------------------------------\n");
            printf("[1]. ins begin\n");
            printf("[2]. ins end\n");
            printf("[3]. add in position\n");
            printf("[4]. add after element \n");
            printf("[5]. add befor element\n");
            printf("[6]. delet begin\n");
            printf("[7]. delet end\n");
            printf("[8]. Display\n");
            printf("[9]. SUM of occurrences of element in list\n");
            printf("[0]. Exit\n");
            printf("Enter your choise : \n");
            scanf(" %d",&choice);
            switch(choice)
            {
            case 1:
                do
                {
                printf("enter val :");
                scanf("%d",&a);
                ins_b(&head,a);
                printf("1- add another \n0- exit \nEnter Number:");
                scanf("%d",&b);
                if(!b)
                break;
                }while(1);
                break;
            case 2:
                do
                {
                printf("enter val :");
                scanf("%d",&a);
                ins_e(&head,a);
                printf("1- add another \n0- exit \nEnter Number:");
                scanf("%d",&b);
                if(!b)
                break;
                }while(1);
                break;
            case 3:
                do
                {
                printf("enter val :");
                scanf("%d",&a);
                printf("enter position :");
                scanf("%d",&x);
                pos_i(&head,x,a);
                printf("1- add another \n0- exit \nEnter Number:");
                scanf("%d",&b);
                if(!b)
                break;
                }while(1);
                break;
            case 4:
                do
                {
                printf("enter val :");
                scanf("%d",&a);
                printf("enter element :");
                scanf("%d",&x);
                add_eaa(&head,a,x);
                printf("1- add another \n0- exit \nEnter Number:");
                scanf("%d",&b);
                if(!b)
                break;
                }while(1);
                break;
            case 5:
                do
                {
                printf("enter val :");
                scanf("%d",&a);
                printf("enter element :");
                scanf("%d",&x);
                add_eba(&head,a,x);
                printf("1- add another \n0- exit \nEnter Number:");
                scanf("%d",&b);
                if(!b)
                break;
                }while(1);
                break;
            case 6:
                del_b(&head);
                break;
            case 7:
                del_e(&head);
                break;
            case 8:
                display(head);
                break;
            case 9:
                printf("enter val :");
                scanf("%d",&x);
                sum_occ(head,x);
                break;
            default:
                exit(0);
            }
        }while(1);
}




    /*ins_b(&head,5);
    ins_b(&head,4);
    ins_b(&head,3);
    ins_b(&head,2);
    ins_b(&head,1);
    ins_b(&head,0);
    ins_e(&head,6);
    ins_e(&head,7);
    ins_e(&head,8);
    ins_e(&head,8);
    ins_e(&head,8);
    ins_e(&head,8);
    ins_e(&head,8);
    ins_e(&head,8);
    ins_e(&head,9);
    ins_e(&head,10);
    ins_e(&head,11);
    ins_e(&head,12);
    pos_i(&head,2,99);
    pos_i(&head,5,66);
    pos_i(&head,10,33);
    ins_e(&head,110);
    add_eaa(&head,120,4);
    add_eaa(&head,1276,4);
    add_eba(&head,760,9);
    add_eba(&head,260,9);
    ins_e(&head,99999999);
    del_b(&head);
    del_e(&head);
    display(head);
    sum_occ(head,8);*/