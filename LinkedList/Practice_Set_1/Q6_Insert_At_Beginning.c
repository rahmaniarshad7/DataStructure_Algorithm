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

void insert_At_Beginning(int value)
{
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory not allocated : ");
        exit(1);
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
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
    int data;
    printf("\nEnter Data to Insert : ");
    scanf("%d", &data);

    insert_At_Beginning(data);
    printf("First Node : %d", head->data);

    // Step 6: Memory free karo
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
