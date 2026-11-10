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
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("null");
}

int main()
{
    struct Node *first, *second, *third, *head;
    first = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));

    first->data = 10;
    second->data = 20;
    third->data = 30;

    head = first;
    first->next = second;
    second->next = third;
    third->next = NULL;

    printf("\n Before Insertion of 5 : ");
    printList(head);

    struct Node *ptr = malloc(sizeof(struct Node));
    ptr->data = 5;
    ptr->next = first;
    head = ptr;

    printf("\n After Insertion of 5 : ");
    printList(head);

    free(first);
    free(second);
    free(third);

    return 0;
}
