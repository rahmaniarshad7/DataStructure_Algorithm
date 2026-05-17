#include <bits/stdc++.h>
using namespace std;

void sortArray(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    int min = i;
    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[min])
      {
        min = j;
      }
    }
    swap(arr[i], arr[min]);
  }
  cout << endl;
  cout << "After Sorting" << endl;
  for (int k = 0; k < size; k++)
  {
    cout << arr[k] << " ";
  }
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
  cout << "Before Sorting" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  sortArray(arr, size);
}