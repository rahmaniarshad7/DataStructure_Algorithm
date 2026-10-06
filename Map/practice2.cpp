#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  unordered_map<int, int> mp;

  for (int i = 0; i < n; i++)
  {
    int id, mark;
    cin >> id >> mark;

    mp[id] = mark;
  }
  int a;
  cout << "Enter Id to fetch data : " << endl;
  cin >> a;

  cout << mp[a] << endl;
  return 0;
}