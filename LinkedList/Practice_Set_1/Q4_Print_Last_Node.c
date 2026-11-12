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

void printLastNode(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("Empty List : ");
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Last Node : %d", temp->data);
}
int main()
{
    struct Node *newNode = NULL, *head = NULL, *temp = NULL;
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
    printLastNode(head);

    // Step 6: Memory free karo
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
