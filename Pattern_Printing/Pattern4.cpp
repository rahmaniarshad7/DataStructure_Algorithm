#include <iostream>
using namespace std;
int main()
{

  for (int row = 1; row <= 5; row++)
  {

    for (int col = 1; col <= 5; col++)
    {
      cout << char('a' + (row - 1)) << " ";
    }
    cout << "\n";
  }
}