#include <bits/stdc++.h>
using namespace std;

vector<int> getMaximum(vector<int> &arr, int k)
{

    vector<int> ans;

    int start = 0;
    int end = 0;

    while (end < arr.size())
    {

        // Window size < k
        if ((end - start + 1) < k)
        {
            end++;
        }

        // Window size == k
        else if ((end - start + 1) == k)
        {

            int maxi = INT_MIN;

            // Find maximum in current window
            for (int i = start; i <= end; i++)
            {
                maxi = max(maxi, arr[i]);
            }

            ans.push_back(maxi);

            // Slide the window
            start++;
            end++;
        }
    }

    return ans;
}

int main()
{

    int size;
    cin >> size;

    vector<int> arr(size);

    // Read array
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    // Get maximum of every window
    vector<int> ans = getMaximum(arr, k);

    // Print answer
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}