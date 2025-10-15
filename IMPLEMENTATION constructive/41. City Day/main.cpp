// https://codeforces.com/problemset/problem/1199/A

#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n);

    for(int i=0; i<n; i++) cin >> a[i];

    // for x days before i and y days after y a[i] shoulebe the least
    // so we jystt need to find the smallest 

    for(int i=0; i<n; i++) {
        bool good = true;

        for(int  j=max(0, i-x); j<i; j++) {
            if(a[j] <= a[i]) {
                good = false;
                break;
            }
        }

        for(int j=i+1; j<=min(i+y, n-1); j++) {
            if(a[j] <= a[i]) {
                good = false;
                break;
            }
        }

        if(good) {
            cout << i + 1 << "\n";
            return;
        }
    }
    return;
}

int32_t main()
{
 
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    