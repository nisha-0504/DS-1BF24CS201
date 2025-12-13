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


void deleteBeginning() {
    if (head == NULL) {
        printf("Empty Linked List\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);

    printf("Deleted from beginning\n");
}


void deleteByValue(int data) {
    if (head == NULL) {
        printf("Empty Linked List\n");
        return;
    }

    
    if (head->data == data) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        printf("Node with value %d deleted\n", data);
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Node with value %d deleted\n", data);
    }
}


void deleteEnd() {
    if (head == NULL) {
        printf("Empty Linked List\n");
        return;
    }

    
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted\n");
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Last node deleted\n");
}


void displaylist() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    struct node *temp = head;
    printf("Linked List:\n");
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
        printf("2: Delete at beginning\n");
        printf("3: Delete by value\n");
        printf("4: Delete at end\n");
        printf("5: Display\n");
        printf("0: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                createnode();
                break;

            case 2:
                deleteBeginning();
                break;

            case 3: {
                int num;
                printf("Enter value to delete: ");
                scanf("%d", &num);
                deleteByValue(num);
                break;
            }

            case 4:
                deleteEnd();
                break;

            case 5:
                displaylist();
                break;

            case 0:
                printf("Program terminated\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (ch != 0);

    return 0;
}
