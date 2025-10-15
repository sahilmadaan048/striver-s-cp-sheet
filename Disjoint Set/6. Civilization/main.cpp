// https://codeforces.com/contest/455/problem/C

#include "bits/stdc++.h"
using namespace std;

class DSU
{
public:
    vector<int> parent, size;
    DSU(int n)
    {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n + 1, 1);
    }
    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b)
            return false;
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

int bfs_far(int src, const vector<vector<int>> &adj, int &farthest)
{
    queue<int> q;
    vector<int> dist(adj.size(), -1);
    q.push(src);
    dist[src] = 0;
    farthest = src;
    int maxd = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > maxd)
                {
                    maxd = dist[v];
                    farthest = v;
                }
            }
        }
    }
    return maxd;
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    int a, b;

    vector<vector<int>> adj(n + 1); // graph

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DSU dsu(n);
    vector<int> diam(n + 1, 0);

    // find connected components and their diameters
    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vector <int> comp;
            queue<int> q;
            q.push(i);
            vis[i] = true;

            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                comp.push_back(u);
                for (auto v : adj[u])
                {
                    if (!vis[v])
                    {
                        vis[v] = true;
                        dsu.unite(i, v);
                        q.push(v);
                    }
                }
            }

            int farthest, d1, d2;
            d1 = bfs_far(i, adj, farthest);
            d2 = bfs_far(farthest, adj, farthest);
            diam[dsu.find(i)] = d2;
        }
    }

    while (q--)
    {
        int num;
        cin >> num;
        if (num == 1)
        {
            // fiund the length of the maxiimum path in hte  region that contains cuty x => basically the diamere
            int x;
            cin >> x;
            cout << diam[dsu.find(x)] << "\n";
        }
        else
        {
            // merge the two rehions one contsining x and the other containg y
            int x, y;
            cin >> x >> y;
            x = dsu.find(x);
            y = dsu.find(y);
            if (x == y)
                continue;
            int d1 = diam[x], d2 = diam[y];
            int new_d = max(d1, max(d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1));
            dsu.unite(x, y);
            diam[dsu.find(x)] = new_d;
        }
    }

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


// it gave tle