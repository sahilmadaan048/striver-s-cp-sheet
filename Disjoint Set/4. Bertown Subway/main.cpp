// https://codeforces.com/contest/884/problem/C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5; // <= 1e5 in problem, safe buffer
int parent[N];
int sz[N];

// dsu with path compressipn
int find_set(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_set(parent[x]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        union_set(i, p[i]);
    }

    vector<ll> cycle_sizes;
    for (int i = 1; i <= n; i++) {
        if (find_set(i) == i) // i is root
            cycle_sizes.push_back(sz[i]);
    }

    ll ans = 0;
    for (ll s : cycle_sizes) ans += s * s;

    sort(cycle_sizes.rbegin(), cycle_sizes.rend());
    if (cycle_sizes.size() >= 2) {
        ans += 2 * cycle_sizes[0] * cycle_sizes[1];
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve(); // only one test case
    return 0;
}

/*

we have to find the number of pairs x, y such that we start from x and reach y
atmost changes in the p parray allowed = 2 (0, 1, 2)

the maximum value of convenience - need to be calculated

*/