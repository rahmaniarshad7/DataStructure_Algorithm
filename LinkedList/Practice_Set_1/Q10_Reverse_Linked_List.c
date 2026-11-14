#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

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

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("null");
}

struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next; // Save next node
        current->next = prev; // Reverse link
        prev = current;       // Move prev forward
        current = next;       // Move current forward
    }
    return prev; // new head
}

int main()
{
    struct Node *newNode = NULL, *temp = NULL;
    int n, value;

    printf("Enter Number of Node : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter Data : ");
        scanf("%d", &value);

        newNode = createNode(value);

        // Step 1: Creating first Node
        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            // connect new Node at end
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("\n Before Reverse : ");
    printList(head);

    printf("\n After Reverse : ");
    struct Node *newHead;
    newHead = reverseList(head);
    printList(newHead);

    // Free Memory
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
