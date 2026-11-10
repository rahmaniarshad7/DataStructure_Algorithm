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

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("null");
    return;
}

int main()
{
    struct Node *first, *second, *third, *fourth, *newNode, *head;
    first = createNode(10);
    second = createNode(20);
    third = createNode(30);
    fourth = createNode(40);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    head = first;
    newNode = createNode(5);
    newNode->next = head;
    head = newNode;

    printList(head);

    // Free Memory;
    free(newNode);
    free(first);
    free(second);
    free(third);
    free(fourth);

    return 0;
}
