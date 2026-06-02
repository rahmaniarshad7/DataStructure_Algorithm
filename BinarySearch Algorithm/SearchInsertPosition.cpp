#include <iostream>
#include <vector>
using namespace std;

int searchInsertPosition(vector<int> &arr, int target)
{
  int start = 0;
  int end = arr.size() - 1;
  int index = arr.size();

  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    // condition 1
    if (arr[mid] == target)
    {
      index = mid;
      end = mid - 1;
    }

    // condition 2
    else if (arr[mid] > target)
    {
      index = mid;
      end = mid - 1;
    }
    // condition 3
    else
    {
      start = mid + 1;
    }
  }
  return index;
}

int main()
{
  int size;
  cout << "Enter Size : " << endl;
  cin >> size;

  vector<int> arr(size);
  cout << "Enter Element : " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }

  int target;
  cout << "Enter target : " << endl;
  cin >> target;

  int index = searchInsertPosition(arr, target);
  cout << "Insert Position : " << index;
}