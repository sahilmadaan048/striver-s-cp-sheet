#include <bits/stdc++.h>
using namespace std;

const int N = 20;

map<long long, int> v[N][N];

int n, m;
long long k;
long long a[N][N];
long long ans = 0;
int half;

void dfsLeft(int x, int y, long long xorValue, int steps) {
    xorValue ^= a[x][y]; 

    if (steps == half) {
        v[x][y][xorValue]++; 
        return;
    }

    if (x + 1 < n) dfsLeft(x + 1, y, xorValue, steps + 1);
    if (y + 1 < m) dfsLeft(x, y + 1, xorValue, steps + 1);
}

void dfsRight(int x, int y, long long xorValue, int steps) {
    if (steps == n + m - 2 - half) {
        if (v[x][y].count(k ^ xorValue))
            ans += v[x][y][k ^ xorValue];
        return;
    }

    if (x > 0) dfsRight(x - 1, y, xorValue ^ a[x][y], steps + 1);
    if (y > 0) dfsRight(x, y - 1, xorValue ^ a[x][y], steps + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    half = (n + m - 2) / 2;

    dfsLeft(0, 0, 0, 0);

    dfsRight(n - 1, m - 1, 0, 0);

    cout << ans << "\n";
    return 0;
}
