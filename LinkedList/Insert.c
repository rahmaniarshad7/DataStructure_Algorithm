#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createList(int value)
{
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory not allocated\n");
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
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Added: Dynamic function to safely free all nodes in the list
void freeList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;       // Save the current node
        head = head->next; // Move head to the next node safely
        free(temp);        // Delete the saved node
    }
}

int main()
{
    struct Node *first, *second, *third, *head;

    first = createList(10);
    second = createList(20);
    third = createList(30);

    first->next = second;
    second->next = third;
    third->next = NULL;

    head = first;
    printList(head);

    // Replaced manual frees with the dynamic function
    freeList(head);
    head = NULL;

    return 0;
}
