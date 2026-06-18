#include <bits/stdc++.h>
using namespace std;

int getMinimum(vector<int> &arr)
{
  int n = arr.size();
  int start = 0;
  int end = n - 1;
  int min = 0;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    int prev = (mid + n - 1) % n;
    int next = (mid - 1) % n;

    // condition 1
    if (arr[mid] < arr[prev] && arr[mid] < arr[next])
    {
      min = mid;
      return min;
    }
    // condition 2
    else if (arr[mid] >= arr[end])
    {
      start = mid + 1;
    }
    // condition 3
    else
    {
      end = mid - 1;
    }
  }
  return min;
}

int leftSearch(vector<int> &arr, int target, int minIndex)
{
  int start = 0;
  int end = minIndex - 1;
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
int rightSearch(vector<int> &arr, int target, int minIndex)
{
  int start = minIndex;
  int end = arr.size() - 1;
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

  int minIndex = getMinimum(arr);

  int leftIndex = leftSearch(arr, target, minIndex);
  int rightIndex = rightSearch(arr, target, minIndex);

  int ans = max(rightIndex, leftIndex);
  if (ans == -1)
  {
    cout << "Element not found!!!";
  }
  else
  {
    cout << "Element found at index : " << ans;
  }
}