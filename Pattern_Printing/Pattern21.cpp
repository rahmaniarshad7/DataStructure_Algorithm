#include <iostream>
using namespace std;
int main()
{

  int n;
  cout << "Enter Row: ";
  cin >> n;

  for (int row = 1; row <= n; row++)
  {
    // Part 1 Space print karna hai row - 1
    for (int col = 1; col <= row - 1; col++)
    {
      cout << " " << " ";
    }
    // Part 2 Star Print karna hai 2 * n - (2 * row - 1);
    for (int i = 1; i <= 2 * n - (2 * row - 1); i++)
    {
      cout << "*" << " ";
    }
    cout << endl;
  }
}