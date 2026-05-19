#include <iostream>
using namespace std;

int ascBinarySearch(int arr[], int size, int target)
{
  int start = 0;
  int end = size - 1;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
      return mid;
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
  return -1;
}

int descBinarySearch(int arr[], int size, int target)
{
  int start = 0;
  int end = size - 1;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }
    else if (arr[mid] < target)
    {
      end = mid - 1;
    }
    else
    {
      start = mid + 1;
    }
  }
  return -1;
}

int main()
{
  int size;
  cout << "Enter size : " << endl;
  cin >> size;

  int arr[15];
  cout << "Enter Elements : " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }

  int target;
  cout << "Enter target : " << endl;
  cin >> target;

  if (arr[0] < arr[1])
  {
    int ans = ascBinarySearch(arr, size, target);
    if (ans == -1)
    {
      cout << "Element not found : ";
    }
    else
    {
      cout << "Element found at index " << ans;
    }
  }
  else
  {
    int ans = descBinarySearch(arr, size, target);
    if (ans == -1)
    {
      cout << "Element not found : ";
    }
    else
    {
      cout << "Element found at index " << ans;
    }
  }
  return 0;
}