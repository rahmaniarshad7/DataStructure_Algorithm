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
};
int main()
{
  Node *head = new Node(100);
  cout << head->data << endl;
  cout << head->next;

  delete head;
}