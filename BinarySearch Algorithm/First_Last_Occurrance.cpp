#include <iostream>
using namespace std;

int findFirstOcurrance(int arr[], int size, int target)
{
  int start = 0;
  int end = size - 1;
  int index = -1;
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

int findLastOccurrance(int arr[], int size, int target)
{
  int start = 0;
  int end = size - 1;
  int index = -1;

  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
      index = mid;
      start = mid + 1;
    }
    if (arr[mid] < target)
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
  cout << "Enter Elements : ";
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }

  int target;
  cout << "Enter target : ";
  cin >> target;

  int firstIndex = findFirstOcurrance(arr, size, target);
  int lastIndex = findLastOccurrance(arr, size, target);

  cout << "First Index : " << firstIndex << endl;
  cout << "Last Index : " << lastIndex;
}