#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

void insert_at_beg(int value)
{
    struct Node *ptr;
    ptr = malloc(sizeof(struct Node));
    if (ptr != NULL)
    {
        ptr->data = value;
        ptr->next = head;
        head = ptr;
    }
    else
    {
        printf("Memory not allocated : ");
        return;
    }
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

int main()
{
    struct Node *first, *second, *third;
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

    int value;
    printf("\n Enter value to Insert : ");
    scanf("%d", &value);

    insert_at_beg(value);

    printf("\n After Insertion of 5 : ");
    printList(head);

    free(first);
    free(second);
    free(third);

    return 0;
}
