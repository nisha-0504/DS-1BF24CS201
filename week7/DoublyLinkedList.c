#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
void insertAtStart(int data)
{
    struct node *newnode = createnode(data);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    printf("%d inserted at beginning of the linked list \n", data);
}
void insertAtEnd(int data)
{
    struct node *newnode = createnode(data);
    struct node *temp = head;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("%d inserted at end of the linked list \n", data);
}
void insertAtPos(int data, int pos)
{
    struct node *newnode = createnode(data);
    struct node *temp = head;
    if (pos < 1)
    {
        printf("Invalid position");
    }
    else if (pos == 1)
    {
        insertAtStart(data);
    }
    else
    {
        int i = 1;
        while (i < pos - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
        {
            printf("position out of bound");
            return;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
    printf("%d inserted at pos %d of the linked list \n", data, pos);
}
void deletebyvalue(int value)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("empty list");
    }
    else if (head->data == value)
    {
        head = head->next;
        head->prev = NULL;
        free(temp);
        return;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
                return;
            }
            temp = temp->next;
        }
    }
}
void deletebyPos(int pos)
{
    struct node *temp = head;
    if (pos < 1)
    {
        printf("Invalid position");
    }
    else if (pos == 1)
    {
        head = head->next;
        head->prev = NULL;
        free(temp);
        return;
    }
    else
    {
        int i = 1;
        while (i < pos && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
        {
            printf("position out of bound");
            return;
        }
        if (temp->next == NULL)
        {
            temp->prev->next = NULL;
            free(temp);
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        return;
    }
}
void displaylist()
{
    struct node *temp = head;
    printf("LINKEDLIST\n");
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d", temp->data);
        printf("\n");
        temp = temp->next;
    }
}
void main()
{
    int ch;
    printf("Enter your choice:(\n");
    printf("1:INSERT AT START\n");
    printf("2:INSERT AT END\n");
    printf("3:INSERT BY POSITION\n");
    printf("4:DELETE BY VALUE\n");
    printf("5:DELETE BY POSITION\n");
    printf("6:DISPLAY)\n");
    printf("0:STOP)\n");
    scanf("%d", &ch);

    while (ch != 0)
    {

        switch (ch)
        {
        case 1:
        {
            int VAL;
            printf("Enter value: ");
            scanf("%d", &VAL);
            insertAtStart(VAL);
            break;
        }
        case 2:
        {
            int VAL;
            printf("Enter value: ");
            scanf("%d", &VAL);
            insertAtEnd(VAL);
            break;
        }
        case 3:
        {
            int VAL;
            int POS;
            printf("Enter value: ");
            scanf("%d", &VAL);
            printf("Enter POSITION: ");
            scanf("%d", &POS);
            insertAtPos(VAL, POS);
            break;
        }
        case 4:
        {
            int POS;
            printf("Enter POSITION: ");
            scanf("%d", &POS);
            deletebyPos(POS);
            break;
        }
        case 5:
        {
            int VAL;
            printf("Enter value: ");
            scanf("%d", &VAL);
            deletebyvalue(VAL);
            break;
        }
        case 6:
        {
            displaylist();
            break;
        }
        default:
        {
            printf("Invalid input");
            break;
        }
        }
        printf("Enter your choice:(\n");
        printf("1:INSERT AT START\n");
        printf("2:INSERT AT END\n");
        printf("3:INSERT BY POSITION\n");
        printf("4:DELETE BY VALUE\n");
        printf("5:DELETE BY POSITION\n");
        printf("6:DISPLAY)\n");
        printf("0:STOP)\n");
        scanf("%d", &ch);
    }
}
