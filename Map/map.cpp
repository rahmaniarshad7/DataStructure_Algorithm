#include <bits/stdc++.h>
using namespace std;
int main()
{
  map<int, string> mp;
  mp[5] = "Arshad Rahmani";
  mp[2] = "Aiman fatma";
  mp[8] = "Alisa";
  mp[1] = "Altamash Rahmani";

  for (auto it = mp.begin(); it != mp.end(); it++)
  {
    cout << it->first << "  --->  " << it->second << endl;
  }
}