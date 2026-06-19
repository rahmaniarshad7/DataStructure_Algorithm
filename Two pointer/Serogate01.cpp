#include <bits/stdc++.h>
using namespace std;

void serogate(vector<int> &arr)
{
  int start = 0;
  int end = arr.size() - 1;
  while (start < end)
  {
    if (arr[start] == 1 && arr[end] == 0)
    {
      swap(arr[start], arr[end]);
      start++;
      end--;
    }
    else if (arr[end] == 1)
    {
      end--;
    }
    else
    {
      start++;
    }
  }
  for (int i : arr)
  {
    cout << i << " ";
  }
}

int main()
{
  int size;
  cout << "Enter Size : ";
  cin >> size;

  vector<int> arr(size);
  cout << "Enter element : " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  serogate(arr);
}