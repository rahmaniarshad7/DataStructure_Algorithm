#include <iostream>
using namespace std;

string getReverse(string str)
{
  string ans = str;
  int start = 0;
  int end = str.length() - 1;
  while (start < end)
  {
    swap(ans[start], ans[end]);
    start++;
    end--;
  }
  return ans;
}

int main()
{
  string str;
  cout << "Enter String to Reverse : " << endl;
  cin >> str;

  string rev = getReverse(str);
  cout << rev;
}