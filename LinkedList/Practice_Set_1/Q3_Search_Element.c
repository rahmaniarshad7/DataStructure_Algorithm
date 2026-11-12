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

int searchElement(struct Node *head, int target)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        return -1;
    }

    while (temp != NULL)
    {
        if (temp->data == target)
        {
            return 1;
        }
        temp = temp->next;
    }
    return -1;
}
int main()
{
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, value;

    printf("\nEnter Number of Nodes : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter Data : ");
        scanf("%d", &value);

        newNode = createNode(value);

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    int target;
    printf("\nEnter Element to search : ");
    scanf("%d", &target);

    int found = searchElement(head, target);
    if (found == 1)
    {
        printf("\nElement Present in Linked List : ");
    }
    else
    {
        printf("\nElement not present in Linked list");
    }

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
