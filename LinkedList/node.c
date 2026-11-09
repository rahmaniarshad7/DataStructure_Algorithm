#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

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
    struct Node *first, *second, *third, *head;
    first = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));

    // Data
    first->data = 10;
    second->data = 20;
    third->data = 30;

    // Linking Nodes;
    first->next = second;
    second->next = third;
    third->next = NULL;

    head = first;
    printList(head);

    free(first);
    free(second);
    free(third);

    return 0;
}
