#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
}*head, *current;

void creat_list(int);
struct node *creat_table(int);
void To_table(struct node *,int);
void To_list(struct node *);

int main(int argc, char const *argv[])
{
    int n,choice;
    printf("if u want to store your data into a list then convert it to a table,click on 1. Otherwise if u want to store your data in a table then converts it to a list, click on 2 : ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Input the number of nodes: ");
        scanf("%d",&n);
        creat_list(n);
        To_table(head,n);
        break;
    case 2:
        printf("Input the number of cases: ");
        scanf("%d",&n);
        head = creat_table(n);
        To_list(head);
        break;
    
    default:
        printf("your choice doesn't exist please try again");
        break;
    }
    return 0;
}

void creat_list(int x){
    int i,num;
    struct node *tmp;
    head =(struct node *)malloc(sizeof(struct node));
    printf("Input data for the first node :");
    scanf("%d",&num);
    head -> data = num;
    head -> next = NULL;
    tmp = head;
    for(i = 2;i <= x;i++){
        current = (struct node*)malloc(sizeof(struct node));
        printf("Input data for the %d node :",i);
        scanf("%d",&num);
        current -> data = num;
        current -> next = NULL;
        tmp -> next = current;
        tmp = tmp -> next;
        }
} 


 void To_table(struct node * head,int x){
     struct node *tmp;
    int i, T[x];
    if(head == NULL)
        printf("list is empty");
    else {
        tmp = head;
        i = 0;
        while(tmp != NULL && i <= x){
            T[i] = tmp -> data;
            tmp = tmp -> next;
            i++;
        }
        for(i = 0; i < x; i++){
            printf("%d\t",T[i]);
        }
    }
}

struct node *creat_table(int x){
    int T[x],i;
    for ( i = 0; i < x; i++)
    {
        printf("Input the data for the %d case :",i+1);
        scanf("%d",&T[i]);
    }
    head = (struct node *)malloc(sizeof(struct node));
    head -> data = T[0];
    head -> next = NULL;
    struct node *tmp = head;
    for ( i = 1; i < x; i++)
    {
        current = (struct node *)malloc(sizeof(struct node));
        current -> data = T[i];
        current -> next = NULL;
        tmp -> next = current;
        tmp = tmp -> next;
    }
    return head;
}

void To_list(struct node *head){
    struct node *tmp = head;
    while(tmp != NULL){
        printf("%d\t",tmp->data);
        tmp = tmp -> next;
    }
}





