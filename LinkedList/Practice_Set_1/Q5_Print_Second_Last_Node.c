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

void printSecondLastNode(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        printf("No Last Node : ");
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    printf("Second Last Node : %d ", temp->data);
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
    printSecondLastNode(head);

    // Step 6: Memory free karo
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
