#include <iostream>
using namespace std;
int main()
{

  int n = 5;
  for (int row = 1; row <= n; row++)
  {
    for (int col = 1; col <= 5; col++)
    {
      cout << row << " ";
    }
    cout << endl;
  }
}