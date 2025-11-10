// https://codeforces.com/contest/229/problem/B

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
#define srt(v) sort(v.begin(), v.end())         // sort
#define mxe(v) *max_element(v.begin(), v.end()) // find max element in vector
#define mne(v) *min_element(v.begin(), v.end()) // find min element in vector
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed
#define bin(x, y) bitset<y>(x)
using namespace std;
int MOD = 1e9 + 7; // Hardcoded, directly change from here for functions!

void modadd(int &a, int b) { a = ((a % MOD) + (b % MOD)) % MOD; }
void modsub(int &a, int b) { a = ((a % MOD) - (b % MOD) + MOD) % MOD; }
void modmul(int &a, int b) { a = ((a % MOD) * (b % MOD)) % MOD; }
// ================================== take ip/op like vector,pairs directly!==================================
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
// ===================================END Of the input module ==========================================
const int INF = (int)4e18;

void solve()
{
    int n, m;
    if (!(cin >> n >> m))
        return;

    vector<vector<pair<int, int>>> g(n + 1);

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    vector<vector<int>> cant(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        cant[i].resize(k);
        for (int j = 0; j < k; j++)
            cin >> cant[i][j];
    }

    // lets use dijkstra s to calculate the minimum imnmne in a nudirected graoh with ecxtra checks on the cant go times

    vector<int> dist(n + 1, INF);
    using state = pair<int, int>;

    priority_queue<state, vector<state>, greater<state>> pq;

    dist[1] = 0;
    pq.push({0, 1}); // {dist, src}

    while (!pq.empty())
    {
        auto [t, u] = pq.top();
        pq.pop();

        if (t != dist[u])
            continue;

        int depart = t;
        auto &vec = cant[u];

        if (!vec.empty())
        {
            // find first forbidden time >= depart
            auto it = lower_bound(vec.begin(), vec.end(), (int)depart);
            while(it != vec.end() and *it == depart) {
                ++depart;
                ++it;
            }
        }

        // re;ax edges now
        for(auto e: g[u]) {
            int v = e.first;
            int w = e.second;
            int time = depart + w;
            if(time < dist[v]) {
                dist[v]  = time;
                pq.push({time, v});
            }
        }
    }

    if(dist[n] == INF) cout << -1 << "\n";
    else cout << dist[n] << "\n";

    return;
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
