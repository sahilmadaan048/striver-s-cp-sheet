// https://codeforces.com/problemset/problem/1027/A

#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n; cin >> n ;
    string s; cin >> s;

    bool flag = true;
    int i = 0;
    int j = n-1;

    while(i < j) {
        if(s[i] == s[j] || abs(s[i] - s[j]) == 2) {
            i++;
            j--;
        } else {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return;
}

int32_t main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    