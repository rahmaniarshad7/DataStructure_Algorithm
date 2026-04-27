#include <iostream>
using namespace std;
int main()
{

  for (int row = 1; row <= 5; row++)
  {
    for (char col = 'F'; col <= 'K'; col++)
    {
      cout << col << " ";
    }
    cout << endl;
  }
}