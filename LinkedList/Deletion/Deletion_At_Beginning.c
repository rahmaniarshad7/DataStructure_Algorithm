
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void printList(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void delete_At_Beginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;

    *head = (*head)->next;

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

    printf("Enter Number of Nodes: ");
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
    printList(head);

    delete_At_Beginning(&head);

    printf("After Deletion: ");
    printList(head);

    freeList(&head);

    return 0;
}
