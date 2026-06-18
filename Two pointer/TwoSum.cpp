#include <bits/stdc++.h>
using namespace std;

pair<int, int> getSum(vector<int> &arr, int target)
{
  pair<int, int> p;
  int start = 0;
  int end = arr.size() - 1;
  while (start < end)
  {
    if (arr[start] + arr[end] == target)
    {
      p.first = arr[start];
      p.second = arr[end];
      return p;
    }
    else if (arr[start] + arr[end] > target)
    {
      end--;
    }
    else
    {
      start++;
    }
  }
  return p;
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
  cout << "Enter target Sum : " << endl;
  cin >> target;

  pair<int, int> p = getSum(arr, target);
  cout << p.first << endl;
  cout << p.second << endl;
}