#include <stdlib.h>
#include <stdio.h>

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
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node *insertAtEnd(struct Node *head, int value)
{
    struct Node *newNode;
    newNode = createNode(value);

    // Case 1: if Linked List is empty insert at first position;
    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    // Case 2: Non empty Linked List;
    struct Node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct Node *head = NULL;
    int n, value;

    printf("Enter Number of Nodes: ");
    scanf("%d", &n);

    // Create Initial Linked List
    for (int i = 1; i <= n; i++)
    {
        printf("Enter Data: ");
        scanf("%d", &value);

        head = insertAtEnd(head, value);
    }

    printf("\nOriginal Linked List: ");
    printList(head);

    // Insert New Node at End
    printf("\nEnter Value to Insert at End: ");
    scanf("%d", &value);

    head = insertAtEnd(head, value);

    printf("\nAfter Insertion at End: ");
    printList(head);

    // Free Memory
    struct Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
