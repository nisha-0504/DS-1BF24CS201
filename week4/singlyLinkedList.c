#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void createnode() {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}


void insertBeginning(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;

    printf("%d inserted at beginning\n", data);
}

/* Insert at specific position */
void insertAtPos(int data, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insertBeginning(data);
        return;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;

    newnode->data = data;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newnode);
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    printf("%d inserted at Specific Position\n", data);
}


void insertEnd(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
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
    printf("%d inserted at End\n", data);

}


void displaylist() {
    struct node *temp = head;

    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
    

int main() {
    int ch;

    do {
        printf("1: Create\n");
        printf("2: Insert at beginning\n");
        printf("3: Insert at specific position\n");
        printf("4: Insert at end\n");
        printf("5: Display\n");
        printf("0: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                createnode();
                break;

            case 2: {
                int num;
                printf("Enter data: ");
                scanf("%d", &num);
                insertBeginning(num);
                break;
            }

            case 3: {
                int num, pos;
                printf("Enter data: ");
                scanf("%d", &num);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPos(num, pos);
                break;
            }

            case 4: {
                int num;
                printf("Enter data: ");
                scanf("%d", &num);
                insertEnd(num);
                break;
            }

            case 5:
                displaylist();
                break;

            case 0:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (ch != 0);

    return 0;
}
