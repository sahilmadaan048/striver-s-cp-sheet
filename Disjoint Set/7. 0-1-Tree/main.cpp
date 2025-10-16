// https://codeforces.com/contest/1156/problem/D

#include "bits/stdc++.h"
using namespace std;
#define int long long

const int MAXN = 2e5 + 5;
vector<pair<int, int>> adj[MAXN];
vector<int> vis;

int dfs(int u, int color) {
    vis[u] = 1;
    int size = 1;
    for (auto [v, w] : adj[u]) {
        if (!vis[v] && w == color)
            size += dfs(v, color);
    }
    return size;
}

void solve() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vis.assign(n, 0);
    int ans = 0;

    // Count components for color 0
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int size = dfs(i, 0);
            ans += size * (size - 1);
        }
    }

    vis.assign(n, 0);
    // for 1
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int size = dfs(i, 1);
            ans += size * (size - 1);
        }
    }

    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

// the path between u and v contains only edges of the same color (either all 0 or all 1).