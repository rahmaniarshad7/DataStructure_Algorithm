#include <bits/stdc++.h>
using namespace std;

int findSmallest(int arr[], int size)
{
  int small = INT_MAX;
  for (int i = 0; i < size; i++)
  {
    small = min(arr[i], small);
  }
  return small;
}

int main()
{
  int size;
  cin >> size;

  int arr[size];
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  int min = findSmallest(arr, size);
  cout << "Smallest element : " << min;
}