// https://codeforces.com/contest/986/problem/A


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<int> goods(n);
    for (int i = 0; i < n; i++) cin >> goods[i], goods[i]--;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const int INF = 1e9;
    vector<vector<int>> dist(k, vector<int>(n, INF));

    for (int type = 0; type < k; ++type) {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (goods[i] == type) {
                dist[type][i] = 0;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (dist[type][v] > dist[type][u] + 1) {
                    dist[type][v] = dist[type][u] + 1;
                    q.push(v);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        vector<int> d;
        for (int type = 0; type < k; ++type)
            d.push_back(dist[type][i]);
        sort(d.begin(), d.end());
        long long ans = 0;
        for (int j = 0; j < s; ++j) ans += d[j];
        cout << ans << " ";
    }
    cout << "\n";
}
