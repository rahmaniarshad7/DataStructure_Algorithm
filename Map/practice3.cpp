#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    unordered_map<int, int> mp;

    // Product ID and Price insert
    for(int i = 0; i < n; i++) {
        int id, price;
        cin >> id >> price;

        mp[id] = price;
    }

    // Number of queries
    int q;
    cin >> q;

    // Fetch price for each product ID
    for(int i = 0; i < q; i++) {
        int id;
        cin >> id;

        cout << mp[id] << endl;
    }

    return 0;
}