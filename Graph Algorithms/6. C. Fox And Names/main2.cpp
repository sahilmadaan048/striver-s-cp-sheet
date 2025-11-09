// https://codeforces.com/contest/510/problem/C

#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define fr(i, n) for (int i = 0; i < (n); i++)
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define nl cout << "\n"
#define dbg(var) cout << #var << "=" << var << " "
#define all(v) v.begin(), v.end()
#define sz(v) (int)(v.size())
#define srt(v) sort(v.begin(), v.end())
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())));
#define bin(x, y) bitset<y>(x)
using namespace std;
int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<string> temp(n);
    fr(i, n) cin >> temp[i];

    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);
    vector<bool> present(26, false);

    for (auto &s : temp)
        for (char c : s)
            present[c - 'a'] = true;

    for (int i = 1; i < n; i++)
    {
        string &a = temp[i - 1];
        string &b = temp[i];
        int len = min(sz(a), sz(b));
        bool found = false;
        for (int j = 0; j < len; j++)
        {
            if (a[j] != b[j])
            {
                int u = a[j] - 'a';
                int v = b[j] - 'a';
                if (find(all(adj[u]), v) == adj[u].end())
                {
                    adj[u].push_back(v);
                    indegree[v]++;
                }
                found = true;
                break;
            }
        }
        if (!found && sz(a) > sz(b))
        {
            cout << "Impossible\n";
            return;
        }
    }

    queue<int> q;
    fr(i, 26) if (indegree[i] == 0 && present[i]) q.push(i);

    string ans = "";
    int visited = 0;
    while (!q.empty())
    {
        char ch = q.front() + 'a';
        q.pop();
        ans += ch;
        visited++;
        for (auto v : adj[ch - 'a'])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }
    int totalPresent = 0;
    fr(i, 26) if (present[i]) totalPresent++;
    if (visited != totalPresent)
    {
        cout << "Impossible\n";
        return;
    }

    fr(i, 26)
    {
        char ch = 'a' + i;
        if (!present[i])
            ans += ch;
    }

    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    while (T--)
        solve();
    return 0;
}
