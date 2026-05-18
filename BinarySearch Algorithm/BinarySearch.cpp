#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
  int start = 0;
  int end = size - 1;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    // condition 1 arr[mid] == target
    if (arr[mid] == target)
    {
      return mid;
    }

    // condition 2 arr[mid] < target
    else if (arr[mid] < target)
    {
      start = mid + 1;
    }

    // condition 3 arr[mid] > target
    else
    {
      end = mid - 1;
    }
  }
  return -1;
}

int main()
{
  int size;
  cout << "Enter Size : " << endl;
  cin >> size;

  int arr[size];
  cout << "Enter Elements : " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  int target;
  cout << "Enter Target : " << endl;
  cin >> target;

  int index = binarySearch(arr, size, target);
  if (index == -1)
  {
    cout << "Element not found";
  }
  else
  {
    cout << "Element present at index " << index;
  }
}