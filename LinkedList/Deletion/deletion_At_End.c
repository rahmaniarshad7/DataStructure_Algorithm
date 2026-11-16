#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory not allocated : ");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void Delete_At_End(struct Node **head)
{
    if (*head == NULL)
    {
        printf("Empty List : ");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void printList(struct Node **head)
{
    struct Node *temp = *head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp ->next;
    }
    printf("null");
    free(temp);
}

void freeList(struct Node **head)
{
    struct Node *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    struct Node *newNode = NULL;
    struct Node *temp = NULL;

    int n, value;

    printf("\nEnter Number of Nodes: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid number of nodes\n");
        return 1;
    }

    for (int i = 1; i <= n; i++)
    {
        printf("Enter Data: ");
        scanf("%d", &value);

        newNode = createNode(value);

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("\nBefore Deletion: ");
    printList(&head);

    Delete_At_End(&head);

    printf("\nAfter Deletion: ");
    printList(&head);

    freeList(&head);

    return 0;
}
