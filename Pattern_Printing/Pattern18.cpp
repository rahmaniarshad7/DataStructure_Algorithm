#include <iostream>
using namespace std;
int main()
{

  int n;
  cout << "Enter Number of Row: ";
  cin >> n;

  for (int row = 1; row <= n; row++)
  {
    // Part 1
    for (int col = 1; col <= n - row; col++)
    {
      cout << " " << " ";
    }
    // Part 2
    for (int i = 1; i <= row; i++)
    {
      cout << i << " ";
    }
    cout << endl;
  }
}