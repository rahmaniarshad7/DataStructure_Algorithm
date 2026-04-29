#include <iostream>
using namespace std;
int main()
{

  int n;
  cout << "Enter Row: ";
  cin >> n;

  for (int row = 1; row <= n; row++)
  {
    // Part 1 print space
    for (int col = 1; col <= n - row; col++)
    {
      cout << " " << " ";
    }
    // Part 2
    for (int i = 1; i <= row; i++)
    {
      cout << i << " ";
    }
    // Part 3
    for (int j = row - 1; j >= 1; j--)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}