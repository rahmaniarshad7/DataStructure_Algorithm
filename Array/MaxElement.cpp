#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int findMaxElement(int arr[], int size)
{
  int maxi = INT_MIN;
  for (int i = 0; i < size; i++)
  {
    maxi = max(arr[i], maxi);
  }
  return maxi;
}

int main()
{
  int size;
  cin >> size;

  int arr[size];
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }

  int max = findMaxElement(arr, size);
  cout << "Max Value : " << max;
}