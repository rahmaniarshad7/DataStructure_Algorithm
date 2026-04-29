#include <iostream>
using namespace std;
int main()
{
  int n;
  cout << "Enter n: ";
  cin >> n;

  for (int row = 1; row <= n / 2; row++)
  {
    // Part1 star
    for (int col = 1; col <= n / 2 - row + 1; col++)
    {
      cout << "*" << " ";
    }
    // Part 2 space
    for (int i = 1; i <= 2 * (row - 1); i++)
    {
      cout << " " << " ";
    }
    // Part 3 space
    for (int j = 1; j <= n / 2 - row + 1; j++)
    {
      cout << "*" << " ";
    }
    cout << endl;
  }
  for (int row = 1; row <= n / 2; row++)
  {
    // Print Star
    for (int col = 1; col <= row; col++)
    {
      cout << "*" << " ";
    }
    // Print Space
    for (int i = 1; i <= 2 * (n / 2 - row); i++)
    {
      cout << " " << " ";
    }
    // Print Star
    for (int j = 1; j <= row; j++)
    {
      cout << "*" << " ";
    }
    cout << endl;
  }
}