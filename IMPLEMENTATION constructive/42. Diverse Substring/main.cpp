// // https://codeforces.com/problemset/problem/1073/A

#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> fq(n, vector<int>(26, 0));

    fq[0][s[0] - 'a'] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int c = 0; c < 26; c++)
            fq[i][c] = fq[i - 1][c];
        fq[i][s[i] - 'a']++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int len = j - i + 1;
            bool diverse = true;
            for (int c = 0; c < 26; c++)
            {
                int count = fq[j][c] - (i > 0 ? fq[i - 1][c] : 0);
                if (count > len / 2)
                {
                    diverse = false;
                    break;
                }
            }
            if (diverse)
            {
                cout << "YES\n";
                cout << s.substr(i, len) << "\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int32_t main()
{

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
