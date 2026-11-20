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
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printSecondLastNode(struct Node *head1)
{
    struct Node *temp;
    temp = head1;

    if (temp->next == NULL || temp->next->next == NULL)
    {
        printf("Second Last Node Not exist : ");
        return;
    }

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    printf("Second Last Node : %d", temp->data);
}

void printList(struct Node *head)
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("null");
}

int main()
{
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    int n, value;
    printf("Enter Number of Nodes : ");
    scanf("%d", &n);

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
    printSecondLastNode(head);

    // Free memory
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}