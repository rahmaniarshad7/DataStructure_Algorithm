#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }

public:
    void getNode(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{

    // creating nodes
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // Linking Nodes
    first->next = second;
    second->next = third;
    third->next = nullptr;

    // Printing Nodes Data
    second->getNode(first);

    // Free memory
    delete first;
    delete second;
    delete third;

    return 0;
}