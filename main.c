#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//double linked list
struct node{
int data;
struct node *prev;
struct node *next;
};

//head and last declared as NULL
struct node *head = NULL;
struct node *last = NULL;

//function prototype
void create();
void display_beg();
void display_rev();
void insert_beg();
void insert_end();

//main() with double linked list menu
int main(){
int ch;
while(1){
    printf("\n______________________MENU________________________");
    printf("\nI 1.Create the list                              I");
    printf("\nI 2.display the list from the beginning          I");
    printf("\nI 3.display the list from the last               I");
    printf("\nI 4.Insert the node at the beginning             I");
    printf("\nI 5.Insert the node at the end                   I");
    printf("\nI 6.Exit                                         I");
    printf("\nI________________________________________________I");
    printf("\nenter the choice:");
    scanf("%d",&ch);
    switch(ch){
    case 1: create();
    break;
    case 2: display_beg();
    break;
    case 3: display_rev();
    break;
    case 4: insert_beg();
    break;
    case 5: insert_end();
    break;
    case 6: exit(0);
    break;
    default : printf("\nWrong choice !!!\n \t\t\t\tRETRY AGAIN");
    break;
    }
}
return 0;
}

//function to create the linked list
void create(){
int n,i=2;
struct node *temp;
printf("\nHow many nodes ?");
scanf("%d",&n);
if(n>=1){
head = (struct node*)malloc(sizeof(struct node));
if(head!=NULL){
printf("\nenter the data:: ");
scanf("%d",&head->data);
    head->next=NULL;
    head->prev=NULL;
    last = head;

while(i<=n){
        temp=(struct node*)malloc(sizeof(struct node));
        if(temp!=NULL){
printf("\nenter the data:: ");
scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=last;

    last->next=temp;
    last=temp;
}
else{
    printf("\nUnable to allocate");
}
i++;
}
}
else{
    printf("\nUnable to allocate");
}
}
}

//display double linked list from the beginning
void display_beg(){
struct node *temp;
int n=1;
if(head==NULL){
    printf("\nempty list");
}
else{
        temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
}

//display the last from the last
void display_rev(){
struct node *temp;
temp=last;
if(last==NULL){
    printf("\nEmpty list !!");
}
else{
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->prev;
    }
}
}
//insert the node at the beginning
void insert_beg(){
    struct node *temp, *ptr;
    if(head==NULL){
        printf("Empty list !!");
    }
    else{
            ptr=head;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter the data:: ");
        scanf("%d",&temp->data);
        temp->next=head;
        temp->prev=NULL;

        head=temp;
    last=ptr;
    }
}

//insert the node at the end
void insert_end(){
    struct node *temp;
    if(last==NULL){
        printf("List is empty!!");
    }
    else{
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter the data:: ");
        scanf("%d",&temp->data);
        temp->prev=last;
        last->next=temp;
        temp->next=NULL;
        last=temp;

    }
}
