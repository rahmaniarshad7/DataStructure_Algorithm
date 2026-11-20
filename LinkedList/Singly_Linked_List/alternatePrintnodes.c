#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // FIX 1: Changed lowercase 'node' to uppercase 'Node'
};

struct Node *createNode(int value)
{
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
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
        printf("%d ", temp->data);

        // FIX 2: Added a safety check before skipping ahead to prevent a Segmentation Fault crash
        if (temp->next != NULL)
        {
            temp = temp->next->next;
        }
        else
        {
            temp = NULL;
        }
    }
    printf("null\n");
}

int main()
{
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, value;

    printf("Enter Number of Nodes : ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++)
    {
        printf("Enter Data : ");
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

    printList(head);

    // Free memory
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
