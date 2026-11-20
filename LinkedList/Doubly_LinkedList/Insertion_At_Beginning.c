#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *createNode(int value){
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory not allocated : ");
        exit(EXIT_FAILURE);
    }
    newNode ->data = value;
    newNode ->prev = NULL;
    newNode ->next = NULL;

    return newNode;
}

void createList(struct Node **head, struct Node **tail){
    int n, value;
    struct Node *newNode;
    printf("Enter Number of Node : ");
    scanf("%d", &n);

    if(n < 0){
        printf("Invalid Node Number : ");
        return;
    }

    for(int i = 1; i <= n; i++){
        printf("Enter Data : ");
        scanf("%d", &value);

        newNode = createNode(value);
        if(*head == NULL){
            *head = newNode;
            *tail = newNode;
        }
        else{
            newNode ->prev = *tail;
            (*tail) ->next = newNode;
            *tail = newNode;
        }
    }
}

void insert_At_Beginning(struct Node **head, struct Node **tail){
    struct Node *newNode;
    int data;
    printf("Enter Data : ");
    scanf("%d", &data);

    newNode = createNode(data);

    if(*head == NULL){
        newNode ->next = NULL;
        newNode ->prev = NULL;
        *head = newNode;
        *tail = newNode;
        return;
    }
    newNode ->prev = NULL;
    newNode ->next = *head;
    (*head) ->prev = newNode;
    *head = newNode;
}

void printList(struct Node **head){
    struct Node *temp = *head;
    while(temp){
        printf("%d -> ", temp ->data);
        temp = temp ->next;
    }
    printf("null");
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
int main(){
    struct Node *head =NULL;
    struct Node *tail = NULL;

    createList(&head, &tail);

    printf("Befor Insertion At First : ");
    printList(&head);

    printf("\n");

    insert_At_Beginning(&head, &tail);
    printf("\nAfter Insertion At First : ");
    printList(&head);

    freeList(&head);

    return 0;
}
