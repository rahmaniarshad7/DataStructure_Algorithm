#include <bits/stdc++.h>
using namespace std;

int getMinSum(vector<int> &arr)
{
  int sum = 0;
  int minSum = arr[0];
  for (int i = 0; i < arr.size(); i++)
  {
    sum += arr[i];
    minSum = min(sum, minSum);
    if (sum > 0)
    {
      sum = 0;
    }
  }
  return minSum;
}

int main()
{
  int size;
  cin >> size;

  vector<int> arr(size);
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  int ans = getMinSum(arr);
  cout << "Min Sum : " << ans;
  return 0;
}
