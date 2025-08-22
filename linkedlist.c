#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertEnd(int value) {
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

void insertBeginning(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

void insertPosition(int position, int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL || position <= 1) {
        newnode->next=head;
        head = newnode;

    } else {
        struct node *temp = head;
        int i = 1;
        while (i < position - 1 && temp->next != NULL) {
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL) {
            printf("%d is the last node. Added node after that\n", i);
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deleteNode(int value) {
    struct node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("Empty\n");
        return;
    }

    if (head->data == value) {
        temp = head;
        head = head->next;
        printf("%d deleted\n", value);
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Data not found\n");
        return;
    }

    prev->next = temp->next;
    printf("%d deleted\n", value);
    free(temp);
}

void printList() {
    if (head == NULL) {
        printf("Empty\n");
    } else {
        struct node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int op, value, position;
    while (1) {
        printf("\n1.Insert at end\n2.Insert at beginning\n3.Insert at position\n4.Delete\n5.Display\n6.Exit\n");
        printf("Choose Operation: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter Number to insert: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 2:
                printf("Enter Number to insert: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;
            case 3:
                printf("Enter Number to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertPosition(position, value);
                break;
            case 4:
                printf("Enter Number to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 5:
                printList();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid Operation\n");
        }
    }
}
