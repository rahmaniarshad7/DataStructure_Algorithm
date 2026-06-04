#include <bits/stdc++.h>
using namespace std;

int getMinimum(vector<int> &arr)
{
  int n = arr.size();
  int start = 0;
  int end = n - 1;
  int min = 0;
  if (arr[start] <= arr[end])
  {
    min = arr[0];
    return min;
  }

  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    int prev = (mid + n - 1) % n;
    int next = (mid + 1) % n;

    // condition 1
    if (arr[mid] < arr[prev] && arr[mid] < arr[next])
    {
      min = arr[mid];
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
}

int main()
{

  int size;
  cout << "Enter Size : " << endl;
  cin >> size;

  vector<int> arr(size);
  cout << "Enter Element : ";
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }

  int min = getMinimum(arr);
  cout << "Minimum Element : " << min;
}