// https://codeforces.com/problemset/problem/1237/A

#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    vector<int> b(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int total = 0;
    int rest = 0;

    bool flip = false; // helps alternate between floor/ceil for odd numbers
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            b[i] = a[i] / 2;
        }
        else
        {
            if (flip)
                b[i] = (a[i] - 1) / 2; // floor
            else
                b[i] = (a[i] + 1) / 2; // ceil
            flip = !flip;
        }
    }
    
    for (auto ele : b)
        cout << ele << "\n";

    return;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
