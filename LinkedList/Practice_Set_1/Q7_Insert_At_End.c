#include <stdio.h>
#include <stdlib.h>

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

void insert_at_End(int value)
{
    struct Node *newNode;
    newNode = createNode(value);

    // Case 1: If linked list is empty
    if (head == NULL)
    {
        head = newNode;
        exit(1);
    }

    // Case 2: If non empty linked list
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Insert at end Successfully...\n");
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("null");
}

int main()
{
    struct Node *newNode = NULL, *temp = NULL;
    int n, value;
    printf("Enter Number of Nodes : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter Data : ");
        scanf("%d", &value);

        newNode = createNode(value);

        // First Node
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            // Step 4: New Node ko end mein connect karo
            temp->next = newNode;
            temp = newNode;
        }
    }
    // Step 5: Insert at Last
    int data;
    printf("Enter data to insert : ");
    scanf("%d", &data);

    insert_at_End(data);
    printList(head);

    // Step 6: Memory free karo
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}