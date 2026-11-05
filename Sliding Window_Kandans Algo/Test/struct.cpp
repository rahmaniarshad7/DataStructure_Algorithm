#include <iostream>
using namespace std;

struct Student
{
  char name[30];
  int rollNo;
};

int main()
{
  struct Student s = {"Arshad", 101};
  struct Student *ptr;
  ptr = &s;

  cout << ptr->name << " " << ptr->rollNo << endl;
  cout << (*ptr).name << endl;
  cout << (*ptr).rollNo << endl;
  return 0;
}