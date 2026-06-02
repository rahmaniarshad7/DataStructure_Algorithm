#include <bits/stdc++.h>
using namespace std;

int findSquareRoot(long long int x)
{
  long long int start = 1;
  long long int end = x;
  long long int ans = 0;

  while (start <= end)
  {
    long long int mid = start + (end - start) / 2;
    // condition 1
    if (mid * mid == x)
    {
      return mid;
    }
    // condition 2
    else if (mid * mid < x)
    {
      ans = mid;
      start = mid + 1;
    }
    // condition 3
    else
    {
      end = mid - 1;
    }
  }
  return ans;
}

int main()
{
  long long int x;
  cout << "Enter Number : " << endl;
  cin >> x;

  int ans = findSquareRoot(x);
  cout << ans;
}