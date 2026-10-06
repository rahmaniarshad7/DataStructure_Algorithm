#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  unordered_map<int, string> mp;

  for (int i = 0; i < n; i++)
  {
    int id;
    cin >> id;
    string name;
    cin >> name;
    mp[id] = name;
  }

  for (auto p : mp)
  {
    cout << p.first << " ---> " << p.second << endl;
  }

  return 0;
}