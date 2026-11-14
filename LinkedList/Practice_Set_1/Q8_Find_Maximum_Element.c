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

int getMaximum(struct Node *head)
{
    if (head == NULL)
    {
        printf("Empty Linked List : ");
        exit(1);
    }
    int max = INT_MIN;
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data > max)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
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
    // Finding maximum value in Linked List:
    int maxValue = getMaximum(head);
    printf("Maximum in Linked List : %d", maxValue);

    // Free Memory
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
