#include <bits/stdc++.h>
using namespace std;
int main()
{
  int size;
  cin >> size;

  int arr[size];
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  int start = 0;
  int end = size - 1;
  while (start < end)
  {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
}