#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *head1 = NULL;

/* Create nodes for first list */
void createnode1() {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

/* Create nodes for second list */
void createnode2() {
    int ch;
    struct node *temp = NULL;

    do {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head1 == NULL) {
            head1 = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Want to add more nodes (1:Yes / 2:No): ");
        scanf("%d", &ch);

    } while (ch != 2);
}

/* Sort the first list */
void sortList() {
    int tempdata;
    struct node *i, *j;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                tempdata = i->data;
                i->data = j->data;
                j->data = tempdata;
            }
        }
    }
}

/* Reverse the first list */
void reverseList() {
    struct node *prev = NULL, *next = NULL, *curr = head;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

/* Concatenate two lists */
struct node *concatList(struct node *head3, struct node *head2) {
    struct node *temp = head3;

    if (head3 == NULL)
        return head2;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head3;
}

/* Display list */
void displaylist(struct node *head2) {
    struct node *temp = head2;

    if (head2 == NULL) {
        printf("Empty list\n");
        return;
    }

    printf("Linked list:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int ch;

    while (1) {
        printf("0: Stop\n");
        printf("1: Create list 1\n");
        printf("2: Sort list 1\n");
        printf("3: Reverse list 1\n");
        printf("4: Concatenate two lists\n");
        printf("5: Display list 1\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 0:
                exit(0);

            case 1:
                createnode1();
                break;

            case 2:
                sortList();
                break;

            case 3:
                reverseList();
                displaylist(head);
                break;

            case 4:
                createnode2();
                head = concatList(head, head1);
                displaylist(head);
                break;

            case 5:
                displaylist(head);
                break;

            default:
                printf("Invalid choice\n");
        }
    }
}
