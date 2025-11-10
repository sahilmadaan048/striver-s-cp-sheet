// https://codeforces.com/contest/1345/problem/D

#include "bits/stdc++.h"
#define int long long
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
using namespace std;

int n, m;
vector<string> grid;
vector<vector<int>> vis;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
            !vis[nx][ny] && grid[nx][ny] == '#')
        {
            dfs(nx, ny);
        }
    }
}

void solve()
{
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    vector<int> row_has_black(n, 0), col_has_black(m, 0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '#')
                row_has_black[i] = col_has_black[j] = 1;

    int empty_rows = count(all(row_has_black), 0);
    int empty_cols = count(all(col_has_black), 0);

    if ((empty_rows > 0 && empty_cols == 0) || (empty_cols > 0 && empty_rows == 0))
    {
        cout << -1 << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        int segments = 0;
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '#')
            {
                if (j == 0 || grid[i][j - 1] == '.')
                    segments++;
            }
        }
        if (segments > 1)
        {
            cout << -1 << "\n";
            return;
        }
    }

    for (int j = 0; j < m; j++)
    {
        int segments = 0;
        for (int i = 0; i < n; i++)
        {
            if (grid[i][j] == '#')
            {
                if (i == 0 || grid[i - 1][j] == '.')
                    segments++;
            }
        }
        if (segments > 1)
        {
            cout << -1 << "\n";
            return;
        }
    }

    vis.assign(n, vector<int>(m, 0));
    int components = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '#' && !vis[i][j])
            {
                components++;
                dfs(i, j);
            }
        }
    }

    cout << components << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while (T--)
        solve();

    return 0;
}
