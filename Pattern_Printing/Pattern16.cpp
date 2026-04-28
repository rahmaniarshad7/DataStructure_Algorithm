#include <iostream>
using namespace std;
int main()
{

  int n;
  cout << "Enter Row: ";
  cin >> n;

  for (int row = 1; row <= n; row++)
  {
    for (int col = 1; col <= n - row; col++)
    {
      cout << "  ";
    }
    for (int i = 1; i <= row; i++)
    {
      cout << "* ";
    }
    cout << endl;
  }
}