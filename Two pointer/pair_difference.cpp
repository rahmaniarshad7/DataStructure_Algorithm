#include <bits/stdc++.h>
using namespace std;

pair<int, int> getPair(vector<int> &arr, int target)
{
  int start = 0;
  int end = start + 1;
  pair<int, int> a;
  while (end < arr.size())
  {
    if (arr[end] - arr[start] == target)
    {
      a.first = arr[start];
      a.second = arr[end];
      return a;
    }
    else if (arr[end] - arr[start] < target)
    {
      end++;
    }
    else
      start++;
  }
}

int main()
{
  int size;
  cout << "Enter Size: " << endl;
  cin >> size;

  vector<int> arr(size);
  cout << "Enter element : " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }

  int target;
  cout << "Enter target : " << endl;
  cin >> target;

  pair<int, int> p = getPair(arr, target);
  cout << p.first << " " << p.second;
}