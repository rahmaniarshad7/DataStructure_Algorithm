#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Node create function
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
// Print Linked List
void printlist(struct Node *head)
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("null");
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
    // Step 5: Printing linked List
    printf("\n Linked List : ");
    printlist(head);

    // Step 6: Memory free karo
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
