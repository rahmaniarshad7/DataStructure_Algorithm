#include <iostream>
using namespace std;

int firstIndex(int arr[], int size, int target)
{
  int index = -1;
  int start = 0;
  int end = size - 1;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
      index = mid;
      end = mid - 1;
    }
    else if (arr[mid] < target)
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  return index;
}

int lastIndex(int arr[], int size, int target)
{
  int index = -1;
  int start = 0;
  int end = size - 1;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
      index = mid;
      start = mid + 1;
    }
    else if (arr[mid] < target)
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  return index;
}

int main()
{
  int size;
  cout << "Enter Size : " << endl;
  cin >> size;

  int arr[10];
  cout << "Enter Elements : " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  int target;
  cout << "Enter target : " << endl;
  cin >> target;

  int first = firstIndex(arr, size, target);
  int last = lastIndex(arr, size, target);

  if (first == -1 && last == -1)
  {
    cout << "Element not found : ";
  }
  else
  {
    cout << "Count = " << last - first + 1;
  }
}