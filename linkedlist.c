#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;


void insert(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void delete(int value) {
    struct node *temp= head, *prev=NULL;

    if (head == NULL) {
       printf("Empty");
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void printList(){
    if(head==NULL){
        printf("Empty\n");
    }
    else{
        struct node * temp=head;
        while(temp !=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}


void main(){
    insert(10);
    printList();
}