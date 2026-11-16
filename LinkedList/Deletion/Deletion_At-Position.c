#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *createNode(int value){
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory not allocated : ");
        exit(1);
    }
    newNode ->data = value;
    newNode ->next = NULL;
    return newNode;
}

void delete_At_Position(struct Node **head, int position){
    if(*head == NULL){
        printf("Empty List : ");
        return;
    }
    if(position < 1){
        printf("Invalid Position : ");
        return;
    }
    if(position == 1){
        struct Node *temp = *head;
        *head = temp ->next;
        free(temp);
        printf("Deleted Successfully : ");
        return;
    }
    struct Node *temp = *head;
    struct Node *prev = NULL;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp ->next;
    }
    free(temp);
    if(position > count){
        printf("\nInvalid Position : ");
        return;
    }

    // Reach to target node
    struct Node *temp2 = *head;
    for(int i = 1; i < position; i++){
        prev = temp2;
        temp2 = temp2 ->next;
    }
    prev ->next = temp2 ->next;
    free(temp2);
    printf("Node Deleted Successfully : ");
}

void printList(struct Node **head){
    struct Node *temp = *head;
    while(temp != NULL){
        printf("%d -> ", temp ->data);
        temp = temp ->next;
    }
    free(temp);
}
void freeList(struct Node **head)
{
    struct Node *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    struct Node *newNode = NULL;
    struct Node *temp = NULL;

    int n, value;

    printf("\nEnter Number of Nodes: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid number of nodes\n");
        return 1;
    }

    for (int i = 1; i <= n; i++)
    {
        printf("Enter Data: ");
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
    int position;
    printf("Enter Position to delete : ");
    scanf("%d", &position);

    printf("\nBefore Deletion: ");
    printList(&head);

    delete_At_Position(&head, position);

    printf("\nAfter Deletion: ");
    printList(&head);

    freeList(&head);

    return 0;
}
