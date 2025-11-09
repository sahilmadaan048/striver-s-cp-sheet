// https://codeforces.com/contest/510/problem/B

#include "bits/stdc++.h"
#define int long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
using namespace std;

int n, m;
vector<string> grid;
vvb vis;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool found = false;

void dfs(int x, int y, int px, int py, char color) {
    vis[x][y] = true;

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (grid[nx][ny] != color) continue;

        if (vis[nx][ny]) {
            if (!(nx == px && ny == py)) {
                found = true;
                return;
            }
        } else {
            dfs(nx, ny, x, y, color);
            if (found) return;
        }
    }
}

void solve() {
    cin >> n >> m;
    grid.resize(n);
    fr(i, n) cin >> grid[i];
    vis.assign(n, vb(m, false));

    fr(i, n) {
        fr(j, m) {
            if (!vis[i][j]) {
                dfs(i, j, -1, -1, grid[i][j]);
                if (found) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
    cout << "No\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    while (T--) solve();
    return 0;
}
