// https://codeforces.com/contest/1095/problem/F

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int minNode = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] < a[minNode]) minNode = i;
    }

    vector<array<long long, 3>> edges;
    for (int i = 1; i <= n; i++) {
        if (i == minNode) continue;
        edges.push_back({a[minNode] + a[i], minNode, i});
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        edges.push_back({w, x, y});
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long totalCost = 0;

    for (auto &e : edges) {
        long long w = e[0];
        int u = e[1], v = e[2];
        if (dsu.unite(u, v)) totalCost += w;
    }

    cout << totalCost << "\n";
    return 0;
}
