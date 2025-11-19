// https://codeforces.com/contest/670/problem/C

#include <iostream>
#include <map>
using namespace std;
const int MN = 2e5 + 100;
map<int, int> mp;
int b[MN];
int c[MN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int q;
        cin >> q;
        mp[q]++;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> c[i];
    }
    pair<pair<int, int>, int> best = {{-1, -1}, 0};
    for (int i = 0; i < m; ++i)
    {
        best = max(best, {{mp[b[i]], mp[c[i]]}, i});
    }
    cout << best.second + 1 << '\n';
}
