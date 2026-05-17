#include <bits/stdc++.h>
using namespace std;
int main()
{
  int index = -1;
  int size;
  cin >> size;
  vector<int> arr(size);
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == 5)
    {
      index = i;
    }
  }
  cout << index << " :";
}