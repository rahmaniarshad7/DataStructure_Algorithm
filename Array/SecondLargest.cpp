#include <bits/stdc++.h>
using namespace std;

int findLargest(int arr[], int size)
{
  int largest = INT_MIN;
  for (int i = 0; i < size; i++)
  {
    largest = max(arr[i], largest);
  }
  return largest;
}

int findSecondLargest(int arr[], int size, int maxi)
{
  int secMax = INT_MIN;
  for (int i = 0; i < size; i++)
  {
    if (arr[i] != maxi)
    {
      secMax = max(arr[i], secMax);
    }
  }
  return secMax;
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
  int max = findLargest(arr, size);
  int secMax = findSecondLargest(arr, size, max);
  cout << "Second Largest element : " << secMax;
}