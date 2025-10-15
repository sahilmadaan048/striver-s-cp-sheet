// https://codeforces.com/problemset/problem/507/A
#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> songs(n); // {difficulty, index}

    for (int i = 0; i < n; i++)
    {
        cin >> songs[i].first;
        songs[i].second = i + 1;
    }

    sort(songs.begin(), songs.end());

    vector<int> chosen;
    int total = 0;

    for (auto [diff, idx] : songs)
    {
        if (total + diff <= k)
        {
            total += diff;
            chosen.push_back(idx);
        }
        else
            break;
    }

    cout << (int)chosen.size() << "\n";
    for (int i = 0; i < (int)chosen.size(); i++)
        cout << chosen[i] << " ";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
