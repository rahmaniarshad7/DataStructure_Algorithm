#include <bits/stdc++.h>
using namespace std;

int countRotation(vector<int> &arr)
{
  int n = arr.size();
  int start = 0;
  int end = n - 1;

  if (arr[start] <= arr[end])
  {
    return 0;
  }
  while (start <= end)
  {

    int mid = start + (end - start) / 2;
    int prev = (mid + n - 1) % n;
    int next = (mid + 1) % n;

    if (arr[mid] < arr[prev] && arr[mid] < arr[next])
    {
      return mid;
    }
    else if (arr[mid] >= arr[end])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  return 0;
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
  int rotation = countRotation(arr);
  cout << "Number of Rotation : " << rotation;
}