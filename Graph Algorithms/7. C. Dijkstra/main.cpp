// https://codeforces.com/contest/20/problem/C

// https://codeforces.com/contest/20/problem/C

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
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())))
#define bin(x, y) bitset<y>(x)
using namespace std;
int MOD = 1e9 + 7;

void modadd(int &a, int b) { a = ((a % MOD) + (b % MOD)) % MOD; }
void modsub(int &a, int b) { a = ((a % MOD) - (b % MOD) + MOD) % MOD; }
void modmul(int &a, int b) { a = ((a % MOD) * (b % MOD)) % MOD; }

template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}

int n, m;
unordered_map<int, vector<pair<int, int>>> mpp;
int pa[100005];

void Path(int u)
{
    if (u == 1)
    {
        cout << 1 << " ";
        return;
    }
    Path(pa[u]);
    cout << u << " ";
}

void solve()
{
    cin >> n >> m;

    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        mpp[u].push_back({v, w});
        mpp[v].push_back({u, w});
    }

    const int INF = 1e18;
    vector<int> dist(n + 1, INF);
    dist[1] = 0;

    using state = pair<int, int>; // (distance, node)
    priority_queue<state, vector<state>, greater<state>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [d, node] = pq.top();
        pq.pop();

        if (d != dist[node])
            continue;

        for (auto [v, w] : mpp[node])
        {
            if (dist[v] > dist[node] + w)
            {
                dist[v] = dist[node] + w;
                pa[v] = node;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INF)
    {
        cout << -1;
        return;
    }

    Path(n);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
