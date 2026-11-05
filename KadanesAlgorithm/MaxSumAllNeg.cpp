#include <bits/stdc++.h>
using namespace std;

int getMaxSum(vector<int> &arr)
{
  int sum = arr[0];
  int maxSum = arr[0];
  for (int i = 0; i < arr.size(); i++)
  {
    sum = sum + arr[i];
    maxSum = max(maxSum, sum);
  }
  return maxSum;
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

  int ans = getMaxSum(arr);
  cout << "Max Sum : " << ans;
}