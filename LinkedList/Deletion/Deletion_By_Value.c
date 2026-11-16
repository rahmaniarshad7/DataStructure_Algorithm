
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory not allocated\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Delete first occurrence of a value
void delete_By_Value(struct Node **head, int value)
{
    // Case 1: Empty list
    if (*head == NULL)
    {
        printf("Empty List\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    // Search for the first occurrence
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    // Case 2: Value not found
    if (temp == NULL)
    {
        printf("Value not found\n");
        return;
    }

    // Case 3: Delete first node
    if (prev == NULL)
    {
        *head = temp->next;
        free(temp);

        printf("Node deleted successfully\n");
        return;
    }

    // Case 4: Delete middle or last node
    prev->next = temp->next;
    free(temp);

    printf("Node deleted successfully\n");
}

// Display linked list
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

// Free remaining memory
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

    int n, value, deleteValue;

    printf("Enter Number of Nodes: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid number of nodes\n");
        return 1;
    }

    // Create linked list
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

    printf("\nBefore Deletion:\n");
    printList(head);

    printf("\nEnter value to delete: ");
    scanf("%d", &deleteValue);

    delete_By_Value(&head, deleteValue);

    printf("\nAfter Deletion:\n");
    printList(head);

    // Release remaining memory
    freeList(&head);

    return 0;
}
